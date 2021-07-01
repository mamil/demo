package main


import (
	"fmt"
	"sort"
)



type GatherTrackNodeFeature struct {
	Timestamp           uint64
}

type GatherObjectTrackNode struct {
	TrackStartTime        uint64                    
	TrackEndTime          uint64                                      
	TrackNodeFeatures     []*GatherTrackNodeFeature                    
}

func tryNil(){
	///如果 slice == nil，那么 len、cap 结果都等于 0。
	///但是len、cap都等于0，slice不为nil
	s := make([]int, 0,0)
	if s == nil{
		fmt.Println("slice is nil")
	} else {
		fmt.Println("slice is not nil")
	}
}

func tryCopy(){
	t1 := GatherTrackNodeFeature{
		Timestamp: 111,
	}
	t2 := GatherTrackNodeFeature{
		Timestamp: 222,
	}
	ta := make([]*GatherTrackNodeFeature, 10,10)
	ta = append(ta, &t1)
	ta = append(ta, &t2)

	g1 := GatherObjectTrackNode{
		TrackStartTime: 123,
		TrackEndTime: 456,
		TrackNodeFeatures: ta,
	}
	fmt.Println("g1:", g1)

	g2 := g1

	addressg1:= &g1
	addressg2:= &g2

	// copy(g2,g1)
	fmt.Println("g2:",g2)


	fmt.Printf("address:%p\n", addressg1) // 这样才能打出指针地址
	fmt.Printf("address:%p\n", addressg2)


	fmt.Println("change")

	g1.TrackStartTime = 999
	fmt.Println("g1:", g1)
	fmt.Println("g2:",g2)
}


// 结构体定义
type test struct {
	value int
	str   string
}

func trySort(){
	fmt.Println("###### sort")
	s := make([]test, 5)
	s[0] = test{value: 2, str: "test2"}
	s[1] = test{value: 4, str: "test4"}
	s[2] = test{value: 1, str: "test1"}
	s[3] = test{value: 5, str: "test5"}
	s[4] = test{value: 3, str: "test3"}
	fmt.Println("初始化结果:")
	fmt.Println(s)

	sort.SliceStable(s, func(i, j int) bool {
		if s[i].value < s[j].value {
			return true
		}
		return false
	})

	fmt.Println(s)

}

func main(){
	fmt.Println("start")
	tryCopy()

	tryNil()
	
	trySort()
}