//question
/*You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

Examples :

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.*/
//Method-1 Linear Search
class Solution {
  public:
    int f(int i,int n)
        { 
            int ans=1;
            while(n--){
                ans=ans*i;
            }
            return ans;
        }
    int nthRoot(int n, int m) {
        // Code here
        int low=1,high=m;
        for(int i=1;i<=m;i++)
        {   int mid=(low+high)/2;
            if(f(mid,n)==m)
            {
                return i;
            }
            else if(f(mid,n)>m)
            break;
        }
        return -1;
    }
};
// Time Complexity: O(n * log m) Best case: O(n) if m is small 
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 Binary Search


//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
