#include "DFS.h"

#include <iostream>
DFS::DFS(const Graph &g, int s) : s(s), V(g.V()), marked(new bool[V]()), edgeTo(new int[V]())
{
	dfs(g, s);
}

DFS::~DFS()
{
	delete[] marked;
	delete[] edgeTo;
}

void DFS::dfs(const Graph &g, int v)
{
	marked[v] = true;
	pre(g, v);
	std::vector<int> adj = g.adj(v);
	for (const int w : adj){
		if (!marked[w])
		{
			edgeTo[w] = v;
			dfs(g, w);
		}
	}
}

bool DFS::hasPathTo(int v) const
{
	return marked[v];
}

const std::deque<int> DFS::pathTo(int v) const{
	std::deque<int> path;
	if (!hasPathTo(v)) return path;
	for (int x = v; x != s; x = edgeTo[x])
		path.push_front(x);
	path.push_front(s);
	return path;
}

void DFS::stream_to(std::ostream &os) const{
	os << "DFS:" << std::endl;
	for (size_t v = 0; v < V; v++) {
		if (hasPathTo(v)) {
			os << s << " to " << v << std::endl;
			const std::deque<int> path = pathTo(v);
			for (const int& x : path){
				if (x == s) os << x;
				else        os << "-" << x;
			}
			os << std::endl;
		}
		else {
			os << s << " to " << v << ":  not connected" << std::endl;
		}
	}
}


std::ostream& operator<<(std::ostream& os, const DFS& dfs){
	dfs.stream_to(os);
	return os;
}