#include <stdexcept>
#include "DirectedGraph.h"


DirectedGraph::DirectedGraph(int v) : Graph(v)
{
}

DirectedGraph::DirectedGraph(std::istream &is)
{
	is >> this->v;
	is >> this->e;

	list = new std::vector<int>[v];

	int v, w;
	for (int i = 0; i < e; i++)
	{
		is >> v >> w;
		list[v].push_back(w);
	}
}


DirectedGraph::~DirectedGraph()
{
}

void DirectedGraph::addEdge(int v, int w)
{
	if (v >= V() || w >= V() || v < 0 || w < 0)
		throw(std::out_of_range("Graph addEdge"));
	list[v].push_back(w);
	++e;
}

DirectedGraph DirectedGraph::reverse() const{
	DirectedGraph R(V());
	for (int v = 0; v < V(); v++) {
		for (int w : adj(v)) {
			R.addEdge(w, v);
		}
	}
	return R;
}

void DirectedGraph::stream_to(std::ostream &os) const{
	os << "DirectedGraph" << std::endl;
	os << V() << std::endl;
	os << E() << std::endl;

	std::vector<int>::iterator it;
	for (int v = 0; v < V(); v++)
		for (const int& w : list[v])
			os << v << " -> " << w << std::endl;
}