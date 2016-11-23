#pragma once

#include "NonrecursiveDFS.h"

class CC : protected NonrecursiveDFS {
private:
	int *id;            //< Stores which component a vertex belongs to
	int components = 0; //< Number of components
protected:
	void pre(const Graph &g, int v) override;    //< sets the component for every vertex

public:
	CC(const Graph &g);

	~CC();

	/**
	 * If two vertices are in the same component
	 * @param v vertex
	 * @param w vertex
	 * @return if v and w are in the same component
	 */
	bool isConnected(int v, int w) const;

	/**
	 * Returns the id of the component which v is in
	 * @param v vertex
	 * @return component id of v
	 */
	int getComponent(int v) const;

	/**
	 * Returns the number of components
	 *	@return number of components
	 */
	int count() const;

	void stream_to(std::ostream &os) const override;
};

std::ostream &operator<<(std::ostream &os, const CC &dfs);