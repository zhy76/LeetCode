class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        int n = documents.size();
        int i = 0;
        while(i < n) {
            if(documents[i] == i) {
                i++;
                continue;
            }
            if(documents[i] == documents[documents[i]]) {
                return documents[i];
            }
            swap(documents[i], documents[documents[i]]);
        }
        return -1;
    }
};