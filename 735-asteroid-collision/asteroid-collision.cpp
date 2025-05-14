class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;++i)
        {     
             bool destroyed = false;
              
                while(!st.empty()&& st.top()>0 && asteroids[i]<0 )
                {
                    if(st.top()<-asteroids[i])
                        {st.pop();}
                    else if(st.top()==-asteroids[i] )
                        {st.pop();  destroyed = true;
                        break;}
                    else
                       {destroyed=true;
                        break;}

                 }
                 
                
                if (!destroyed) {
                st.push(asteroids[i]);
            }

        }
            
        vector<int> v;

    
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }

    
    reverse(v.begin(), v.end());
        return v;
        }
    
};