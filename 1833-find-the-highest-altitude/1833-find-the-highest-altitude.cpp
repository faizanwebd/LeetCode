class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0, maxAltitude = 0;
        for (int g : gain) {
            altitude += g;
            maxAltitude = max(maxAltitude, altitude);
        }
        return maxAltitude;
    }
};
