class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int m=*max_element(piles.begin(),piles.end());
        if (n==h)
            return m;
        
        int b=1,end=m,tt;
        while (b<end)
            {tt=0;
                int mid=(b+end)/2;
                for (int i=0;i<n;++i)
                 tt+=( piles[i]-1)/mid +1 ;
                if (tt<=h)
                    end=mid;
                else
                    b=mid+1;
            }
        return b;    
        
    }
};