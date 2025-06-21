class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        for(auto &a:word)
        {
            freq[a-'a']++;
        }
        int deleted=0;
       
        sort(freq.begin(),freq.end());
        int ans=word.length();
        for (int i=0;i<26;++i)
        {
            int result =deleted;int minFreq=freq[i];

            for(int j=25;j>i;--j)
            {
                if(freq[j]-minFreq<=k) break;
                result+=freq[j]-(minFreq+k);
            }
            ans=min(ans,result);
            deleted+=freq[i];
        }
        return ans;
    }
};


