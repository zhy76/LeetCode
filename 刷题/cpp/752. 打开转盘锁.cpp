class Solution {
public:
    string plusOne(string s, int i) {
    char ch[s.length() + 1];  // Allocate extra space for null terminator
    strncpy(ch, s.c_str(), sizeof(ch));  // Use strncpy instead of strcpy
    ch[sizeof(ch) - 1] = '\0';  // Ensure null terminator
    if (ch[i] == '9') {
        ch[i] = '0';
    } else {
        ch[i] += 1;
    }
    return string(ch);
}

string minusOne(string s, int i) {
    char ch[s.length() + 1];  // Allocate extra space for null terminator
    strncpy(ch, s.c_str(), sizeof(ch));  // Use strncpy instead of strcpy
    ch[sizeof(ch) - 1] = '\0';  // Ensure null terminator
    if (ch[i] == '0') {
        ch[i] = '9';
    } else {
        ch[i] -= 1;
    }
    return string(ch);
}


    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        queue<string> qu;
        qu.push("0000");
        visited.insert("0000");
        unordered_set<string> deads;
        for (string s : deadends) {
            deads.insert(s);
        }
        int step = 0;
        while(!qu.empty()){
            int sz = qu.size();
            for(int i=0; i<sz; i++) {
                string cur = qu.front();
                qu.pop();
                if(deads.count(cur)){
                    continue;
                }
                if(cur == target) {
                    return step;
                }
                for(int j=0;j<4;j++){
                    string up = plusOne(cur, j);
                    if(!visited.count(up)){
                        qu.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if(!visited.count(down)){
                        qu.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};