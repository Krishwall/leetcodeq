class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        return dividenconquer(s,0,n,k);

    }

    int dividenconquer(string& s,int l,int r,int k)
    {
        unordered_map<char,int> mapp;
        if(r<k) return 0;
        for(int i=l;i<r;i++)
        {
            mapp[s[i]]++;

        }
        for(int mid=l;mid<r;mid++)
        {
            if(mapp[s[mid]]>=k)
            continue;

            int midNext=mid+1;
            while(midNext<r && mapp[s[midNext]]<k)
                midNext++;

            return max(dividenconquer(s,l,mid,k),dividenconquer(s,midNext,r,k));
        }
        return (r-l);


    }
};