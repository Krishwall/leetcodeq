class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a=start ^ goal;
        int cnt=0;
        while(a>0)
        {
            cnt+=a &1;
            a=a>>1;
        }
        return cnt;
    }
};