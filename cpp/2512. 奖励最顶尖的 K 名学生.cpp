class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int> words;
        for(auto p:positive_feedback){
            words[p]=3;
        }
        for(auto n:negative_feedback){
            words[n]=-1;
        }
        int len=student_id.size();
        vector<pair<int,int> > score_id;
        for(int i=0;i<len;i++){
            string rep=report[i];
            int stu_id=student_id[i];
            vector<string> wo=split(rep,' ');
            int score=0;
            for(auto w:wo){
                if(words.count(w)){
                    score+=words[w];
                }
            }
            score_id.push_back({-score,stu_id});
        }
        sort(score_id.begin(),score_id.end());
        vector<int> top_k;
        for(int i=0;i<k;i++){
            top_k.push_back(score_id[i].second);
        }
        return top_k;
    }

    vector<string> split(string& s, char c){
        vector<string> words;
        string word;
        for(auto str: s){
            if(str==c){
                words.push_back(word);
                word="";
                continue;
            }
            word.push_back(str);
        }
        words.push_back(word);
        return words;
    }
};