class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low=-1e10;
        long long high=1e10;
        int n1=nums1.size();
        int n2=nums2.size();
        while(low<=high)
        {
            long long count =0;
            long long mid=(low+high)>>1;

            for(int i=0;i<n1;++i)
            {
                count+=totalEle(nums2,nums1[i],mid); // finds total elements having product less than mid
            }
            if(count<k) low=mid+1;
            else if(count>=k) high=mid-1;
            
        }
        
        return low;
    }

    long long totalEle(vector<int>& nums2,long long e1,long long& prod) {
        
        int low=0;int high=nums2.size()-1;
        int n2=high+1;
        while(low<=high){
            int mid=(high+low)>>1;

            if((e1>=0 && e1*nums2[mid]<=prod) || (e1<0 && e1*nums2[mid]>prod))
            {
                low=mid+1;
            }
            else
            {high=mid-1;}
        }
            if(e1>=0) return low;
            else return n2-low;
      
    }

};