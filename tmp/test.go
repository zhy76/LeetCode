package main

import(
	"fmt"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	ch := make(chan struct{})

	wg.Add(2)
	go func() {
		defer wg.Done()
		for i := 1; i <= 100; i+=2 {
			fmt.Println(i)
			ch <- struct{}{} // 阻塞
			if(i < 99) {
				<-ch
			}
		}
	}()
	
	go func() {
		defer wg.Done()
		for i := 2; i <= 100; i+=2 {
			<-ch
			fmt.Println(i)
			if i < 100 {
				ch <- struct{}{} 
			}
		}
	}()

	wg.Wait()
	close(ch)

}