/*Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/
class Solution {
public:
    int countPrimes(int n) {
          int cnt = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * 2; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};
// Time complexity: O(n log log n), space complexity: O(n)