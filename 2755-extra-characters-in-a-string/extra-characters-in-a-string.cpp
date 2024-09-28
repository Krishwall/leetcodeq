class Trie_Node{
    public:
    unordered_map<char,Trie_Node*> children;
    bool ew;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        int n=s.length();

        auto root=build(dictionary);
        vector<int> dp(n+1,0);

        for (int i=n-1;i>-1;--i)
        {
            dp[i]=dp[i+1]+1;

            auto node=root;
            int j=i;
            while (j<n && node->children.find(s[j])!=node->children.end())
                {
                    node=node->children[s[j]];
                    if (node->ew)
                    dp[i]=min(dp[i],dp[j+1]);
                    j+=1;
                }
        
            
        }
        return dp[0];

    }

    Trie_Node* build(vector<string>& dictionary){
        auto root=new Trie_Node();

        for(auto& word: dictionary){
            auto node=root;
            for (auto&c: word){
                if (node->children.find(c)==node->children.end())
                {
                    node->children[c]= new Trie_Node();
                }
                node=node->children[c];
            }
            node->ew=true;
        }
        return root;
    }
};