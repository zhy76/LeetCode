// 使用两个 goroutine 交替打印奇数和偶数，顺序输出 1~100 

package main

import (
  "fmt"
  "sync"
)

func main() {
  ch := make(chan struct{})
  wg := sync.WaitGroup{}
  wg.Add(2)

  go func() {
    defer wg.Done()
    for i := 1; i <= 99; i += 2 {
      fmt.Println(i)
      ch <- struct{}{}
      if i < 99 {
        <-ch
      }
    }
  }()

  go func() {
    defer wg.Done()
    for i := 2; i <= 100; i += 2 {
      <-ch
      fmt.Println(i)
      if i < 100 {
        ch <- struct{}{}
      }
    }
  }()

  wg.Wait()
  close(ch) // 移动到这里来关闭通道
}


// package main

// import (
//   "fmt"
//   "sync"
// )

// func main() {
//   ch := make(chan struct{}, 1) // 使用缓冲通道，避免初始阻塞
//   wg := sync.WaitGroup{}
//   wg.Add(2)

//   go func() {
//     defer wg.Done()
//     for i := 1; i <= 99; i += 2 {
//       fmt.Println(i)
//       ch <- struct{}{} // 发送信号
//       <-ch             // 等待接收信号
//     }
//   }()

//   go func() {
//     defer wg.Done()
//     for i := 2; i <= 100; i += 2 {
//       <-ch            // 接收信号
//       fmt.Println(i)
//       if i < 100 {
//         ch <- struct{}{} // 发送信号
//       }
//     }
//   }()

//   ch <- struct{}{} // 开始第一个goroutine的打印操作
//   wg.Wait()
//   close(ch) // 在这里关闭通道是安全的
// }
