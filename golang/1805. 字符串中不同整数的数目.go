func numDifferentIntegers(word string) int {
    s := map[string]bool{}
    n := len(word)
    p1 := 0
    for {
        for p1 < n && !unicode.IsDigit(rune(word[p1])) {
            p1++
        }
        if p1 == n {
            break
        }
        p2 := p1
        for p2 < n && unicode.IsDigit(rune(word[p2])) {
            p2++
        }
        for p2-p1 > 1 && word[p1] == '0' { // 去除前导 0
            p1++
        }
        s[word[p1:p2]] = true
        p1 = p2
    }
    return len(s)
}