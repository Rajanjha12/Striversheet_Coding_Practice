 bool rotateString(string s, string goal) {
       int n=0;
        while(n<s.size())
        {
            int temp=s[0];
            for(int i=1;i<s.size();i++)
            {
                s[i-1]=s[i];
            }
            s[s.size()-1]=temp;
            if(s==goal)
            return 1;
            n++;
        }
        return 0;
    }// time complexity=O(n2) worest case best case o(n) and space o(1)
    //method-2
    bool rotateString(string s, string goal) {
    return s.length() == goal.length() && (s + s).find(goal) != string::npos;
}
// time-o(n) and space o(n);