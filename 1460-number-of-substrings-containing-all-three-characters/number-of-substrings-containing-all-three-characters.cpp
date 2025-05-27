class Solution {
public:
    int numberOfSubstrings(string s) {
        
        vector<int> lastSeen(3,-1);

        int l=0,r=0;int n=s.length();
        int count=0;

        while(r<n)
        {
            lastSeen[s[r]-'a']=r;

            if(lastSeen[0] !=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
                {count+= *min_element(lastSeen.begin(),lastSeen.end())+1;}
            r++;

        } 
        return count;

    }
};