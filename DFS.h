#pragma once

#include <stack>

#include "Graph.h"

class DFS
{
protected:
	const int s;	//< source vertex
	const int V;	//< number of vertices in Graph
	bool *marked;	//< marked[v] = is there an s-v path?
	int *edgeTo;	//< edgeTo[v] = last edge on s-v path

	/**
	 * Constructor for override
	 */
	DFS(const Graph &g) :s(-1), V(g.V()), marked(new bool[V]()), edgeTo(new int[V]()){};
	/**
	 * recursive Depth First Search algorithm
	 * @param g graph
	 * @param s source vertex
	 */
	virtual void dfs(const Graph &g, int s);
	/**
	 * This can be overridden to extend the functionality of DFS. This is called at the beginning of dfs
	 * @param g graph
	 * @param s source vertex
	 */
	virtual void pre(const Graph& g, int v){};
public:
	/**
	 * Constructor for DFS algorithm. Allocates memory and starts the dfs algorithm
	 * @param g graph
	 * @param s source vertex
	 */
	DFS(const Graph &g, int s);

	/**
	 * Freeing up memory
	 */
	virtual ~DFS();

	/** If a vertex has been visited during the search
	 * @param v vertex
	 * @return true if v is visited during the search
	 */
	bool hasPathTo(int v) const;

	/**
	 * Returns a path from s to v
	 * @param v path to
	 * @return path from s source to v
	 */
	const std::deque<int> pathTo(int v) const;
	/**
	 * Writes every path from s to every vertex
	 * @param os OutputStream to write to
	 */
	virtual void stream_to(std::ostream &os) const;
};

/**
 * Writes the dfs to the given OutputStream
 * @param os OutputStream
 * @param g graph
 * @return OutputStream
 */
std::ostream& operator<<(std::ostream& os, const DFS& dfs);
