class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int n=colors.size();
        for(int i=0;i<n-1;i++)
        {   
            
            time+=neededTime[i];
            int maxi=neededTime[i];
            while(colors[i]==colors[i+1] && i+1<n)
            {
                maxi=max(maxi,neededTime[i+1]);
                time+=neededTime[i+1];
                i++;
            }
            time-=maxi;
            

            
        }
        return time;
    }
};