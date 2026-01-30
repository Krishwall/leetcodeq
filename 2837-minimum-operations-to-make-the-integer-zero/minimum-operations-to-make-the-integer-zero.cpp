class Solution {

public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2>num1) return -1;
        int k=0;
        while(true)
        {   
            long long x=num1-static_cast<long long>(num2)*k;
            if(x<k)
            return -1;

            if(k>=__builtin_popcountll(x)) // 1101 total count wil return 3, 2^3 +2^2 + 2^0
            {
                return k;
            }

            k++;
        }

    }
};