#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 

        int l = 0, r = n - 1, k; 
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] <= nums[n - 1])
                k = mid, r = mid - 1; 
            else 
                l = mid + 1; 
        }

        if (target <= nums[n - 1])
            l = k, r = n - 1;
        else 
            l = 0, r = k - 1; 

        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] == target)
                return mid; 
            else if (nums[mid] < target)
                l = mid + 1; 
            else 
                r = mid - 1; 
        }
        return -1; 
    }
};