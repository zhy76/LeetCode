func isPlindrome(s string, start int, end int) bool {
    for start < end {
        if s[start] != s[end] {
            return false
        }
        start++
        end--
    }
    return true
}

func partition(s string) [][]string {
    ans:=[][]string{}
    path:=[]string{}
    n:=len(s)
    var dfs func(int)
    dfs = func(i int) {
        if i == n {
            ans = append(ans, append([]string(nil), path...))
            return
        }
        for j:=i; j<n; j++ {
            if isPlindrome(s, i, j) {
                path = append(path, s[i:j+1])
                dfs(j+1)
                path = path[:len(path)-1]
            }
        }
    }
    dfs(0)
    return ans
}