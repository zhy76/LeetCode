func checkPalindrome(a string, left int, right int) bool {
    for left<right {
        if a[left] != a[right] {
            return false
        }
        left++
        right--
    }
    return true
}
func chekcAB(a, b string) bool {
    left, right := 0, len(a)-1
    for left < right && a[left] == b[right] {
        left++
        right--
    }
    if left >= right {
        return true
    } 
    return checkPalindrome(a, left, right) || checkPalindrome(b, left, right)
}
func checkPalindromeFormation(a string, b string) bool {
    return chekcAB(a, b) || chekcAB(b, a)
}