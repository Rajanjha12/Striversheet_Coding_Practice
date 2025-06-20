   
   //example:s = ["h","e","l","l","o"]
   // Time Complexity: O(n) Two-pointer approach
   // Space Complexity: O(1)  
   
   void reverseString(vector<char>& s) {
         int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }