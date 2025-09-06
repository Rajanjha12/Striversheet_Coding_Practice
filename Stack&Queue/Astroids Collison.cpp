/*We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int &a : asteroids)//or For(int a=0; a < asteroids.size(); a++)
         {
            
            while(!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top();
                if(sum < 0) {
                    st.pop();
                } else if(sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop();
                    a = 0;
                }
            }
            
            if(a != 0)
                st.push(a);
            
        }
        
        int s = st.size();
        
        vector<int> result(s);
        int i = s-1;
        while(!st.empty()) {
            result[i] = st.top();
            st.pop();
            i--;
        }
        
        return result;
    }
};
// Time complexity: O(n), space complexity: O(n) for the stack
//Using vector<int> as stack - T.C (O(n))
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(int &a : asteroids)//or For(int a=0; a < asteroids.size(); a++)
         {
            
            while(!st.empty() && a < 0 && st.back() > 0) {
                int sum = a + st.back();
                if(sum < 0) {
                    st.pop_back();
                } else if(sum > 0) {
                    a = 0;
                    break;
                } else {
                    st.pop_back();
                    a = 0;
                }
            }
            
            if(a != 0)
                st.push_back(a);
            
        }
        
        
        return st;
    }
};