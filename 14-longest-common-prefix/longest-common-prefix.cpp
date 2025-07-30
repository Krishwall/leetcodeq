
class Solution {
    struct Node{
        int fl=false;
        Node* links[26];
        Node* get(char ch)
        {
            return links[ch-'a'];
        }
        bool containsKey(char ch){ return links[ch-'a']!=NULL;}
        void put(char ch,Node* node) {links[ch-'a']=node;}

    };

    class Trie{
        public:
        Node* root;
        Trie()
        {
            root=new Node();
        }
        int insert(string word){
            Node* node=root;
            int cnt=0;
            for(int i=0;i<word.size();++i)
            {
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                else{cnt++;}
                node=node->get(word[i]);
            }
            return cnt;
        }

        
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        int count=INT_MAX;
       if(strs.size()==1) return strs[0];
       trie.insert(strs[0]);
        for(int i=1;i<strs.size();++i)
        {   
            
            count=min(count,trie.insert(strs[i]));
        }
        return strs[0].substr(0,count);
    }
};