#include "NonrecursiveDFS.h"

#include <stack>

NonrecursiveDFS::NonrecursiveDFS(const Graph &g, int s) : DFS(g), adjIt(new std::vector<int>::const_iterator[g.V()])
{
	// to be able to iterate over each adjacency list, keeping track of which
	// vertex in each adjacency list needs to be explored next
	for (int v = 0; v < g.V(); v++)
		adjIt[v] = g.adj(v).cbegin();

	dfs(g, s);
}


NonrecursiveDFS::~NonrecursiveDFS()
{
	delete[] adjIt;
}

void NonrecursiveDFS::dfs(const Graph& g, int s){
	// depth-first search using an explicit stack
	std::stack<int> stack;
	marked[s] = true;
	stack.push(s);
	while (!stack.empty()) {
		int v = stack.top();
		pre(g, v);

		if (adjIt[v] != g.adj(v).cend()) {
			int w = *adjIt[v];
			++adjIt[v];
			// StdOut.printf("check %d\n", w);
			if (!marked[w]) {
				// discovered vertex w for the first time
				marked[w] = true;
				edgeTo[w] = v;
				stack.push(w);
				// StdOut.printf("dfs(%d)\n", w);
			}
		}
		else {
			// StdOut.printf("%d done\n", v);
			stack.pop();
		}
	}
}

void NonrecursiveDFS::stream_to(std::ostream &os) const{
	os << "NonrecursiveDFS" << std::endl;

	for (int i = 0; i < V; i++){
		os << i << "-" << edgeTo[i] << std::endl;
	}
}
