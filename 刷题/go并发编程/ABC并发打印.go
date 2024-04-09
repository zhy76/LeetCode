// 3个goroutine交替打印abc
// https://www.cnblogs.com/ssezhangpeng/p/13725315.html
package main

import (
    "fmt"
    "sync"
)

func PrintA(wg *sync.WaitGroup, chA, chB chan struct{}) {
    for i := 0; i < 10; i++ {
        <-chA
        fmt.Println("A")
        chB <- struct{}{}
    }
    wg.Done()
}

func PrintB(wg *sync.WaitGroup, chB, chC chan struct{}) {
    for i := 0; i < 10; i++ {
        <-chB
        fmt.Println("B")
        chC <- struct{}{}
    }
    wg.Done()
}

func PrintC(wg *sync.WaitGroup, chC, chA chan struct{}) {
    for i := 0; i < 10; i++ {
        <-chC
        fmt.Println("C")
        chA <- struct{}{}
    }
    wg.Done()
}

func main() {
    wg := sync.WaitGroup{}
    chA := make(chan struct{}, 1)
    chB := make(chan struct{}, 1)
    chC := make(chan struct{}, 1)

    chA <- struct{}{}

    wg.Add(1)
    go PrintA(&wg, chA, chB)

    wg.Add(1)
    go PrintB(&wg, chB, chC)

    wg.Add(1)
    go PrintC(&wg, chC, chA)

    wg.Wait()
    fmt.Println("Success.")
}