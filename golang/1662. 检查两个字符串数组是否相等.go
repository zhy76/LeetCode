func arrayStringsAreEqual(word1, word2 []string) bool {
	return strings.Join(word1, "") == strings.Join(word2, "")
}