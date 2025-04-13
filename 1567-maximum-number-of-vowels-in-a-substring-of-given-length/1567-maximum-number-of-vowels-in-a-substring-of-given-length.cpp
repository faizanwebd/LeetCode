class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0, maxCnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) cnt++;
            if (i >= k && isVowel(s[i - k])) cnt--;
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
