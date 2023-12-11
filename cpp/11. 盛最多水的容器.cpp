class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
           int high = min(height[left], height[right]);
           ans = max(ans, high * (right - left));
           if(height[left] < height[right]) {
               left++;
           } else {
               right--;
           }
        }
        return ans;
    }
};