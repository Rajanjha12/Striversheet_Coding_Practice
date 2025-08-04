// Method-1 Linear Search 
//Imp point : eq: 11/2=5not 6 take only integer part
/*Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.
Floor value of any number is the greatest Integer which is less than or equal to that number
Examples:
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.*/
int floorSqrt(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}
// Time Complexity: O(sqrt(n)) where n is the input number
//best case: O(1) if n is 0 or 1
//worst case: O(sqrt(n)) if n is a large number
// Space Complexity: O(1) as we are using only a constant amount of extra space
//Method-2 built-in function
int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}
// Time Complexity: O(1) as it uses the built-in sqrt function
// Space Complexity: O(1) as we are using only a constant amount of extra space
// Note: This code is designed to work with C++17 standard and may not be compatible with earlier versions.
//Method-3 Binary Search
int floorSqrt(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}
// Time Complexity: O(log n) where n is the input number
//best case: O(1) if n is 0 or 1
//worst case: O(log n) if n is a large number
// Space Complexity: O(1) as we are using only a constant amount of extra space
 