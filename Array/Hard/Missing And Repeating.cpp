//Method-1

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int repeating = -1, missing = -1;

    //Find the repeating and missing number:
    for (int i = 1; i <= n; i++) {
        //Count the occurrences:
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}
// Time Complexity: O(n^2) where n is the size of the array
// Space Complexity: O(1) as we are not using any extra space
// Method-2 Better Approach using Hashing
vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array
    int hash[n + 1] = {0}; // hash array

    //update the hash array:
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }

    //Find the repeating and missing number:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) for the hash array
// Method-3 Optimal Approach using Mathematical Formula
vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>ans;
           vector<int>count(arr.size(),0);
        for(int i=0;i<arr.size();i++)
       {
        count[arr[i]-1]++;
       }
         for(int i=0;i<arr.size();i++)
        {
            if(count[i]>1)
              ans.push_back(i+1);
        }
       for(int i=0;i<arr.size();i++)
       {
           if(count[i]==0)
           ans.push_back(i+1);
       }
       
        return ans;
    }
// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(n) for the count array