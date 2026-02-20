#include <bits/stdc++.h>
using namespace std; 

class Solution {
private: 
    int n, m; 
public:
    int findmed(vector<int>& arr1, vector<int>& arr2, int ind) {
        int l = 1, r = min((int)arr1.size(), ind), sz = ind + 1, target = INT_MAX; 
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            int ii = sz - mid;
            
            if (arr1[mid - 1] <= arr2[ii - 1]) {
                target = min(target, arr2[ii - 1]); 
                l = mid + 1;  
            }
            else {
                target = min(target, arr1[mid - 1]); 
                r = mid - 1;
            }
        }

        if (ind < arr1.size() and arr1[ind] <= arr2[0])
            return arr1[ind]; 
        else if (ind < arr2.size() and arr2[ind] <= arr1[0])
            return arr2[ind]; 
        else 
            return target; 
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(), m = nums2.size(); 

        if (!n) {
            if (m & 1)
                return nums2[m / 2]; 
            else {
                double val = (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0; 
                return val; 
            }
        }
        if (!m) {
            if (n & 1)
                return nums1[n / 2]; 
            else {
                double val = (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0; 
                return val; 
            }
        }

        double ans = 0; 
        if (n <= m) {
            if ((n + m) & 1)
                ans = findmed(nums1, nums2, (n + m) / 2); 
            else {
                ans += findmed(nums1, nums2, (n + m) / 2 - 1); 
                ans += findmed(nums1, nums2, (n + m) / 2); 
                ans /= 2.0; 
            }
        }
        else {
            if ((n + m) & 1)
                ans = findmed(nums2, nums1, (n + m) / 2); 
            else {
                ans += findmed(nums2, nums1, (n + m) / 2 - 1); 
                ans += findmed(nums2, nums1, (n + m) / 2); 
                ans /= 2.0; 
            }
        }
        return ans; 
    }
};