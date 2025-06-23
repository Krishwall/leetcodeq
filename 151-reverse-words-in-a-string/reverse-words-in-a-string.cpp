class Solution {
public:
    string reverseWords(string s) {
        if(s=="")return s;
        int left=0,right=s.length()-1;
        
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;
        string temp="",ans="";
        while(left<=right)
        {
                char ch=s[left];
                if(left>0 && ch==' ' && s[left-1]==' '){ left++;continue;}
                if(ch!=' ')
                temp+=ch;
                else if(ch==' ' )
               { if (ans!="")ans=temp+' ' + ans;
                else ans=temp;
                temp="";}
                left++;
        }
        if (!temp.empty()) {
            if (!ans.empty())
                ans = temp + " " + ans;
            else
                ans = temp;
        }

        return ans;
    }
};