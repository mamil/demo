package main
import "fmt"

type MinStack struct {
    min []int
    stack []int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        min: make([]int, 0),
        stack: make([]int, 0),
    }
}


func (this *MinStack) Push(x int)  {
    m := this.GetMin()
    if x < m{
        this.min = append(this.min, x)
    } else{
        this.min = append(this.min, m)
    }
    this.stack = append(this.stack, x)

}


func (this *MinStack) Pop()  {
    if len(this.stack) == 0 {
        return
    }
    this.stack = this.stack[:len(this.stack)-1]
    this.min = this.min[:len(this.min)-1]
}


func (this *MinStack) Top() int {
    if len(this.stack) ==0 {
        return 0
    }
    return this.stack[len(this.stack)-1]
}


func (this *MinStack) GetMin() int {
    if len(this.min) == 0 {
        return 1 << 31
    }
    m := this.min[len(this.min)-1]
    return m
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */

func main(){
	fmt.Println("hello")

	min := Constructor()
	min.Push(-2)
	min.Push(0)
	min.Push(-3)
	fmt.Println(min.GetMin()) // ,-3,null,0,-2]
	min.Pop()
	fmt.Println( min.Top())
	fmt.Println( min.GetMin())
}