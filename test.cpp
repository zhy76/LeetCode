/*

无序int数组的拆分
给定一个乱序的正整数数组，需要将该数组拆成n（n<=100）个子集，在保证每个子集的和不超过指定上限limit的情形下，
使n尽量小，请用尽可能最高效的方式实现。
比如，array = {1, 3, 6, 2, 5, 4, 9, 2, 7, 3, 5, 1, 8}, 1-10limit = 10,  程序输出 n、以及n个子集分别包含哪些数

n = sum / l;
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> track;
vector<int> nums;
vector<vector<int> > res;
void backtrack(vector<int> nums, int ind, int limit, int sum) {
    if(ind == nums.size()) {
        return;
    }
    if(sum > limit) {
        track.pop_back();
        res.push_back(track);
        return;
    }
    for(int i = ind; i < nums.size(); i++) {
        track.push_back(nums[i]);
        sum += nums[i];
        backtrack(nums, i + 1, limit, sum);
        sum -= nums[i];
        track.pop_back();
    }
}

int main() {
    vector<int> nums(10);
    int a[20] = {1, 3, 6, 2, 5, 4, 9, 2, 7, 3, 5, 1, 8};
    for (int i = 0; i < 10; i++) {
        nums[i] = a[i];
    }
    int limit = 10;
    int sum = 0;
    backtrack(nums, 0, limit, 0);
    cout<<res.size()<<endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
