class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)return false;

        map<int,int> hash;
        for(int card:nums)
        hash[card]++;

        auto it=hash.begin();

        while(it!=hash.end())
        {
            if(it->second==0)
            {++it;continue;}
            int start=it->first;
            int count=it->second;
            for(int i=0;i<k;++i)
            {
                if(hash[start+i]<count)return false;
                hash[start+i]-=count;
            }
            ++it;


        }
        return true;
    }
};