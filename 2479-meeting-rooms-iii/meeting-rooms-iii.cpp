class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort (meetings.begin(),meetings.end());
        
        priority_queue<int,vector<int>,greater<int>> freeRoom;

        for(int i=0;i<n;i++)
            freeRoom.push(i);
        
        
        

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>endTimes;
        vector<int> timesUsed(n,0);
        for(int i=0;i<meetings.size();i++)
        {
            
            while(!endTimes.empty() && endTimes.top().first <= meetings[i][0])
            {
                freeRoom.push(endTimes.top().second);
                endTimes.pop();
                
               
            }

            if(!freeRoom.empty())
            {
                int rn=freeRoom.top();
                freeRoom.pop();
                timesUsed[rn]++;
                
                endTimes.push({meetings[i][1],rn});
            }
            else

               { auto [finish,room]=endTimes.top();
                endTimes.pop();
                endTimes.push({finish+meetings[i][1]-meetings[i][0],room});
                timesUsed[room]++;
                }

        }
        int maxMeet=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(timesUsed[i]>maxMeet)
            {
                maxMeet=timesUsed[i];
                ans=i;
            }
        }

        return ans;

    }
};