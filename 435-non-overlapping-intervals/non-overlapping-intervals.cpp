class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=1;
        int limit=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;++i)
        {
            if(intervals[i][0]>=limit)
                {limit=intervals[i][1];
                count++;}
        }
        return (n-count);
    }
   static bool comp(vector<int>& a , vector<int>& b)
    {
        if (a[1]<b[1]) return true;
        return false;
    }
};