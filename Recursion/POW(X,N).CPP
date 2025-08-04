class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(n==0)
        return 1;
        if(N<0)
        {
            N=-N;
            x=1/x;
        }
        return (n%2==0)?myPow(x*x,N/2):x*myPow(x*x,N/2);
    }
};
//TIME COMPLEXITY :O(LOGN) AND SPACE :O(1);