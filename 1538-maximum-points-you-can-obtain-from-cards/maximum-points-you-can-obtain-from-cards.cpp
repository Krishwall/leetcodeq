class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(),sum=0;
        int lsum=0,rsum=0;
        for(int i=0;i<k;++i)
            lsum+=cardPoints[i];
       int  maxS=lsum;
        for(int i=k-1;i>=0;--i)
        {
            lsum=lsum-cardPoints[i];
            rsum=rsum+cardPoints[n-k+i];
            maxS=max(maxS,lsum+rsum);
        }
        return maxS;
    }
};