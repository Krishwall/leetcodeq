class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<int> allrows;
        int prevCount=0;
        int ans=0;
        for(int i=0;i<bank.size();i++)
        {
            int count=0;
            for (int j=0;j<bank[0].size();j++)
            {   if(bank[i][j]=='1')
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