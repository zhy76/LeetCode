func areNumbersAscending(s string) bool {
    pre, i := 0, 0
    for i < len(s) {
        if unicode.IsDigit(rune(s[i])) {
            cur := 0
            for i < len(s) && unicode.IsDigit(rune(s[i])) {
                cur = cur*10 + int(s[i]-'0')
                i++
            }
            if cur <= pre {
                return false
            }
            pre = cur
        } else {
            i++
        }
    }
    return true
}