class Solution {
public:
    int numberOfSubstrings(string s) {
        
       int lastSeen[3]={-1,-1,-1};

        int l=0,r=0;int n=s.length();
        int count=0;

        while(r<n)
        {
            lastSeen[s[r]-'a']=r;

            if(lastSeen[0] !=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
                {count+=min(lastSeen[0], min(lastSeen[1], lastSeen[2]))+1;}
            r++;

        } 
        return count;

    }
};