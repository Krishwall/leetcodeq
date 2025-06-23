class Solution {
public:
    string reverseWords(string s) {
        
        int n =s.length();
        int i =0, j =0;

        while (i <n && s[i] ==' ') i++;  

        bool spacePending= false;
        while (i<n) {
            if (s[i]!=' ') {
                if (spacePending) s[j++]= ' ';
                s[j++] =s[i++];
                spacePending =false;
            } else {
                spacePending =true;
                i++;
            }
        }
       
        s.resize(j); 

        reverse(s.begin(), s.end());

       
        int start = 0;
        for (int end =0; end <=s.length(); ++end) {
            if (end== s.length() || s[end]== ' ') {
                reverse(s.begin()+start, s.begin()+end);
                start =end+1;
            }
        }

        return s;
    }
};
