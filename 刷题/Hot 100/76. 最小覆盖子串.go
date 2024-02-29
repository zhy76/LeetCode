func minWindow(s string, t string) string {
    need := make(map[byte]int)
    window := make(map[byte]int)
    left, right := 0, 0
    valid := 0
    start, length := 0, math.MaxInt32
    for i := range t {
        need[t[i]]++
    } 
    for right < len(s) {
        c := byte(s[right])
        right++
        if _, ok := need[c]; ok {
            window[c]++
            if window[c] == need[c] {
                valid++
            }
        }
        for left < right && valid == len(need) {
            if length > right - left {
                start = left
                length = right - left
            }
            d := s[left]
            left++
            if _, ok := need[d]; ok {
                if need[d] == window[d] {
                    valid--
                }
                window[d]--
            }
        }
    }
    if length == math.MaxInt32 {
        return ""
    } else {
        return s[start : start+length]
    }
}