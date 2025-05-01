class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        string current;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
            string letters = phone[digits[index] - '0'];
            for (char c : letters) {
                current.push_back(c);
                backtrack(index + 1);
                current.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};
