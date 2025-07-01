
//Method-1 two Pointer Optimal Approach Time Complexity: O(n) Space Complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=0;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j]!=0)
            {
                swap(arr[i],arr[j]);
                i++;
            }
        }
    }
};
//Method-2 Brute Force time complexity o(n) and space complexity O(n)
 vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;