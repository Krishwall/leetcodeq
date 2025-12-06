class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n= citations.size();

        int low=0,high=n;
        int mid=0;
        int maxi=0;
        while(low<high)
        {   mid=(low+high)/2;
            if( n-mid<=citations[mid])
            {
                high=mid;
               
            }
            else
                low=mid+1;
        }

        return n-low;
    }
};