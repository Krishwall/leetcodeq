class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<int> allrows;
        for(int i=0;i<bank.size();i++)
        {
            int count=0;
            for (int j=0;j<bank[0].size();j++)
            {   if(bank[i][j]=='1')
                count++;
            }
            if(count)
            allrows.push_back(count);

        }
        int ans=0;
        for(int i=1;i<allrows.size();i++)
        ans+=allrows[i]*allrows[i-1];

        return ans;
    }
};