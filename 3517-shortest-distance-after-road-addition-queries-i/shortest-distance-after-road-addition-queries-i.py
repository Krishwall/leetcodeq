class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        graph ={i:[] for i in range(n)}
        for i in range(n-1):
            graph[i].append(i+1)
        
        # print(graph)

        def helper(graph):
            visited=[False]*n
            queue=deque([(0,0)])
            visited[0]=True

            while queue:
                node,dist=queue.popleft()
                if node==n-1:
                    return dist
                for neighbour in graph[node]:
                    if not visited[neighbour]:
                        visited[neighbour]=True
                        queue.append((neighbour,dist+1))
        answer=[]

        for u,v in queries:
            graph[u].append(v)
            answer.append(helper(graph))
        return answer
                


                    



