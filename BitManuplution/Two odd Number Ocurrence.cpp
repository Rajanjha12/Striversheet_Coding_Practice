/*Given an unsorted array, arr[] of positive numbers that contains even number of occurrences for all numbers except two numbers. Return that two numbers in decreasing order which has odd occurrences.

Examples:

Input: arr = [4, 2, 4, 5, 2, 3, 3, 1]
Output: [5, 1] 
Explanation: 5 and 1 have odd occurrences.
 esme jo one time aaye hain unko return karna hai
*/
// Method-1
class Solution {
  public:
    vector<int> twoOddNum(vector<int>& Arr) {
        // code here
     long long  int N=Arr.size();
               long long int xorr=0;
        for(long long int i=0; i<N; i++){
            xorr^=Arr[i];
        }
        
        long long int rgtmost=(xorr&(-xorr));
    /*This gives the rightmost set bit in xorr.
🔍 Why use the rightmost set bit?
In binary, xorr = A ^ B, and since A ≠ B, there must be at least one bit where A and B differ.
The rightmost set bit tells us the first bit from the right where A and B differ.
*/

        long long a=0, b=0;
        
        for(long long int i=0; i<N; i++){
            if(Arr[i] & rgtmost){
                a^=Arr[i];
            }else{
                b^=Arr[i];
            }
        }
        //Divide elements into two groups
        
        if(a<b) swap(a, b);
        
        return {a, b};
 
    }
};
// Time complexity O(n), space complexity O(1)
/*full Explaonation:

Input:  [2, 3, 3, 2, 5, 6]
xorr = 5 ^ 6 = 3
Rightmost set bit = 1 (binary 0011)

Group A (set bit): 3, 3, 5
Group B (unset bit): 2, 2, 6

Group A XOR: 3 ^ 3 ^ 5 = 5
Group B XOR: 2 ^ 2 ^ 6 = 6

Return: {6, 5}*/