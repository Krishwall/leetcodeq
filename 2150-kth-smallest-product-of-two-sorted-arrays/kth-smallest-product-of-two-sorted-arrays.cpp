class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low=-1e10;
        long long high=1e10;
        int n1=nums1.size();
        int n2=nums2.size();

        int pos1=0,pos2=0;

        while(pos1<n1 && nums1[pos1]<0) pos1++;
        while(pos2<n2 && nums2[pos2]<0) pos2++;

        while(low<=high)
        {
            long long count =0;
            long long mid=(low+high)>>1;


            for(int i1=0,i2=pos2-1;i1<pos1 && i2>=0;)
            {
               if(1ll*nums1[i1]*nums2[i2]>mid)
                {
                    i1++;
                }
                else{
                    count+=pos1-i1;
                    i2--;
                }
            }


            for(int i1=pos1,i2=n2-1;i1<n1 && i2>=pos2;)
            {
               if(1ll*nums1[i1]*nums2[i2]>mid)
                {
                    i2--;
                }
                else{
                    count+=i2-pos2+1;
                    i1++;
                }
            }


            for(int i1=0,i2=pos2;i1<pos1 && i2<n2;)
            {
               if(1ll*nums1[i1]*nums2[i2]>mid)
                {
                    i2++;
                }
                else{
                    count+=n2-i2;
                    i1++;
                }
            }


            for(int i1=pos1,i2=0;i1<n1 && i2<pos2;)
            {
               if(1ll*nums1[i1]*nums2[i2]>mid)
                {
                    i1++;
                }
                else{
                    count+=n1-i1;
                    i2++;
                }
            }
            if(count<k) low=mid+1;
            else  high=mid-1;
            
        }
        
        return low;
    }

    

};