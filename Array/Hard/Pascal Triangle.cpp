//Method-1 Brute Force Approach
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
//Time Complexity: O(r) where r is the size of the second array
//Space Complexity: O(1) as we are not using any extra space except the output
//Method-2 Optimal Approach
long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
// Time Complexity: O(n) where n is the size of the first array
// Space Complexity: O(1) as we are not using any extra space except the output
//Method-3 Pascal's Triangle Approach
vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);
       for(int i=0;i<numRows;i++)
       {
    result[i]=vector<int>(i+1,1);
    for(int j=1;j<i;j++)
 {
    result[i][j]=result[i-1][j]+result[i-1][j-1];
 }

       }
       return result;
    }
//Time Complexity: O(n^2) where n is the number of rows in the triangle
//Space Complexity: O(n^2) as we are using a 2D vector to