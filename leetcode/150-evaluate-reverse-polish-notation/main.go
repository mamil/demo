package main
import (
	"fmt"
	"strconv"
)
func evalRPN(tokens []string) int {
	if len(tokens) == 0{
		return 0
	}

	res := []int{}
	for _,v :=range tokens{
		switch v{
		case "+","-","*","/":
			b := res[len(res)-1]
			a := res[len(res)-2]
			res = res[:len(res)-2]
			switch v{
			case "+":
				res = append(res, a+b)
			case "-":
				res = append(res, a-b)
			case "*":
				res = append(res, a*b)
			case "/":
				res = append(res, a/b)
			}
		default:
			val,_ := strconv.Atoi(v)
			res = append(res, val)
		}
	}
	return res[0]
}

func main()  {
	token := []string{"3", "1", "+", "5", "*"}
	fmt.Println( evalRPN(token))
}