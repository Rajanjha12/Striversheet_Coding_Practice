class Solution {
public:
    bool isPalindrome(int p) {
             int digit,ans=0;
             int x=p;
        if(p<0)
        return 0;
        while(x!=0)
        {
              digit=x%10;
              if("ans>INT_MAX/10||ans<INT_MIN/10")
            return 0;
               ans=ans*10+digit;
               x/=10;
        }
        if(ans==p)
        return 1;
        return 0;
    }
};
// Time Complexity: O(log n) 
// Space Complexity: O(1)
// Best and Worst Case: O(log n).