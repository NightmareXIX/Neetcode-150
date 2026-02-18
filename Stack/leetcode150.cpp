#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
int evalRPN(vector<string>& tokens) {
        int n = tokens.size(); 
        vector<int> st; 

        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or 
                tokens[i] == "/") {
                int b = st.back(); st.pop_back(); 
                int a = st.back(); st.pop_back(); 
                int val; 

                if (tokens[i] == "+")
                    val = a + b; 
                else if (tokens[i] == "-")
                    val = a - b; 
                else if (tokens[i] == "*")
                    val = a * b; 
                else 
                    val = a / b; 

                st.push_back(val); 
            }
            else {
                int val = stoi(tokens[i]); 
                st.push_back(val); 
            }
        }
        return st.back(); 
    }
};