// //将给定的数组中的元素进行波浪形排序，要求时间和空间复杂度尽可能低。
// //波浪形排序是指：arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5] ...
// //例如：
// //输入：1, 2, 6, 7, 5, 3, 4
// //输出：4, 1, 7, 5, 6, 2, 3
// // 1,2,3,4,5,6,7
// #include <iostream>
// #include <vector>
// using namespace std;

// void wiggleSort(vector<int>& arr) {
//     for (size_t i = 0; i < arr.size() - 1; ++i) {
//         if ((i % 2 == 0) == (arr[i] < arr[i + 1])) {
//             swap(arr[i], arr[i + 1]);
//         }
//     }
// }

// int main() {
//     vector<int> arr = {1, 2, 6, 7, 5, 3, 4};
//     wiggleSort(arr);

//     for (int num : arr) {
//         cout << num << " ";
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
