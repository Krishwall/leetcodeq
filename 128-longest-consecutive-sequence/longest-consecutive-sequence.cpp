class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;int longest=0;
        
       
        for(int num:nums)
            st.insert(num);
        
        for( int it: st)
        {
            if(st.find(it-1)== st.end())
            {
                int cnt =1;
                int x=it;
                while(st.find(it+1) !=st.end())
                   {it++; cnt++;}
                longest=max(longest,cnt);
            }
        }return longest;

    }
};