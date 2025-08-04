void SortedStack :: sort()
{
   //Your code here
    stack<int> temp;

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        while (!temp.empty() && temp.top() < curr)
        {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(curr);
    }

    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
//TIME COMPLEXITY : O(N^2) AND SPACE : O(N);
//Method to sort the stack using recursion
void sortedinsert(stack<int>& s, int x){
       if(s.empty() || x > s.top()){
           s.push(x);
           return;
       }
       
       int temp = s.top();
       s.pop();
       sortedinsert(s, x);
       
       s.push(temp);
   }

void SortedStack ::sort() {
    // Your code here
    if(!s.empty()){
        int x = s.top();
        s.pop();
        sort();
        
        sortedinsert(s, x);
    }
}
//TIME COMPLEXITY : O(N2) AND SPACE : O(N);