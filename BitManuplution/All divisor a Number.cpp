/*Given an integer n, print all the divisors of N in the ascending order.
 
Examples:

Input : n = 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.*/
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        set<int> ans;
        for(int i = 1 ; i*i <= n ; i++){
            if(n%i == 0){
                cout << i << " ";
                if(i!=n/i){
                    ans.insert(n/i);
                }
            }
        }
        for(auto it : ans){
            cout << it << " ";
        }
    }
};
// Time complexity: O(sqrt(n)), space complexity: O(1)