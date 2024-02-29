class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int a = num1[i]-'0';
                int b = num2[j]-'0';
                int mul = a * b;
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        string ans = "";
        int i = 0;
        while(i < res.size() && res[i] == 0) i++;
        for(; i < res.size(); i++) {
            ans += (res[i] + '0');
        }
        return ans == "" ? "0" : ans;
    }
};