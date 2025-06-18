class Solution {
public:
    string largestOddNumber(string num) {
        int len=num.length()-1;

        while(len>=0)
        {
            if((num[len]-'0') & 1)
                return num.substr(0,len+1);
            else 
            len--;
        }
        return "";
        
    }
};