class Solution {
public:
    static int countBits(int n)
    {
        int count=0;
        while(n>0)
        {
            count++;
            n=n&(n-1);
        }
        return count;
    }

    static bool comp(int a,int b)
    {
        if(countBits(a)==countBits(b))
        {
            return a<b;
        }
        return countBits(a)<countBits(b);
    }
    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(),arr.end(),comp);
        return arr;
        
    }
};