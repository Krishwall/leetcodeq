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
    int findMaximumXOR(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int bitLength = 0;
        while (bitLength<31 && (1 << bitLength) <= maxVal) ++bitLength;

        Trie trie(bitLength);

        for (int num : nums)
            trie.insert(num);

        int maxXor = 0;
        for (int num : nums)
            maxXor = max(maxXor, trie.getMax(num));

        return maxXor;
    }
};
