class Solution {
public:
    int trap(vector<int>& height) {
        int waterTrap=0;int lMax,rMax=0,l=0,r=height.size()-1;
        lMax=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(lMax>height[l])
                waterTrap+=lMax-height[l];
                else
                    lMax=height[l];
                l++;
            }
            else
            {
                if(rMax>height[r])
                waterTrap+=rMax-height[r];
                else
                    rMax=height[r];
                r--;
            }
             
        }
        return waterTrap;
    }
};