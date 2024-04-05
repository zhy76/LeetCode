package main

import "fmt"
func main() {
	var a []int
	a = []int{1, 2, 3, 4, 5, 6, 7, 8}
	for i, _ := range a {
		fmt.Println(i)	
	}
}
