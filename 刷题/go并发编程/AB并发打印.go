// A和B两个协程，B协程等待A协程的ready（条件变量）为true，然后B要做一个process；A等待B的process完成之后打印一个“hello”，并且把ready设为true；
package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	var mutex sync.Mutex
	cond := sync.NewCond(&mutex)
	ready := false

	var wg sync.WaitGroup
	wg.Add(2)

	// A goroutine
	go func() {
		defer wg.Done()

		// 等待B处理完成
		mutex.Lock()
		for !ready {
			cond.Wait()
		}
		mutex.Unlock()

		fmt.Println("hello")
		ready = true // 在实际场景中，可能需要用其他方式通知B或其他协程继续工作
	}()

	// B goroutine
	go func() {
		defer wg.Done()

		// 假设的处理过程
		process()

		mutex.Lock()
		ready = true
		cond.Broadcast() // 通知所有等待的协程条件已经满足
		mutex.Unlock()
	}()

	wg.Wait()
}

func process() {
	// 模拟B的处理过程，包括3秒的延迟
	fmt.Println("B is processing")
	time.Sleep(3 * time.Second) // 添加3秒延迟
	fmt.Println("B finished processing")
}
