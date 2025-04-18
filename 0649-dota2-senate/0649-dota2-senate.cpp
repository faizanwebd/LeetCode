class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        
        while (!radiant.empty() && !dire.empty()) {
            int r_idx = radiant.front();
            int d_idx = dire.front();
            
            radiant.pop();
            dire.pop();
            
            if (r_idx < d_idx) {
                radiant.push(r_idx + senate.length());
            } else {
                dire.push(d_idx + senate.length());
            }
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
