class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string& a,string& b){
            return a.length()<b.length();});
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;++i)
        {   
            for(int prev=0;prev<i;++prev)
            {
                if(check(words[i],words[prev]) && 1+dp[prev]>dp[i])
                dp[i]=1+dp[prev];
            }
            if(dp[i]>maxi) maxi=dp[i];
        }
        return maxi;
    }
    bool check(string& s1,string& s2)
    {
        int n1=s1.size();
        int n2=s2.size();
        
       
        if((n1-n2) !=1) return 0;
        int first =0,second=0;

        while(first<n1)
        {
            if(s1[first]==s2[second]){first++;second++;}
            else first++;
        }
        if(first==n1 && second==n2 ) return true;
        return false;
    }
    
};