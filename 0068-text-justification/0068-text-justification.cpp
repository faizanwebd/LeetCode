class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();
        while (i < n) {
            int lineLen = words[i].length();
            int j = i + 1;
            while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }
            int wordCount = j - i;
            int totalSpaces = maxWidth - lineLen + (wordCount - 1);
            string line;
            if (j == n || wordCount == 1) {
                line = words[i];
                for (int k = i + 1; k < j; ++k) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int space = totalSpaces / (wordCount - 1);
                int extra = totalSpaces % (wordCount - 1);
                for (int k = i; k < j - 1; ++k) {
                    line += words[k];
                    line += string(space + (k - i < extra ? 1 : 0), ' ');
                }
                line += words[j - 1];
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
