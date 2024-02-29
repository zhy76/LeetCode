class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string,vector<int> > timeMap;
        for(int i=0;i<keyName.size();i++){
            string name=keyName[i];
            string time=keyTime[i];
            int hour=(time[0]-'0')*10+(time[1]-'0');
            int minute=(time[3]-'0')*10+(time[4]-'0');
            timeMap[name].emplace_back(hour*60+minute);
        }
        vector<string> ans;
        for(auto &[name,vec]:timeMap){
            sort(vec.begin(),vec.end());
            int size=vec.size();
            for(int i=2;i<size;i++){
                int time1=vec[i-2],time2=vec[i];
                int diff=time2-time1;
                if(diff<=60){
                    ans.emplace_back(name);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};