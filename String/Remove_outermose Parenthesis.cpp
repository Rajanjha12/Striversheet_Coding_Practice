// using string concept
//Method-1
string removeOuterParentheses(string s) {
        string result;   
        int balance = 0; 
 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                 
                if (balance > 0) {
                    result += s[i];  
                }
                balance++; 
            } else {
                balance--;  
                if (balance > 0) {
                    result += s[i];  
            }
        }
        }

        return result;  
    }
//Best case and worest case O(n) and space O(n);
//Method-2 Stack