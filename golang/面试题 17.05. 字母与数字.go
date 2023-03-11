func findLongestSubarray(array []string) []string {
    sum:=0
    mp := map[int]int{}
    maxL := 0
    mp[0] = -1
    k := 0
    for i, s :=range array {
        if s[0] >= '0' && s[0] <= '9' {
            sum++
        } else {
            sum--
        }
        if j, ok := mp[sum]; ok {
            if i-j > maxL {
                maxL = i-j
                k = j+1
            }
        } else {
            mp[sum] = i
        }
    }
    return array[k : k+maxL]
}