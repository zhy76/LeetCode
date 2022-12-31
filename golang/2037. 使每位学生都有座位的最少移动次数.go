func minMovesToSeat(seats []int, students []int) int {
    sort.Ints(seats)
    sort.Ints(students)
    ans:=0 
    for i,x:=range(seats){
        ans+=abs(x-students[i])
    }
    return ans
}
func abs(a int) int{
    if a<0 {
        return -a
    }
    return a
}