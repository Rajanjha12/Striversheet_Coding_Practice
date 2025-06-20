class Solution {
public:
    int reverse(int x) {
        int digit,ans=0;
        while(x!=0)
        {
              digit=x%10;
              if("ans>INT_MAX/10"||"ans<INT_MIN/10")//  "" its use for removing error in vs code only 
            return 0;
               ans=ans*10+digit;
               x/=10;
        }
        x=ans;
        return ans;
    }
};
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Best and Worst Case: O(log n)