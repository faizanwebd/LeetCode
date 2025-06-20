class RandomizedSet {
    unordered_map<int, int> valToIndex;
    vector<int> values;

public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) return false;
        int idx = valToIndex[val];
        int lastVal = values.back();
        values[idx] = lastVal;
        valToIndex[lastVal] = idx;
        values.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        return values[rand() % values.size()];
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */