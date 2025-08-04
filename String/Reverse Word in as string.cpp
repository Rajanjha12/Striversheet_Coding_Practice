// Method-1
string reverseWords(string s) { 
      int i=0;
         int n=s.size();
         string ans="";
         while(i<n)
         {
            string temp="";
            while(s[i]==' '&&i<n)
            i++;
            while(s[i]!=' '&&i<n)
            {
                temp+=s[i];
                i++;
            }
            if(temp.size()>0)
            {
                if(ans.size()==0)
                {
                    ans=temp;
                }
                else{
                    ans=temp+' '+ans;
                }
            }

         }
         return ans;
    }
    //(n2) Time complexity and O(n) space complexity 
    //Method-2 optimised
    string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Step 1: Extract words (automatically skips extra spaces)
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 2: Reverse the vector of words
    reverse(words.begin(), words.end());

    // Step 3: Join the words with a single space
    string result;
    for (int i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }

    return result;
}
//O(n) Time Complexity and o(n) space complexity;