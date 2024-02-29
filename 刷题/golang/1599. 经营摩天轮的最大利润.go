func minOperationsMaxProfit(customers []int, boardingCost int, runningCost int) int {
    ans := -1
    var cnt, maxProfit, profit, rest int
    for _, customer := range customers {
        cnt++
        customer += rest
        if customer > 4 {
            profit += 4*boardingCost
            rest = customer - 4
        } else {
            profit += customer*boardingCost
            rest = 0
        }
        profit -= runningCost
        if profit > maxProfit {
            maxProfit = profit
            ans = cnt
        }
    }
    for rest > 0 {
        if boardingCost*4 - runningCost < 0 {
            return ans
        }
        cnt++
        if rest > 4 {
            profit += 4*boardingCost
            rest -= 4
        } else {
            profit += rest*boardingCost
            rest = 0
        }
        profit -= runningCost
        if profit > maxProfit {
            maxProfit = profit
            ans = cnt
        }
    }
    return ans
}