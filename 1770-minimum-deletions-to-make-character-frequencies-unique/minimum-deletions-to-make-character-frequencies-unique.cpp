class Solution {
public:
    
    int minDeletions(string s) {
        
        vector<int> freq(26,0);
        for(auto& a:s)
        {
            freq[a-'a']++;

        }
        int deletions =0;
        sort(freq.begin(),freq.end(),greater<int>());
        
        int i=1;
        for( ;i<26;i++)
        {   
           
            while(freq[i]>0 && freq[i]>=freq[i-1] )
            {
                freq[i]--;
                deletions++;
                
            }
        }
        return deletions;
    }
       
    
};