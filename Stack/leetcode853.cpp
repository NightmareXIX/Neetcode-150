#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(); 
        
        vector<pair<int, float>> tp(n); 
        for (int i = 0; i < n; i++) {
            tp[i].first = position[i]; 
            tp[i].second = 1.0 * (target - position[i]) / speed[i]; 
        }
        sort(tp.begin(), tp.end()); 

        int ans = 0; 
        float cur = 0; 
        for (int i = n - 1; i >= 0; i--) {
            if (tp[i].second > cur) {
                ans++; cur = tp[i].second; 
            }
        }
        return ans; 
    }
};