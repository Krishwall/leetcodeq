class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int min=0,max=0;
        for(auto a:s)
        {
            if(a=='(')
                {
                    min+=1;
                    max+=1;

                }
            else if(a==')' )
                    {
                        min-=1;
                        max-=1;
                    }
            else 
            {
                min-=1;
                max+=1;
            }
            if(min<0) min=0;
            if(max<0) return false;


            
        }
        return (min==0);
    }
};