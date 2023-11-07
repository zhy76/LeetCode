class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;
        for(int i=left; i<=right; i++){
            string word=words[i];
            if(isVowel(word[0]) && isVowel(word[word.length()-1])){
                ans++;
            }
        }
        return ans;
    }
};