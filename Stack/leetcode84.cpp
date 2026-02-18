#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); 
        vector<int> st, left(n), right(n); 
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.back()] >= heights[i])
                st.pop_back(); 

            left[i] = (st.empty()) ? 0 : st.back() + 1; 
            st.push_back(i); 
        }

        st.clear(); 
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and heights[st.back()] >= heights[i])
                st.pop_back(); 

            right[i] = (st.empty()) ? n - 1 : st.back() - 1; 
            st.push_back(i); 
        }

        int ans = 0; 
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (right[i] - left[i] + 1); 
            ans = max(ans, area); 
        }
        return ans; 
    }
};