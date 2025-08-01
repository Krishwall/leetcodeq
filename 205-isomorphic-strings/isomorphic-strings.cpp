class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> st_map, ts_map;

        for(int i = 0; i < s.length(); ++i) {
            char sc = s[i];
            char tc = t[i];

            if(st_map.count(sc) && st_map[sc] != tc)
                return false;

            if(ts_map.count(tc) && ts_map[tc] != sc)
                return false;

            st_map[sc] = tc;
            ts_map[tc] = sc;
        }

        return true;
    }
};
