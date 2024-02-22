class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        string tmp = "";
        for(auto c : version1) {
            if(c != '.') {
                tmp += c;
            } else {
                v1.push_back(stoi(tmp));
                tmp = "";
            }
        }
        v1.push_back(stoi(tmp));
        tmp = "";
        for(auto c : version2) {
            if(c != '.') {
                tmp += c;
            } else {
                v2.push_back(stoi(tmp));
                tmp = "";
            }
        }
        v2.push_back(stoi(tmp));
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()) {
            // cout<<v1[i] <<v2[j]<<endl;
            if(v1[i] < v2[j]) return -1;
            else if(v1[i] > v2[j]) return 1;
            else if(v1[i] == v2[j]) {
                i++;
                j++;
            }
        }
        while(i < v1.size()) {
            if(v1[i] != 0) return 1;
            i++;
        }
        while(j < v2.size()) {
            if(v2[j] != 0) return -1;
            j++;
        }
        return 0;
    }
};