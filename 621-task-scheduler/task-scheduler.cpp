class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxi=0;
        for(char ch:tasks){
            freq[ch-'A']++;
            maxi=max(maxi,freq[ch-'A']);
        }
        int time=(maxi-1)*(n+1);
        for(int i:freq){
            if(i==maxi){
                time++;
            }
        }
        return max(time,(int)tasks.size());
    }
};

// Visual intuition

// Example:

// tasks = [A,A,A,B,B,B], n = 2


// maxi = 3  

// Two tasks have max frequency

// Skeleton:

// A _ _  A _ _         (maxi-1)*(n+1)


// Fill with B:

// A B _  A B _


// Final row:

// A B


// Total = 8