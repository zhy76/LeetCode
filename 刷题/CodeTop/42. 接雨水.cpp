class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n-1;
        int res = 0;
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax > rightMax) {
                res += rightMax - height[right];
                right--;
            } else {
                res += leftMax - height[left];
                left++;
            }
        }
        return res;
    }
};