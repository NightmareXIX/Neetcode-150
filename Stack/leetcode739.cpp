#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> st, ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and temperatures[st.back()] <= temperatures[i])
                st.pop_back();

            int val = (st.empty()) ? 0 : st.back() - i;
            ans[i] = val;
            st.push_back(i);
        }
        return ans;
    }
};