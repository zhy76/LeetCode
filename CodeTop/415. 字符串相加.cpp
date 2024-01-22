class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int carry = 0;
        int i = len1 - 1, j = len2 - 1;
        string ans;
        while(i>=0 || j>=0 || carry != 0) {
            int a = i>=0? num1[i] - '0':0;
            int b = j>=0? num2[j] - '0':0;
            int sum = a+b+carry;
            ans += (sum % 10 + '0');
            carry = sum/10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};