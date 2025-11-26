class Solution {
public:
    int possibleStringCount(string word) {
       
   int k=1;
        for(int i=1;i<word.length();i++)
        {
            if(word[i]==word[i-1])
                k+=1;
        }
        return k;
    }
};