/* 
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false

lets expalin the problemwith example:Convert n to a string → n1
Sort n1 (so digit order doesn’t matter)
Loop i from 0 to 29:
1 << i = 
2
𝑖
2 
i
(we stop at i < 30 because 2^30 = 1,073,741,824 is already close to 32-bit int limit)
Convert that power of 2 to string → n2
Sort n2

If n1 == n2, then n can be rearranged into that power of 2 → return true

If no match, return false.

Dry Run Example
Input:
cpp
Copy
Edit
n = 128
Execution:
n1 = "128"

Sort: "128" → "128"

Loop:

i = 0 → 1 << 0 = 1 → "1" → "1" (not match)

i = 1 → 1 << 1 = 2 → "2" → "2" (not match)

i = 2 → 1 << 2 = 4 → "4" (not match)

...

i = 7 → 1 << 7 = 128 → "128" → "128" → ✅ match → return true

Why up to 30 only
In 32-bit signed int:

1 << 30 = 1,073,741,824 (largest power of 2 < INT_MAX)

1 << 31 would overflow into the sign bit

Since we only care about positive integers, i range 0–29 is enough.
*/


class Solution {
public:
    bool reorderedPowerOf2(int n) {
         string n1 = to_string(n);
        sort(n1.begin(),n1.end());

        for(int i = 0; i < 30 ; i++){

            string n2 = to_string(1 << i);
            sort(n2.begin(), n2.end());

            if(n1 == n2) return true;
        }
        return false;
    }
};
// Time complexity: O(log n), space complexity: O(1)