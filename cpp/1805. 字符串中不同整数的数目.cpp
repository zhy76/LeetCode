class Solution {
public:
    int numDifferentIntegers(string word) {
        int n=word.size();
        set<string> st;
        for(int i=0;i<n;){
            string t="";
            while(word[i]>='0'&&word[i]<='9'){
                t+=word[i];
                i++;
            }
            if(t!="") {
                while(t[0]=='0'){
                    t.erase(t.begin());
                }
                st.insert(t);
            }
            i++;
        }
        return st.size();
    }
};