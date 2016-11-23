#include "CC.h"

CC::CC(const Graph &g) : NonrecursiveDFS(g, 0), components(1), id(new int[V]())
{
	for (int i = 1; i < V; i++){
		if (!marked[i]){
			dfs(g, i);
			components++;
		}
	}
}

CC::~CC()
{
	delete[] id;
}

void CC::pre(const Graph& g, int v){
	id[v] = components;
}


bool CC::isConnected(int v, int w) const{
	return id[v] == id[w];
}

int CC::getComponent(int v) const{
	return id[v];
}

int CC::count() const{
	return components;
}


/* String representation */
void CC::stream_to(std::ostream &os) const{
	os << "CC: " << components << std::endl;
	for (size_t i = 0; i < V; i++){
		os << "vertex: " << i << " is in component " << id[i] << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const CC& cc){
	cc.stream_to(os);
	return os;
}