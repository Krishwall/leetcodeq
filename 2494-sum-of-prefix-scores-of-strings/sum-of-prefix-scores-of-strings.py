class Trie_node:
    def __init__(self):
        self.next=[None]*26
        self.cnt=0

class Solution:
    def __init__(self):
        self.root=Trie_node()
    def insert(self,word):
        node=self.root
        for c in word:
            if node.next[ord(c)-ord("a")] is None:
                node.next[ord(c)-ord("a")]=Trie_node()
            node.next[ord(c)-ord("a")].cnt+=1
            node=node.next[ord(c)-ord("a")]
    def count(self,s):
        node=self.root
        ans=0

        for c in s:
            ans+=node.next[ord(c)-ord("a")].cnt
            node=node.next[ord(c)-ord("a")]
        return ans
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        n=len(words)
        for i in range(n):
            self.insert(words[i])
        scores=[0]*n

        for i in range(n):
            scores[i]=self.count(words[i])
        return scores
def kdsmain():
    input_data = sys.stdin.read().strip()
    lines = input_data.splitlines()
    
    num_test_cases = len(lines)
    results = []

    for i in range(num_test_cases):
        words = json.loads(lines[i])
        
        result = Solution().sumPrefixScores(words)

        results.append(json.dumps(result, separators=(',', ':')))

    with open('user.out', 'w') as f:
        for result in results:
            f.write(f"{result}\n")

if __name__ == "__main__":
    kdsmain()
    exit(0)  