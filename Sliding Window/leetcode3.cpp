class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); 
        unordered_map<char, int> mp; 

        int j = 0, len = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++; 
            while (mp[s[i]] > 1) {
                mp[s[j++]]--;
            }
            len = max(len, i - j + 1); 
        }
        return len; 
    }
};