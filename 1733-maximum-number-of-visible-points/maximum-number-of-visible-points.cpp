class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        
        vector<double> indexAngle;
        int same =0;
        for (auto &p : points) {
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];

            if (dx == 0 && dy == 0) {
                same++;
                continue;
            }

            double ang = atan2(dy, dx) * 180.0 / M_PI;
            indexAngle.push_back(ang);
        }
        sort(indexAngle.begin(),indexAngle.end());
        int m=indexAngle.size();
        for (int i = 0; i < m; i++) {
            indexAngle.push_back(indexAngle[i] + 360);
        }

        int l=0,r=0;
        
        int maxPoints=0;
        for(auto a:indexAngle)
            cout<<a<<"  ";
        int n=indexAngle.size();
        while(r<n)
        {
            if((indexAngle[r]-indexAngle[l])>angle)
                {l++;}
            
                maxPoints=max(maxPoints,r-l+1);
            r++;
        }
        // cout<<atan(1/0.001);
        return maxPoints+same;

    }
};