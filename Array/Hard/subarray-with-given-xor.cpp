//Method-1
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}
// Time Complexity: O(n^3) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space
// Method-2 
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space
// Method-3 Optimal Approach using Hashing
int Solution::solve(vector<int> &A, int B) {
     vector<int> prefixXOR(A.size(),0);
    prefixXOR[0]=A[0];
    for(int i=1;i<A.size();i++)
    {
        prefixXOR[i]=prefixXOR[i-1] ^ A[i];
    }
    map<int,int> pam;
    int answer=0;
   
    for (int i = 0; i < A.size(); i++) {
        int xor1 = prefixXOR[i] ^ B;
       
        if (pam.find(xor1) != pam.end()) {
            answer += pam[xor1];
        }
       
        pam[prefixXOR[i]]++;
       
        if (prefixXOR[i] == B) {
            answer++;
        }
    }
    return answer;
}
