//Method-1 optimized approach
/*Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size(),col=matrix[0].size();
        int top=0,bottom=row-1,right=col-1,left=0;
        while(left<=right&&top<=bottom)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
                
            }
            top++;
             for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
                
            }
            right--;
            if(top<=bottom)
            {
             for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
                
            }
            bottom--;
            }
            if(left<=right)
            {
             for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
                
            }
            left++;
            }

        }
        return ans;

    }
// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns
// Space Complexity: O(1) as we are not using any extra space except the output