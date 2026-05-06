class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> maxRanges(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int left =max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            maxRanges[left]=max(maxRanges[left],right);
        }

        int endcurrent_window=0;
        int maxto_the_right=0;
        int i=0,tapscount=0;

        while( endcurrent_window<n)
        {
            while(i<= endcurrent_window)

            {
                maxto_the_right=max(maxto_the_right,maxRanges[i]);
                i++;
            }
            if(maxto_the_right<=endcurrent_window)
                return -1;

            endcurrent_window=maxto_the_right;
            tapscount++;
        }
        return tapscount;



        


    }
    
};