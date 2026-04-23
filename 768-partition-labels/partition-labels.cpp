class Solution {
public:
    vector<int> partitionLabels(string s) {
    // unordered_map<char,int> lastIndex;
    vector<int> lastIndex(26,0);
    vector<int> firstIndex(26,0);
    int partitionEnd=0,partitionStart=0;

    int n=s.length();
    for(int i=0;i<n;i++)
    {
        
            lastIndex[s[i]-'a']=i;
    }

    vector<int> ans;
    for(int i=0;i<s.length();i++)
    {   
        if(!firstIndex[s[i]-'a'])
            firstIndex[s[i]-'a']=i;

        if(partitionEnd<firstIndex[s[i]-'a'])
        {
            ans.push_back(partitionEnd-partitionStart+1);
            partitionStart=i;
            partitionEnd=i;
        }

        partitionEnd=max(partitionEnd,lastIndex[s[i]-'a']);


    }
        if(partitionEnd-partitionStart+1>0)
            ans.push_back(partitionEnd-partitionStart+1);
        return ans;
    
    }
};