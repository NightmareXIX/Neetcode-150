#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); 
        
        multiset<int> st; 
        for (int i = 0; i < k - 1; i++) {
            st.insert(nums[i]); 
        }

        vector<int> ans; 
        for (int i = k - 1; i < n; i++) {
            st.insert(nums[i]); 
            ans.push_back(*st.rbegin()); 

            int val = nums[i - k + 1]; 
            st.erase(st.find(val)); 
        }
        return ans; 
    }
};