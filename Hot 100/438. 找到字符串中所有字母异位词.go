func findAnagrams(s, p string) (ans []int) {
    sLen, pLen := len(s), len(p)
    if sLen < pLen {
        return
    }

    count := [26]int{}
    for i, ch := range p {
        count[s[i]-'a']++
        count[ch-'a']--
    }

    differ := 0
    for _, c := range count {
        if c != 0 {
            differ++
        }
    }
    if differ == 0 {
        ans = append(ans, 0)
    }

    for i, ch := range s[:sLen-pLen] {
        if count[ch-'a'] == 1 { // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
            differ--
        } else if count[ch-'a'] == 0 { // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
            differ++
        }
        count[ch-'a']--

        if count[s[i+pLen]-'a'] == -1 { // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
            differ--
        } else if count[s[i+pLen]-'a'] == 0 { // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
            differ++
        }
        count[s[i+pLen]-'a']++

        if differ == 0 {
            ans = append(ans, i+1)
        }
    }
    return
}
