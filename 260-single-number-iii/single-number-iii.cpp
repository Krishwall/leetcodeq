class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr=0;
        for (auto &a: nums)
            xr=xr^a;
        
        xr=(xr &(xr-1)) ^ xr;
        int bucket1=0, bucket0=0;
        for(auto a : nums)
        {       if (xr&a) // checks if the right most bit is set
                bucket1=bucket1^a; // if it is set then it is put into bucket 1 and is XOR'ed
                else
                bucket0=bucket0^a;

        }
        return {bucket1,bucket0};
    }
};