class Solution {
public:
    vector<int> findSubstring(string& s, vector<string>& words) {
        vector<int> ans;
        int wordLength=words[0].length();
        int wordCount=words.size();
        int n=s.size();
        unordered_map<string, int> originalCount;
        for(int i=0;i<wordCount;i++)
        {
            originalCount[words[i]]++;
        }

        for(int offset=0;offset<wordLength;offset++)
        {
            int size=0;

            unordered_map<string, int> seen;

            for(int i=offset;i+wordLength<=n;i+=wordLength)
                {
                    string sub=s.substr(i,wordLength);

                    auto itr=originalCount.find(sub);

                    if(itr==originalCount.end())
                       { seen.clear();
                        size=0;
                        continue;}

                    ++seen[sub];
                    ++size;

                    while(seen[sub]>itr->second){

                        string first=s.substr(i-(size-1)*wordLength,wordLength);
                        --seen[first];
                        --size;
                    }


                    if(size== wordCount)
                        ans.push_back(i-(size-1)*wordLength);

                }

        }

        return ans;
    }
};