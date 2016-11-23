#include "Graph.h"

#include <stdexcept>
#include <iostream>

Graph::Graph(int v) : v(v), list(new std::vector<int>[v])
{
}

Graph::Graph(std::istream &is)
{
	is >> this->v;
	is >> this->e;

	list = new std::vector<int>[v];

	int v, w;
	for (int i = 0; i < e; i++)
	{
		if (e > 100){
			int percent = e / 100;
			if (i % percent == 0)
				std::cout << i / percent << "%" << std::endl;
		}
		
		is >> v >> w;
		list[v].push_back(w);
		list[w].push_back(v);
	}
}

Graph::~Graph(){
	delete[] list;
}

int Graph::V() const{
	return this->v;
}

int Graph::E() const{
	return this->e;
}

int Graph::degree(int v) const{
	return list[v].size();
}

int Graph::maxDegree() const{
	int max = -1;
	for (int i = 0; i < V(); i++)
		if (degree(i) > max)
			max = degree(i);
	return max;
}


const std::vector<int>& Graph::adj(int v) const{
	return list[v];
}

void Graph::addEdge(int v, int w){
	if (v >= V() || w >= V() || v < 0 || w < 0)
		throw(std::out_of_range("Graph addEdge"));
	list[v].push_back(w);
	list[w].push_back(v);
	++e;
}
void Graph::stream_to(std::ostream &os) const{
	os << "Graph" << std::endl;
	os << V() << std::endl;
	os << E() << std::endl;

	for (int v = 0; v < V(); v++)
		for (const int& w : list[v])
			os << v << " - " << w << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Graph& g){
	g.stream_to(os);
	return os;
}