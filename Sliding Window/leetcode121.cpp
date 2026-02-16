class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 

        vector<int> pref(n); 
        pref[0] = prices[0]; 
        for (int i = 1; i < n; i++) {
            pref[i] = min(prices[i], pref[i - 1]); 
        }

        int ans = 0, mx = prices[n - 1]; 
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, prices[i]); 
            ans = max(ans, mx - pref[i]); 
        }
        return ans; 
    }
};