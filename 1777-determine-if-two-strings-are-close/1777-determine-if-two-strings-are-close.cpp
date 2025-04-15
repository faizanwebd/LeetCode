class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        unordered_set<char> set1, set2;

        for (char c : word1) {
            freq1[c - 'a']++;
            set1.insert(c);
        }
        for (char c : word2) {
            freq2[c - 'a']++;
            set2.insert(c);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return (set1 == set2) && (freq1 == freq2);
    }
};
