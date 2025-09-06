class Solution {
  public:
string armstrongNumber(int n) {
        int c=n;
        int digit,sum=0;
        int b=to_string(n).length();
       int i;
        while(c!=0)
        {
            digit=c%10;
            sum=sum+pow(digit,b);
            c=c/10;
            
        }
            if(sum==n)
            {
                return "true";
            }else
            
            return "false";
            
        
        
        // code here
    }
};
// Time complexity:O(log n)
// Space complexity:O(1)