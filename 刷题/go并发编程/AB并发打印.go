package main

// A和B两个线程，B线程等待A线程的ready（条件变量）为true，然后B要做一个process；A等待B的process完成之后打印一个“hello”，并且把ready设为true；
import (
	"fmt"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	ready := make(chan bool)
	done := make(chan bool)
	wg.Add(1)
	go func() {
		defer wg.Done()
		<-ready
		fmt.Println("Hello A")
		done <- true
	}()
	wg.Add(1)
	go func() {
		defer wg.Done()
		fmt.Println("Hello B")
		ready <- true
		<-done
	}()
	wg.Wait()
}