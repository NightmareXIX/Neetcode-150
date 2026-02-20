#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(); 

        int l = 0, r = n - 1, val; 
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            
            if (nums[mid] <= nums[n - 1]) {
                val = nums[mid], r = mid - 1; 
            }
            else 
                l = mid + 1; 
        }
        return val; 
    }
};