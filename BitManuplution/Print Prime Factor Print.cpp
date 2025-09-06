/*Given a number n. Find its unique prime factors in increasing order.

Examples :

Input: n = 100
Output: [2, 5]
Explanation: Unique prime factors of 100 are 2 and 5.*/

class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
       ector<int> ans;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                while (n % i == 0) n /= i; // remove all multiples of i
            }
        }
        if (n > 1) ans.push_back(n); // remaining prime
        return ans;
    }
};
// Time complexity: O(sqrt(n)), space complexity: O(1)