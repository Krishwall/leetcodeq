class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int maxUnique=0;
        unordered_set<char> aa;
        for(auto& a:s)
        {
            aa.insert(a);
        }
        maxUnique=aa.size();
        // delete (aa);

        unordered_map<int,int> countMap;
        int result=0;
        for(int currUnique=1;currUnique<=maxUnique;currUnique++)
        {   
            countMap.clear();
            int start=0,end=0,ch=0,unique=0,countAtLeastK=0;

            while(end<s.size())
            {
                if(unique<=currUnique)
                {
                    ch=s[end]-'a';
                    if(countMap[ch]==0)
                        unique++;
                    countMap[ch]++;

                    if(countMap[ch]==k)
                        countAtLeastK++;
                    end++;
                }
                else
                {
                    ch=s[start]-'a';
                    if(countMap[ch]==k)
                        countAtLeastK--;
                    
                    countMap[ch]--;
                    if(countMap[ch]==0)
                    unique--;
                    start++;
                }

                if(unique==currUnique && unique==countAtLeastK)
                    result=max(end-start,result);
            }
        }

        return result;

    }

    

    
};