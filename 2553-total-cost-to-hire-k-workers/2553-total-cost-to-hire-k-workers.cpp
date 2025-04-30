class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long total_cost = 0;
        int left = 0, right = n - 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> left_heap, right_heap;

        for (int i = 0; i < candidates && left <= right; ++i) {
            left_heap.push({costs[left], left});
            ++left;
        }
        for (int i = 0; i < candidates && left <= right; ++i) {
            right_heap.push({costs[right], right});
            --right;
        }

        for (int i = 0; i < k; ++i) {
            if (!left_heap.empty() && !right_heap.empty()) {
                if (left_heap.top().first <= right_heap.top().first) {
                    auto [cost, idx] = left_heap.top();
                    left_heap.pop();
                    total_cost += cost;
                    if (left <= right) {
                        left_heap.push({costs[left], left});
                        ++left;
                    }
                } else {
                    auto [cost, idx] = right_heap.top();
                    right_heap.pop();
                    total_cost += cost;
                    if (left <= right) {
                        right_heap.push({costs[right], right});
                        --right;
                    }
                }
            } else if (!left_heap.empty()) {
                auto [cost, idx] = left_heap.top();
                left_heap.pop();
                total_cost += cost;
                if (left <= right) {
                    left_heap.push({costs[left], left});
                    ++left;
                }
            } else if (!right_heap.empty()) {
                auto [cost, idx] = right_heap.top();
                right_heap.pop();
                total_cost += cost;
                if (left <= right) {
                    right_heap.push({costs[right], right});
                    --right;
                }
            }
        }

        return total_cost;
    }
};