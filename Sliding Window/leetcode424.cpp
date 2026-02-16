class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); 
        vector<int> freq(26); 

        int j = 0, len = 0, mx = 0; 
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'A']++; 
            int cur = i - j + 1; mx = max(mx, freq[s[i] - 'A']); 
            while (cur - mx > k) {
                freq[s[j] - 'A']--; j++; 
                cur = i - j + 1; 
            }
            len = max(len, i - j + 1); 
        }   
        return len; 
    }
};