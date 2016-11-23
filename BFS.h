#pragma once

#include <stack>

#include "Graph.h"

class BFS
{
private:
	const int s;	//< source vertex
	const int V;	//< number of vertices in Graph
	bool *marked;	//< marked[v] = is there an s-v path?
	int *edgeTo;	//< edgeTo[v] = last edge on s-v path
	int *distTo;	//< distTo[v] = distance: on s-v path
protected:
	/**
	 * Constructor for override
	 */
	BFS(const Graph &g) :s(0), V(g.V()){};
	/**
	 * Internal Breadth First Search algorithm
	 * @param g graph
	 * @param s source vertex
	 */
	void bfs(const Graph &g, int s);
public:
	/**
	 * Constructor for BFS algorithm. Allocates memory and starts the bfs algorithm
	 * @param g graph
	 * @param s source vertex
	 */
	BFS(const Graph &g, int s);

	/**
	 * Freeing up memory
	 */
	virtual ~BFS();

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
std::ostream& operator<<(std::ostream& os, const BFS& bfs);
