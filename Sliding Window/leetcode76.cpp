class Solution {
public:
    bool check(unordered_map<char, int>& f1, unordered_map<char, int>& f2) {
        for (auto [x, y] : f1) {
            if (y > f2[x]) return false; 
        }
        return true; 
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(); 
        unordered_map<char, int> f1, f2; 

        for (int i = 0; i < m; i++) 
            f1[t[i]]++; 

        int j = 0, len = INT_MAX, l, r; 
        for (int i = 0; i < n; i++) {
            f2[s[i]]++; 
            while (j <= i and f2[s[j]] > f1[s[j]]) {
                f2[s[j]]--; j++; 
            }

            int cur = i - j + 1; 
            if (check(f1, f2) and cur < len) {
                len = cur; 
                l = j, r = i; 
            }
        }

        string ans = ""; 
        for (int i = l; i <= r; i++)
            ans += s[i]; 
        return ans; 
    }
};