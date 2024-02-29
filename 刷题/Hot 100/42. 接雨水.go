func trap(height []int) (ans int) {
    left, right := 0, len(height) - 1
    leftMax, rightMax := 0, 0
    for left < right {
        leftMax = max(leftMax, height[left])
        rightMax = max(rightMax, height[right])
        if leftMax < rightMax {
            ans += leftMax - height[left]
            left+=1
        } else {
            ans += rightMax - height[right]
            right-=1
        }
    }
    return
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}