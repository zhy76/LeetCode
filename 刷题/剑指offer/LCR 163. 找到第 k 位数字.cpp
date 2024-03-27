class Solution {
public:
    int findKthNumber(int k) {
        int digit = 1;
        long start = 1;
        long count = 9;
        while (k > count) { // 1.
            k -= count;
            start *= 10;
            digit += 1;
            count = digit * start * 9;
        }
        long num = start + (k - 1) / digit; // 2.
        return to_string(num)[(k - 1) % digit] - '0'; // 3.
    }
};
