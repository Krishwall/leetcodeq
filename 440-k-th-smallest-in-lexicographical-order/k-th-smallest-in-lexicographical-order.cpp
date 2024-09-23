#include<algorithm>
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr=1;
        k-=1;
        int step;

        while(k>0)
        {
             step=countsteps(n,curr,curr+1);

            if (step<=k)
            {
                k-=step;
                curr+=1;
            }
            else
            {
                curr*=10;
                k-=1;
            }


        }
        return curr;
    }
        int countsteps(int n,long prefix1,long prefix2)
        {
            int steps=0;
            while(prefix1<=n){
                steps+=min(static_cast<long>(n+1),prefix2)-prefix1;
                prefix1*=10;
                prefix2*=10;

            }
            return steps;

        }

        
    
};