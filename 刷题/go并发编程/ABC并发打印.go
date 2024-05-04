// 3个goroutine交替打印abc
// https://www.cnblogs.com/ssezhangpeng/p/13725315.html
package main

import (
    "fmt"
    "sync"
)

func printChars(wg *sync.WaitGroup, chIn, chOut chan struct{}, char string, count int) {
    defer wg.Done() // Ensure wg.Done() is called even if panic occurs
    for i := 0; i < count; i++ {
        <-chIn // Wait for signal
        fmt.Println(char)
        chOut <- struct{}{} // Signal next goroutine
    }
}

func main() {
    var wg sync.WaitGroup
    chA, chB, chC := make(chan struct{}, 1), make(chan struct{}, 1), make(chan struct{}, 1)
    count := 10 // Number of iterations for each goroutine

    chA <- struct{}{} // Start the chain

    wg.Add(3)
    go printChars(&wg, chA, chB, "A", count)
    go printChars(&wg, chB, chC, "B", count)
    go printChars(&wg, chC, chA, "C", count)

    wg.Wait() // Wait for all goroutines to finish
    fmt.Println("Success.")
}

// package main

// import (
//     "fmt"
//     "sync"
// )

// func PrintA(wg *sync.WaitGroup, chA, chB chan struct{}) {
//     for i := 0; i < 10; i++ {
//         <-chA
//         fmt.Println("A")
//         chB <- struct{}{}
//     }
//     wg.Done()
// }

// func PrintB(wg *sync.WaitGroup, chB, chC chan struct{}) {
//     for i := 0; i < 10; i++ {
//         <-chB
//         fmt.Println("B")
//         chC <- struct{}{}
//     }
//     wg.Done()
// }

// func PrintC(wg *sync.WaitGroup, chC, chA chan struct{}) {
//     for i := 0; i < 10; i++ {
//         <-chC
//         fmt.Println("C")
//         chA <- struct{}{}
//     }
//     wg.Done()
// }

// func main() {
//     wg := sync.WaitGroup{}
//     chA := make(chan struct{}, 1)
//     chB := make(chan struct{}, 1)
//     chC := make(chan struct{}, 1)

//     chA <- struct{}{}

//     wg.Add(1)
//     go PrintA(&wg, chA, chB)

//     wg.Add(1)
//     go PrintB(&wg, chB, chC)

//     wg.Add(1)
//     go PrintC(&wg, chC, chA)

//     wg.Wait()
//     fmt.Println("Success.")
// }