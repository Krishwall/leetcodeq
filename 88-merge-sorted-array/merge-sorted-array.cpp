class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r=m+n-1,la=m-1,lb=n-1;
        while(la>=0 && lb>=0)
        {
        if(nums1[la] > nums2[lb])
          nums1[r--]=nums1[la--];
          else
          nums1[r--]=nums2[lb--];
        
               
    }
        while(lb>=0)
            nums1[r--]=nums2[lb--];
        }
};