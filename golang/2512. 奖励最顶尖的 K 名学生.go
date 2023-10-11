func topStudents(positive_feedback []string, negative_feedback []string, report []string, student_id []int, k int) []int {
    words := map[string]int{}
    for _, word := range positive_feedback{
        words[word]=3
    }
    for _, word := range negative_feedback {
        words[word]=-1
    }
    type pair struct { score, id int}
    var score_stuid []pair
    for i, rep := range report {
        score := 0
        for _, w := range strings.Split(rep, " ") {
            score += words[w]
        }
        score_stuid=append(score_stuid, pair{score, student_id[i]})
    }
    sort.Slice(score_stuid, func(i, j int) bool {
        a, b := score_stuid[i], score_stuid[j]
        return a.score > b.score || a.score == b.score && a.id<b.id
    })
    top_k:=make([]int,k)
    for i, p:=range score_stuid[:k] {
        top_k[i]=p.id
    }
    return top_k
}