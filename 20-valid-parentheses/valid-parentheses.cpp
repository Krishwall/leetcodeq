class Solution {
public:
    bool isValid(string s) {
        if ((s.length() & 1) ==1)
            return false;
        
        stack<char> brac;

        for (char c:s){
            if(c=='(' || c=='{'|| c=='[')
                brac.push(c);
            else
            {
                if (
                    brac.empty() || (c==')' && brac.top()!='(')||(c==']' && brac.top()!='[')||(c=='}' && brac.top()!='{'))
                    return false;
            brac.pop();
            }
        }
        return brac.empty();
    }
};