// 给定一个长度为 N 的近乎有序数组，和一个元素 x，如果 x 在数组中，输出 x 在数组中的下标。如果不存在，输出 -1。要求时间和空间复杂度尽可能低。
// 近乎有序数组指的是，将有序数组中的某些元素与前或者后一个元素交换后形成的数组。其中, array[i] 只能与 array[i-1] 或者 array[i+1] 交换。每个元素只会交换一次。
// 例如：
// 输入：array[] =  {10, 3, 40, 20, 50, 80, 70}, x = 40
// 输出：2

#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr =  {10, 3, 40, 20, 50, 80, 70};
    int x = 40;
    int n = arr.size();
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = l + (r - l + 1) / 2;
        if(arr[mid] == x) {
            cout<<mid<<endl;
            return 0;
        } else if(arr[l] <= x && x < arr[mid] || arr[mid] < x && x <= arr[l]) {
            r = mid - 1;
        } else if(arr[r] <= x && x < arr[mid] || arr[mid] < x && x <= arr[r]) {
            l = mid + 1;
        } else {
            l = mid;
        }
    }
    cout<<-1<<endl;
    return 0;
}