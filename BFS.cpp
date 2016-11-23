#include "BFS.h"

#include <deque>

BFS::BFS(const Graph &g, int s) :s(s), V(g.V()), marked(new bool[V]()), edgeTo(new int[V]()), distTo(new int[V]())
{
	bfs(g, s);
}


BFS::~BFS()
{
	delete[] marked;
	delete[] edgeTo;
	delete[] distTo;
}

void BFS::bfs(const Graph &g, int s){
	std::deque<int> queue;

	marked[s] = true;
	queue.push_back(s);

	while (!queue.empty()){
		int v = queue.front();
		queue.pop_front();
		for (const int w : g.adj(v))
		{
			if (!marked[w]){
				queue.push_back(w);
				marked[w] = true;
				edgeTo[w] = v;
				distTo[w] = distTo[v] + 1;
			}
		}
	}
}

bool BFS::hasPathTo(int v) const
{
	return marked[v];
}

const std::deque<int> BFS::pathTo(int v) const{
	std::deque<int> path;
	if (!hasPathTo(v)) return path;
	for (int x = v; x != s; x = edgeTo[x])
		path.push_front(x);
	path.push_front(s);
	return path;
}

void BFS::stream_to(std::ostream &os) const{
	os << "BFS:" << std::endl;
	os << "source vertex: " << s << std::endl;
	for (size_t v = 0; v < V; v++) {
		os << "dist to " << v << " is " << distTo[v] << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const BFS& bfs){
	bfs.stream_to(os);
	return os;
}