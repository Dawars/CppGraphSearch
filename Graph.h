#pragma once

#include <fstream>
#include <vector>
#include <set>
#include <iostream>

/** Graph class with adjacency list representation
 * @author Dawars
 */
class Graph {
protected:
	int v; 		//< Number of vertices
	int e = 0;	//< Number of edges

	/**
	 * Adjacency list to store the graph
	 */
	std::vector<int> *list;

	/**
	 * Empty protected constructor for inheritance
	 */
	Graph() {};
public:
	/**
	 * Constructs an empty Graph with v Vertices
	 * @param v number of vertices
	 */
	Graph(int v);

	/**
	 * Constructs an empty Graph from an InputStream with format:
	 * |V|
	 * |E|
	 * v1 w1
	 * v2 w2
	 * @param is InputStream
	 */
	Graph(std::istream &is);

	virtual ~Graph();

	/**
	 * Add v-w edge to this graph
	 * @brief Add v-w edge
	 * @param v one end of edge
	 * @param w other end of edge
	 */
	virtual void addEdge(int v, int w);

	/**
	 * Gives the adjacent vertices to v
	 * @param v vertex
	 * @return vector of adjacent vertices
	 */
	const std::vector<int> &adj(int v) const;

	/**
	 * Number of vertices in this graph
	 * @return number of vertices
	 */
	int V() const;

	/**
	 * Number of edges in this graph
	 * @return number of edges
	 */
	int E() const;

	/**
	 * Writes the string representation to an OutputStream
	 * @param os OutputStream to write to
	 */
	virtual void stream_to(std::ostream &os) const;

	/** Returns the degree of a vertex
	 * @param v vertex
	 * @return degree of v
	 */
	int degree(int v) const;

	/**
	 * Returns the max degree in the graph
	 * @return max degree in graph
	 */
	int maxDegree() const;
};

/**
 * Writes the graph to the given OutputStream
 * @param os OutputStream
 * @param g graph
 * @return OutputStream
 */
std::ostream &operator<<(std::ostream &os, const Graph &g);
