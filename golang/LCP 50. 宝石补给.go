func giveGem(gem []int, operations [][]int) int {
    for _, operation := range operations {
        x, y := operation[0], operation[1]
        number:=gem[x]/2
        gem[y]+=number
        gem[x]-=number
    }
    mn, mx := gem[0], gem[0]
    for _, number := range gem {
        mn = min(number, mn)
        mx = max(number, mx)
    }
    return mx - mn
}

func max(x int, y int) int {
    if x < y {
        return y
    }
    return x
}

func min(x int, y int) int {
    if x > y {
        return y
    }
    return x
}
