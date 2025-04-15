class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        for (int num : arr) {
            countMap[num]++;
        }

        unordered_set<int> occurrences;
        for (auto pair : countMap) {
            if (occurrences.count(pair.second)) {
                return false;  
            }
            occurrences.insert(pair.second);
        }

        return true;  
    }
};
