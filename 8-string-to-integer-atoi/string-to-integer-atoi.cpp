class Solution {
public:
    int myAtoi(string s) {
        int c=0;int sign=1,digit;long long num=0;
        while(s[c]==' ')
            ++c;
        if (s[c]=='-')
            {sign=-1;
            ++c;}
        else if(s[c]=='+')
            ++c;
        
        while(s[c]>='0' && s[c]<='9' && c<s.size())
            {
                digit=s[c]-48;
                if((sign*(num*10+digit))>INT_MAX)
                return INT_MAX;
                if((sign*(num*10+digit))<INT_MIN)
                return INT_MIN;
                num=num*10+digit;
                c++;
            }
        return sign*num;
        
    }
};