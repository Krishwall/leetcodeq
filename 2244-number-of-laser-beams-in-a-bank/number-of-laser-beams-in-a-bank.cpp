class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
       
        int prevCount=0;
        int ans=0;
        for(int i=0;i<bank.size();i++)
        {
            int count=0;
            for (auto& a:bank[i])
            {   if(a=='1')
                count++;
            }
            if(count)
            {
                ans+=count*prevCount;
                prevCount=count;
            }
            

        }
        

        return ans;
    }
};