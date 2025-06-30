class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word, res;
        while (iss >> word) res = word + (res.empty() ? "" : " ") + res;
        return res;    
    }
};