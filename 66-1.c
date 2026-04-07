from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.V = vertices

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def is_cyclic_util(self, v, visited, rec_stack):
        # Mark current node as visited and add to recursion stack
        visited[v] = True
        rec_stack[v] = True

        # Recur for all neighbors
        for neighbour in self.graph[v]:
            # If neighbor is not visited, recurse
            if not visited[neighbour]:
                if self.is_cyclic_util(neighbour, visited, rec_stack):
                    return True
            # If neighbor is already in recursion stack, cycle found
            elif rec_stack[neighbour]:
                return True

        # Backtrack: remove the vertex from recursion stack
        rec_stack[v] = False
        return False

    def is_cyclic(self):
        visited = [False] * self.V
        rec_stack = [False] * self.V
        
        # Call the utility function for every node (handles disconnected graphs)
        for node in range(self.V):
            if not visited[node]:
                if self.is_cyclic_util(node, visited, rec_stack):
                    return "YES"
        return "NO"

# Example Usage:
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 0) # Cycle: 0 -> 1 -> 2 -> 0
g.add_edge(2, 3)

print(g.is_cyclic())
