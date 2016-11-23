#pragma once
#include "DFS.h"

class NonrecursiveDFS :
	public DFS
{
protected:
	NonrecursiveDFS(const Graph &g) : DFS(g){};
	void dfs(const Graph &g, int s) override;
	void pre(const Graph &g, int v){};
private:
	/**
	 * Iterator array for every vertex in G graph to keep track of the next vertex to visit
	 */
	std::vector<int>::const_iterator *adjIt;
public:
	NonrecursiveDFS(const Graph &g, int s);
	virtual ~NonrecursiveDFS();
	void stream_to(std::ostream& os) const override;
};

