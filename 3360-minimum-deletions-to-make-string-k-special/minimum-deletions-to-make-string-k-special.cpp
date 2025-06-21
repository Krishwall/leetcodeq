class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> freq;

        for(auto&ch : word)
        freq[ch]++;

        int res=word.length();

        for(auto &pair : freq)
        {
         int deleted=0;
            for(auto &pair2:freq)
            {
                if(pair.second>pair2.second)
                    {deleted+=pair2.second;}

                else if(pair2.second-pair.second>k)
                    deleted+=pair2.second-(pair.second+k);
            }
            res=min(res,deleted);
        }


        return res;
    }
};


