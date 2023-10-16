func singleNumber(nums []int) []int {
    xorsum:=0
    for _, num := range nums {
        xorsum^=num
    }
    lsb:=xorsum & (-xorsum)
    type1, type2:=0, 0
    for _, num := range nums {
        if num & lsb > 0 {
            type1 ^= num
        } else {
            type2 ^= num
        }
    }
    return []int{type1, type2}
}