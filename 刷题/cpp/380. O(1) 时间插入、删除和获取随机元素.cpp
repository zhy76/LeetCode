class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> value2index;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!value2index.count(val)) {
            value2index[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(!value2index.count(val)) {
            return false;
        }
        int ind = value2index[val];
        value2index[nums.back()] = ind;
        swap(nums[nums.size()-1], nums[ind]);
        nums.pop_back();
        value2index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */