class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge="";
        while(word1.length()&&word2.length()){
            if(word1>word2){
                merge+=word1[0];
                word1.erase(word1.begin());
            }else{
                merge+=word2[0];
                word2.erase(word2.begin());
            }
        }
        if(word1.length()){
            merge+=word1;
        }
        if(word2.length()){
            merge+=word2;
        }
        return merge;
    }
};