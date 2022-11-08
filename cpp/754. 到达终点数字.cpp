class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = ceil((-1 + sqrt(8L * target + 1)) / 2); // 注意 8*target 会超过 int 范围
        return (n * (n + 1) / 2 - target) % 2 == 0 ? n : n + 1 + n % 2;
    }
};