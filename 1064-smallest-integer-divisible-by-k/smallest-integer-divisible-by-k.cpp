class Solution {
public:
    int smallestRepunitDivByK(int& k) {
        
        if(k&1==0) return -1;
        if(k%5==0) return -1;
        int i=1;
        int rem=0;
        while(i<=k){
            rem=(rem*10+1)% k;
            if(rem==0) return i;
            i++;
        }

        return -1;
    }
};