func numJewelsInStones(jewels, stones string) (ans int) {
    // 把 jewels 转换成字符集合 mask
    mask := 0
    for _, c := range jewels {
        mask |= 1 << (c & 63)
    }
    // 统计有多少 stones[i] 在集合 mask 中
    for _, c := range stones {
        ans += mask >> (c & 63) & 1
    }
    return
}