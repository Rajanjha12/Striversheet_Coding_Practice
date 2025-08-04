/*Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/
/// Method-1 Optimal Approach
void rotate(vector<vector<int>>& matrix) {
      /* Method-1 covered space:o(n),time o(n2)
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));  
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }
 
        matrix = ans;
        */
        //Method-2 space-o(1),time o(n2);
        int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
 
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    }
