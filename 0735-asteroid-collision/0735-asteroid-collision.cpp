class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            while (!st.empty() && st.top() > 0 && a < 0) {
                int top = st.top();
                if (abs(top) < abs(a)) {
                    st.pop();
                    continue;
                } else if (abs(top) == abs(a)) {
                    st.pop();
                }
                a = 0;
                break;
            }
            if (a != 0) st.push(a);
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
