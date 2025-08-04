//Method-2 using stl::set to find union of two arrays
// Time Complexity: O(n + m) where n and m are the sizes of the two arrays
// Space Complexity: O(n + m) for storing the union in a set

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        set<int>res;
        for(int i =0;i<a.size();i++){
           res.insert(a[i]);
       }
       for(int j =0;j<b.size();j++){
           res.insert(b[j]);
       }
       vector<int>ans(res.begin(), res.end()); // TO CONVERT SET INTO VECTOR
       return ans;
    }
    

