class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,n=fruits.size(),k=2,maxL=0;
        map<int,int> mpp;

        while(r<n)
        {
            mpp[fruits[r]]++;
            if(mpp.size()>k)
            {
                
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0)
                    mpp.erase(fruits[l]);

                    l++;
                
            }
            if(mpp.size()<=k ) maxL=max(maxL,r-l+1);
            r++;

        }
        return maxL;
    }
};