class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int max_min=INT_MIN;
        for(int i=0;i<informTime.size();i++)
        {
            if(informTime[i]==0)
            {
                max_min=max(max_min,getInfoTime(i,manager,informTime));
            }
        }
        return max_min;
    }

    int getInfoTime(int index,vector<int>& manager,vector<int>& informTime)
    {
        int time=0;
        while(manager[index]!=-1)
        {
            time+=informTime[index];
            index=manager[index];
        }
        time+=informTime[index];
        return time;
    }
};