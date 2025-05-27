class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int mpp[26]={0};
        int r=0,l=0,maxF=0,maxL=0;

        while(r<n)
           { mpp[s[r]-'A']++;
             maxF=max(maxF,mpp[s[r]-'A']);

             if((r-l+1)-maxF>k)
             {
                mpp[s[l]-'A']--;maxF=0;
                l++;
             }
            else{
                maxL=max(maxL,(r-l+1));
            }
            r++;
             
           }
           return maxL;
    }
};