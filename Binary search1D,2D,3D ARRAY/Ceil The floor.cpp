/*Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].

Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than greatest element of arr[].

Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is not present.

Examples:

Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
Output: 6, 8
Explanation: Floor of 7 is 6 and ceil of 7 is 8.
Input: x = 10 , arr[] = [5, 6, 8, 8, 6, 5, 5, 6]
Output: 8, -1
Explanation: Floor of 10 is 8 but ceil of 10 is not possible.*/
//Method-1
vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
         int f=-1,c=-1;
        int i;
        vector<int> ans;
    
        sort(arr.begin(),arr.end());
        for(i=0;i<arr.size();i++)
        {
            if(arr[i] < x)
                f=arr[i];
            
            if(arr[i] > x)
            {
                c=arr[i];
                break;
            }
            
            if(arr[i] == x)
                return {x,x};
                
        }
        ans.push_back(f);
        ans.push_back(c);
        
        return ans;
        
    }
// Time Complexity: O(n log n) for sorting the array, where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space


//iF THE ARRAY given in pair form and accept the the answer in pair form then use this code coding ninja question
//Method-2
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	// Write your code here.
	        int f = -1, c = -1;
       sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (arr[i] < x)
            f = arr[i];
        else if (arr[i] == x)
            return {x, x};
        else if (arr[i] > x) {
            c = arr[i];
            break;
        }
    }

    return {f, c};
}
// Time Complexity: O(n log n) for sorting the array, where n is the size of the array
// Space Complexity: O(1) as we are using only a constant amount of extra space