func vowelStrings(words []string, left int, right int) int {
    vowels := map[byte]struct{}{'a' : {}, 'e' : {}, 'i' : {}, 'o' : {}, 'u' : {}}
    ans := 0
    for _, word := range(words[left : right + 1]) {
        if _, ok1 := vowels[word[0]]; ok1 {
            if _, ok2 := vowels[word[len(word) - 1]]; ok2 {
                ans++
            }
        }
    }
    return ans
}
