/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
// 方法一：枚举
// class Solution {
// public:
//     vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
//         vector<vector<int> > ans;
//         for(int x=1;x<=1000;x++){
//             for(int y=1;y<=1000;y++){
//                 if(customfunction.f(x,y)==z){
//                     ans.push_back({x,y});
//                 }
//             }
//         }
//         return ans;
//     }
// };
// 方法二：二分
// class Solution {
// public:
//     vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
//         vector<vector<int> > ans;
//         for(int x=1;x<=1000;x++){
//             int yleft=1,yright=1000;
//             while(yleft<=yright){
//                 int ymid=(yleft+yright)>>1;
//                 if(customfunction.f(x,ymid)==z){
//                     ans.push_back({x,ymid});
//                     break;
//                 }
//                 if(customfunction.f(x,ymid)<z){
//                     yleft=ymid+1;
//                 }else{
//                     yright=ymid-1;
//                 }
//             }
//         }
//         return ans;
//     }
// };
// 方法三：双指针
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int> > ans;
        for(int x=1,y=1000;x<=1000&&y>=1;x++){
            while(y>=1&&customfunction.f(x,y)>z){
                y--;
            }
            if(y>=1&&customfunction.f(x,y)==z){
                ans.push_back({x,y});
            }
        }
        return ans;
    }
};