func maximumSum(nums []int) int {
    ans := -1
    mx := [82]int{} // 至多 9 个 9 相加
    for _, num := range nums {
        s := 0 // num 的数位和
        for x := num; x > 0; x /= 10 { // 枚举 num 的每个数位
            s += x % 10
        }
        if mx[s] > 0 { // 说明左边也有数位和等于 s 的元素
            ans = max(ans, mx[s]+num) // 更新答案的最大值
        }
        mx[s] = max(mx[s], num) // 维护数位和等于 s 的最大元素
    }
    return ans
}
