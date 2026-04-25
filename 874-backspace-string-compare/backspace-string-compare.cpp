class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(auto& a:s)
        {
            if(a=='#')
            {
                if(s1.empty())
                    continue;
                s1.pop();
            }
            else s1.push(a);
            
        }
        for(auto& a:t)
        {
            if(a=='#')
            {
                if(s2.empty())
                    continue;
                s2.pop();
            }
            else s2.push(a);
            
        }
        if(s1.size()!=s2.size())
            return false;
        while(!s1.empty())
        {
            if(s1.top()==s2.top())
                {s1.pop();s2.pop();}
            else 
            return false;
        }
        return true;
    }
};