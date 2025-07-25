class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
        return 0;
        vector<bool> nums(n,1);
        
        for(int i=2;i*i<n;++i)
        {   if(nums[i]==1)
              {  
                int c=2;
                while(c*i<n)
                {
                    nums[i*c]=0;
                    c++;
                }
               }
        }
        return accumulate(nums.begin(),nums.end(),0)-2;}
        
};