func countSeniors(details []string) int {
    count := 0
    for i := 0; i < len(details); i++ {
        age, _ := strconv.Atoi(details[i][11:13])
        if (age > 60) {
            count++
        }
    }
    return count
}