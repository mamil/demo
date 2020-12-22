#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::deque<TreeNode*> q; // 存储遍历节点的队列
        std::vector<std::vector<int>> all;
        if (! root) return all;
        all.emplace_back();

        q.push_back(root);
        q.push_back(nullptr); // 加入一层结束标记

        int level = 0;; // 当前层
        while(! q.empty())
        {
            if (q.front() == nullptr) // 一层结束
            {
                if (q.size() != 1) // 没有下一层
                {
                    all.emplace_back();
                    level++;
                    q.push_back(nullptr); // 本层的子节点已经全部加入，加入一层结束标记
                }
                q.pop_front(); // 删除上层标记

                continue;
            }

            if (level % 2 == 0)
            {
                all[level].push_back(q.front()->val);
            }
            else
            {
                all[level].insert(all[level].begin(), q.front()->val);
            }

            if (q.front()->left != nullptr)
            {
                q.push_back(q.front()->left);
            }
            if (q.front()->right != nullptr)
            {
                q.push_back(q.front()->right);
            }
            q.pop_front();
        }
        return all;
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(15);
    TreeNode* node5 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;

    node3->left = node4;
    node3->right = node5;


    Solution s;
    auto res = s.zigzagLevelOrder(node1);

    for (auto it1 : res)
    {
        for (auto it2 : it1)
        {
            std::cout <<it2 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}