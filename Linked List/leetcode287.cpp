#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans = 0; 
        for (int b = 0; b < 32; b++) {
            int set_bit = 1 << b; 
            
            int x = 0, y = 0; 
            for (int i = 0; i < n; i++) {
                if (nums[i] & set_bit)
                    x++; 
            }
            for (int i = 1; i < n; i++) {
                if (i & set_bit)
                    y++; 
            }

            if (x > y)
                ans |= set_bit; 
        }
        return ans; 
    }
};