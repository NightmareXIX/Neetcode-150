class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size(); 
        vector<int> f1(26), f2(26); 

        for (int i = 0; i < n; i++)
            f1[s1[i] - 'a']++; 

        int j = 0; 
        for (int i = 0; i < m; i++) {
            int ind = s2[i] - 'a'; 
            f2[ind]++; 
            while (j <= i and f2[ind] > f1[ind]) {
                f2[s2[j] - 'a']--; 
                j++; 
            }

            bool flag = true; 
            for (int k = 0; k < 26; k++) {
                if (f1[k] != f2[k]) flag = false; 
            }
            if (flag) return true; 
        }

        return false; 
    }
};