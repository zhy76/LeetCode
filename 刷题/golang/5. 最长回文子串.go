func longestPalindrome(s string) string {
    n := len(s)
    maxL := 1
    if n < 2 {
        return s
    }
    dp := make([][]bool, n)
    for i := range dp {
        dp[i] = make([]bool, n)
    }
    for i := 0; i<n; i++ {
        dp[i][i] = true
    }
    begin := 0
    for l := 2; l <= n; l++ {
        for i := 0; i < n; i++ {
            j := i+l-1
            if j >= n {
                break
            } 
            if s[i] != s[j] {
                dp[i][j] = false
            } else {
                if l < 3 {
                    dp[i][i+1] = true
                } else {
                    dp[i][j] = dp[i+1][j-1]
                }
            }
            if dp[i][j] && l > maxL {
                maxL = l
                begin = i
            }
        }
    }
    return s[begin:begin+maxL]
}