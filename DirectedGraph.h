#pragma once
#include "Graph.h"

/** Directed Graph class with adjacency list representation
 * @author Dawars
 */
class DirectedGraph :
	public Graph
{
public:
	/**
	 * v - number of Vertices
	 */
	DirectedGraph(int v);

	/**
	 * Constructs an empty Graph from an InputStream with format:
	 * |V|
	 * |E|
	 * v1 w1
	 * v2 w2\n
	 * v->w
	 * @param is InputStream
	 */
	DirectedGraph(std::istream &is);

	~DirectedGraph();

	/**
	 * Add directed v->w edge to this graph
	 * @param v start vertex of edge
	 * @param w end of edge
	 */
	void addEdge(int v, int w) override;

	/**
	 * String representation
	 * @param os OutputStream to write to
	 */
	void stream_to(std::ostream &os) const override;

	/**
	* Returns the reverse of the digraph.
	* @return the reverse of the digraph
	*/
	DirectedGraph reverse() const;

};

