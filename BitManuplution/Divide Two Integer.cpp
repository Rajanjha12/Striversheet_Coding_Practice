/*Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.*/
//Method 1:
class Solution {
public:
    int divide(int dividend, int divisor) {
       if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        return dividend/divisor;
    }
};
//Time Complexity: O(1)
//Space Complexity: O(1)
//Method 2: Using Bit Manipulation
 /*
 Time Complexity : O(log(N)*log(N)), The time complexity of the code is O(log(N)*log(N)) since the outer loop
    and the inner loop both runs log(N) times, where N is the dividend.

    Space Complexity : O(1), The space complexity of the above code is O(1) since we’re using constant extra
    space.

    Solved using Math + Bit Manipulation.

*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        long long dvd = labs(dividend), dvs = labs(divisor), result = 0;
        int sign = (dividend > 0) ^ (divisor > 0) == 0 ? 1 : -1;
        while(dvd >= dvs){
            long long temp = dvs, mul = 1;
            while(temp << 1 <= dvd){
                temp <<= 1;
                mul <<= 1;
            }
            dvd -= temp;
            result += mul;
        } 
        return sign*result;
    }
};
//Method-3
class Solution {
public:
    int divide(int dividend, int divisor) {
    
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        

        long int dd = abs(dividend), dv = abs(divisor);
        
     
        int res=0;
        while(dv<=dd) {
            long int sum=dv, count=1;
            while(sum<=dd-sum) {
                sum+=sum;
                count+=count;
            }
            res+=count;
            dd-=sum;
        }
        
if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -res;
        
        return res;
          
    }
};