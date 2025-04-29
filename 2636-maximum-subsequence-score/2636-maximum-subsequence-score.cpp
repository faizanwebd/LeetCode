class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i)
            pairs.emplace_back(nums2[i], nums1[i]);

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, res = 0;

        for (auto& [min2, val1] : pairs) {
            minHeap.push(val1);
            sum += val1;

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k)
                res = max(res, sum * min2);
        }

        return res;
    }
};
