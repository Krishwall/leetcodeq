class Solution {
    struct Node {
        Node* links[2] = {nullptr, nullptr};

        Node* get(int bit) { return links[bit]; }
        bool containsKey(int bit) { return links[bit] != nullptr; }
        void put(int bit, Node* node) { links[bit] = node; }
    };

    class Trie {
        Node* root;
        int maxBits;

    public:
        Trie(int bits) : maxBits(bits) {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;
            for (int i = maxBits - 1; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (!node->containsKey(bit)) {
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int getMax(int num) {
            Node* node = root;
            int maxNum = 0;
            for (int i = maxBits - 1; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (node->containsKey(1 - bit)) {
                    maxNum |= (1 << i);
                    node = node->get(1 - bit);
                } else {
                    node = node->get(bit);
                }
            }
            return maxNum;
        }
    };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int maxi=0;
        for(int i=0;i<queries.size();++i)
        {
            queries[i].push_back(i);
            maxi=max(maxi,queries[i][0]);

        }
         int maxVal=max(*max_element(nums.begin(),nums.end()),maxi) ;
        
         int bitLength = 0;
         while (bitLength<31 && (1 << bitLength) <= maxVal) ++bitLength;

        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),[](vector<int>& query1,vector<int>& query2){
            return query1[1]<query2[1];
        });
        
        Trie trie(bitLength);
        vector<int> ans(queries.size(),-1);
        int j=0;
        for(int i=0;i<queries.size();++i)
        {   
            
            
            
            bool fl=false;
            
            while(j<nums.size() && nums[j]<=queries[i][1])
            {    
                trie.insert(nums[j]);fl=true;++j;
                
            }
            
            if(j!=0)
            ans[queries[i][2]]=trie.getMax(queries[i][0]);
            
        }
        return ans;
    }
};