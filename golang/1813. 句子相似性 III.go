func areSentencesSimilar(sentence1 string, sentence2 string) bool {
    words1:=strings.Split(sentence1," ")
    words2:=strings.Split(sentence2," ")
    i,n:=0,len(words1)
    j,m:=0,len(words2)
    for i<n&&i<m&&words1[i]==words2[i]{
        i++
    }
    for j<n-i&&j<m-i&&words1[n-j-1]==words2[m-j-1]{
        j++
    }
    return i+j==min(n,m)
}
func min(x,y int) int{
    if x<y {
        return x
    }
    return y
}