class Solution {
public:
    vector<int> partitionLabels(string s) {
    unordered_map<char,int> lastIndex;
    int n=s.length();
    for(int i=n-1;i>=0;i--)
    {
        if(lastIndex.find(s[i])==lastIndex.end())
            lastIndex[s[i]]=i;
    }

    int partitionEnd=0,newStart=0;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {   
        partitionEnd=max(lastIndex[s[i]],partitionEnd);
        if(i==partitionEnd)
        {
            ans.push_back(i-newStart+1);
            newStart=i+1;
        }
        
    }
        return ans;
    
    }
};