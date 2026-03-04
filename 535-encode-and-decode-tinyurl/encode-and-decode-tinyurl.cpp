class Solution {
private:

    unordered_map<string,string> longToShort;
    unordered_map<string,string> shortToLong;
    int id = 1;

    string idToShortUrl(int n)
    {
        char map[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string shorturl;

        while(n)
        {
            shorturl.push_back(map[n%62]);
            n/=62;
        }

        reverse(shorturl.begin(),shorturl.end());
        return shorturl;
    }

public:

    string encode(string longUrl) {

        if(longToShort.count(longUrl))
            return longToShort[longUrl];

        string shortUrl = idToShortUrl(id++);

        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;

        return shortUrl;
    }

    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};