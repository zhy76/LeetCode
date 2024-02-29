func addStrings(num1 string, num2 string) string {
	i, j := len(num1)-1, len(num2)-1
	carry := 0
	ans := []byte{}
	for i >= 0 || j >= 0 || carry != 0 {
		a, b := 0, 0
		if i >= 0 {
			a = int(num1[i] - '0')
		}
		if j >= 0 {
			b = int(num2[j] - '0')
		}
		sum := a + b + carry
		ans = append(ans, byte(sum%10+'0'))
		carry = sum / 10
		i--
		j--
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}