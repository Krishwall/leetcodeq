class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int low=0,high=arr.size()-1;
        int missing=0;
        if(k<arr[0]) return k;
        while(low<=high)
        {
            int mid=(low+high)/2;
             missing=arr[mid]-(mid+1);
            if(missing<k)
                low=mid+1;
            else high=mid-1;

        }
        missing=arr[high]-(high+1);
        return arr[high] + k-missing; // high +k+1 or low +k
        
    }
};