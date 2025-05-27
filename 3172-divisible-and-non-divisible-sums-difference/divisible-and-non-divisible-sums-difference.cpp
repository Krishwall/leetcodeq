class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int sum= m*(n/m)*(n/m + 1) ;
        return n*(n+1)/2 - sum;
            }
};