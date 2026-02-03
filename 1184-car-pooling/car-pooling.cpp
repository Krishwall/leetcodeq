class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int currPass=0;
        
        sort(trips.begin(),trips.end(),[](vector<int> a,vector<int> b)-> bool{return a[1]<b[1];});
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> busy;
        
        // <endTime,startTime,numPassenger>
        for(int i=0;i<trips.size();i++)
        {   
           
            
            
            while(!busy.empty() && busy.top()[0]<=trips[i][1])
            {
                    currPass-=busy.top()[2];
                    busy.pop();
            }

            
                busy.push({trips[i][2],trips[i][1],trips[i][0]});
                currPass+=trips[i][0];
            
        if(currPass>capacity) return false;
        }
        return true;
    }
};