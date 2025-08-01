class Solution {
public:
    bool isIsomorphic(const string &s, const string &t)
    {
        char map_s2t[128] = {0};
        char map_t2s[128] = {0};

        for (int i = 0; i < s.size(); i++) {
            const char item_s2t = s[i];
            const char item_t2s = t[i];

            if (!map_s2t[item_s2t])
                map_s2t[item_s2t] = item_t2s;

            if (!map_t2s[item_t2s])
                map_t2s[item_t2s] = item_s2t;

            if (map_s2t[item_s2t] != item_t2s || map_t2s[item_t2s] != item_s2t)
                return false;
        }    
    
        return true;
    }
};