class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1,words2;
        string t="";
        for(char ch:sentence1){
            if(ch!=' '){
                t+=ch;
            }else{
                words1.emplace_back(t);
                t="";
            }
        }
        words1.emplace_back(t);
        t="";
        for(char ch:sentence2){
            if(ch!=' '){
                t+=ch;
            }else{
                cout<<t<<endl;
                words2.emplace_back(t);
                t="";
            }
        }
        cout<<t<<endl;
        words2.emplace_back(t);
        t="";
        int n1=words1.size(),n2=words2.size();
        int i=0,j=0;
        while(i<n1&&i<n2&&words1[i]==words2[i]){
            i++;
        }
        while(j<n1-i&&j<n2-i&&words1[n1-j-1]==words2[n2-j-1]){
            j++;
        }
        return i+j==min(n1,n2);
    }
};