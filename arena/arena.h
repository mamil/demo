// from https://github.com/google/leveldb/blob/master/util/arena.h
// Arena 是一种统一化管理内存生命周期的方法。所有需要在堆上分配的内存，不通过 malloc/new，而是通过 Arena 的 CreateObject 接口。同时，不需要手动的执行 free/delete，而是在 Arena 被销毁的时候，统一释放所有通过 Arena 对象申请的内存。所以，只需要确保 Arena 对象一定被销毁就可以了，而不用再关心其他对象是否有漏掉的 free/delete。这样显然降低了内存管理的复杂度。
// 此外，我们还可以将 Arena 的生命周期与 Request 的生命周期绑定，一个 Request 生命周期内的所有内存分配都通过 Arena 完成。这样的好处是，我们可以在构造 Arena 的时候，大概预估出处理完成这个 Request 会消耗多少内存，并提前将会使用到的内存一次性的申请完成，从而减少了在处理一个请求的过程中，分配和回收内存的次数，从而优化了性能。
// 我们最早看到 Arena 的思想，是在 LevelDB 的代码中。这段代码相当简单，建议大家直接阅读。

// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef STORAGE_LEVELDB_UTIL_ARENA_H_
#define STORAGE_LEVELDB_UTIL_ARENA_H_

#include <atomic>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leveldb
{

    class Arena
    {
    public:
        Arena();

        Arena(const Arena &) = delete;
        Arena &operator=(const Arena &) = delete;

        ~Arena();

        // Return a pointer to a newly allocated memory block of "bytes" bytes.
        char *Allocate(size_t bytes);

        // Allocate memory with the normal alignment guarantees provided by malloc.
        char *AllocateAligned(size_t bytes);

        // Returns an estimate of the total memory usage of data allocated
        // by the arena.
        size_t MemoryUsage() const
        {
            return memory_usage_.load(std::memory_order_relaxed);
        }

    private:
        char *AllocateFallback(size_t bytes);
        char *AllocateNewBlock(size_t block_bytes);

        // Allocation state
        char *alloc_ptr_;
        size_t alloc_bytes_remaining_;

        // Array of new[] allocated memory blocks
        std::vector<char *> blocks_;

        // Total memory usage of the arena.
        //
        // TODO(costan): This member is accessed via atomics, but the others are
        //               accessed without any locking. Is this OK?
        std::atomic<size_t> memory_usage_;
    };

    inline char *Arena::Allocate(size_t bytes)
    {
        // The semantics of what to return are a bit messy if we allow
        // 0-byte allocations, so we disallow them here (we don't need
        // them for our internal use).
        assert(bytes > 0);
        if (bytes <= alloc_bytes_remaining_)
        {
            char *result = alloc_ptr_;
            alloc_ptr_ += bytes;
            alloc_bytes_remaining_ -= bytes;
            return result;
        }
        return AllocateFallback(bytes);
    }

} // namespace leveldb

#endif // STORAGE_LEVELDB_UTIL_ARENA_H_