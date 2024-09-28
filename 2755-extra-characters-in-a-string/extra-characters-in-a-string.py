class Trie_node:
    def __init__(self):
        self.children={}
        self.ew=False

    
        
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:

        n=len(s)

        root=self.build(dictionary)
        dp=[0]*(n+1)

        for i in range(n-1,-1,-1):
            dp[i]=dp[i+1]+1
            node=root
            j=i
            while j<n and s[j] in node.children:
                node=node.children[s[j]]

                if node.ew:
                    dp[i]=min(dp[i],dp[j+1])
                j+=1
        return dp[0]
    


    def build(self,dictionary):
        root=Trie_node()
        for word in dictionary:
            node=root
            for ch in word:
                if ch not in node.children:
                    node.children[ch]=Trie_node()
                node=node.children[ch]
            node.ew=True
        return root


        