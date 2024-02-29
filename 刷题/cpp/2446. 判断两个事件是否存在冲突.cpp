class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int time1_start=(10*(event1[0][0]-'0')+(event1[0][1]-'0'))*60+(10*(event1[0][3]-'0')+(event1[0][4]-'0'));
        int time1_end=(10*(event1[1][0]-'0')+(event1[1][1]-'0'))*60+(10*(event1[1][3]-'0')+(event1[1][4]-'0'));
        int time2_start=(10*(event2[0][0]-'0')+(event2[0][1]-'0'))*60+(10*(event2[0][3]-'0')+(event2[0][4]-'0'));
        int time2_end=(10*(event2[1][0]-'0')+(event2[1][1]-'0'))*60+(10*(event2[1][3]-'0')+(event2[1][4]-'0'));
        if(time1_start<=time2_start&&time1_end>=time2_start|| time2_start<=time1_end&& time1_start<=time2_end){
            return true;
        }
        return false;
    }
};