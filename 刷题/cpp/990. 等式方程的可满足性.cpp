class Solution {
public:
    unordered_map<char,char> father;
    int find(char x) {
        if(father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }

    void Union(char a,char b) {
        char Fa = find(a);
        char Fb = find(b);
        if(Fa != Fb) {
            father[Fa] = Fb;
        }
    }

    bool isConnected(char a, char b) {
        char Fa = find(a);
        char Fb = find(b);
        return Fa == Fb;
    }

    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<26; i++) {
            father['a'+i] = 'a' +i;
        }
        for(auto equation: equations) {
            char a=equation[0];
            char b=equation[3];
            if(equation[1] == '='){
                Union(a, b);
            }
        }
        for(auto equation: equations) {
            char a=equation[0];
            char b=equation[3];
            if(equation[1] == '!'){
                if(isConnected(a, b)) {
                    return false;
                }
            }
        }
        return true;
    }
};