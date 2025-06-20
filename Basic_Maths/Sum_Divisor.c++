/* 4->f(1)+f(2)+f(3)+f(4)
Brute force approach
Time complexity: O(n^2)
    // Print the number divisoon of striver sheet;
*/ 
class Solution {
  public:
  long long sum1(int n1)
  { int sum =0;
      for(int i=1;i<=n1;i++)
        {
            if(n1%i==0)
            sum=sum+i;
            
        }
        return sum;
  }
    long long sumOfDivisors(long long n) {
        // Code here
        long long sum =0;
        for(int i=1;i<=n;i++)
        {
            sum=sum+sum1(i);
            
        }
        return sum;
    }
};
// Method-2
class Solution {
  public:
 int sum1(int n){
        int sum =0;
        for(int i =1 ;i<=sqrt(n); i++){
            if(n%i==0){
                sum+=i;
                if((n/i)!= i) sum+=(n/i);
            }
        }
        return sum;
    }
    long long sumOfDivisors(long long n) {
        // Code here
        long long sum =0;
        for(int i=1;i<=n;i++)
        {
            sum=sum+sum1(i);
            
        }
        return sum;
    }
};
//optimal approach
// Time complexity: o(n)
class Solution {
public:
    long long sumOfDivisors(long long n) {
        long long sum = 0;
        for (long long i = 1; i <= n; i++) {
            sum += (n / i) * i;
        }
        return sum;
    }
};