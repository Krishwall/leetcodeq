class Solution {
public:
    int climbStairs(int n) {
        if (n<=2)
        return n;

    int a=1,b=2;
    int temp;
    for (int  i=3;i<=n;++i)
        {   temp=a;
            a=b;
            b=temp+b;
        }
    return b;
    }
};