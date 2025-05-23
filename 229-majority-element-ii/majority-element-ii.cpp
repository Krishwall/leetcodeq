class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN;
        int n=nums.size();
        int ele2=INT_MIN;
        vector<int> ans;
        // for(int i=0;i<n;++i)
        // {
        //     if(ele1!=nums[i])
        //         {
        //             ele2=nums[i];
        //             idx=i;
        //             break;
        //         }
        // }
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==ele1)
                cnt1+=1;
            else if(nums[i]==ele2)
                cnt2+=1;
            else if (cnt1==0 && nums[i]!=ele2)
              {  ele1=nums[i];cnt1=1;}
            else if (cnt2==0 && nums[i]!=ele1)
                {ele2=nums[i];cnt2=1;}
            else {cnt1--;cnt2--;}
        }
       int min =n/3;
        cnt1=0;cnt2=0;
        for(int i=0;i<n;++i)
            {if( nums[i]==ele1) cnt1++;
            if (nums[i]==ele2) cnt2++;}
        if (cnt1>min) ans.push_back(ele1);
        if (cnt2>min) ans.push_back(ele2);
        return ans;
        
    }
};