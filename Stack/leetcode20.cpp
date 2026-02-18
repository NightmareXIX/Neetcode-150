#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isValid(string s) {
        int n = s.size(); 

        stack<char> st; 
        map<char, char> mp; 
        mp[')'] = '('; mp['}'] = '{'; mp[']'] = '['; 
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')
                st.push(s[i]); 
            else {
                if (st.empty()) return false; 
                
                char c = st.top(); st.pop(); 
                if (mp[s[i]] != c)
                    return false; 
            }
        }

        return (st.empty()); 
    }
};