# from math import inf
from typing import List

class Solution:
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        """Modify Graph Edge Weights
        >>> s = Solution()
        >>> n = 5
        >>> edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]]
        >>> source = 0
        >>> destination = 1
        >>> target = 5
        >>> s.modifiedGraphEdges(n, edges, source, destination, target)
        [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
        """
        def dijkstra(edges: List[List[int]]) -> int:
            g = [[inf]*n for _ in range(n)]
            for a, b, w in edges:
                if w == -1:
                    continue
                g[a][b] = g[b][a] = w
            dist = [inf] * n
            dist[source] = 0
            vis = [False] * n
            for _ in range(n):
                k = -1
                for j in range(n):
                    if not vis[j] and (k == -1 or dist[k] > dist[j]):
                        k = j
                vis[k] = True
                for j in range(n):
                    dist[j] = min(dist[j], dist[k] + g[k][j])
            return dist[destination]
        
        inf = 2 * 10 ** 9
        d = dijkstra(edges)
        if d < target: 
            return []
        ok = d == target
        for e in edges:
            if e[2] > 0:
                continue
            if ok:
                e[2] = inf
                continue
            e[2] = 1
            d = dijkstra(edges)
            if d <= target:
                ok = True
                e[2] += target - d
        return edges if ok else []
