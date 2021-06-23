package main

import "fmt"

type ErrorMessage struct {
	index   int
	message string
}

func p1() {
	defer func() {
		if err := recover(); err != nil {
			errorMessage, ok := err.(ErrorMessage)
			if !ok {
				return
			}
			fmt.Println(errorMessage.index)
			fmt.Println(errorMessage.message)
		}
	}()

	panic(ErrorMessage{1, "just error"})

}

func main() {
	p1()
}
