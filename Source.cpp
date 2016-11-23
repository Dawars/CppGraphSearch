#include <iostream>
#include <fstream>
#include <vector>

#include "Graph.h"
#include "DirectedGraph.h"
#include "DFS.h"
#include "NonrecursiveDFS.h"
#include "BFS.h"
#include "CC.h"

/**
 * Test usage of Graph classes
 */
int main(){

	std::ofstream output("./test/out.txt");

	std::ifstream tinyG("./test/tinyG.txt");
	std::ifstream mediumG("./test/mediumG.txt");
	std::ifstream largeG("./test/largeG.txt");

	std::vector<Graph*> graphs;

	graphs.push_back(new Graph(tinyG));
	graphs.push_back(new DirectedGraph(mediumG));
	graphs.push_back(new Graph(largeG));
	//graphs.push_back(new DirectedGraph(std::cin));	// can be read from any input stream

	std::cout << "read end" << std::endl;

	tinyG.close();
	mediumG.close();
	largeG.close();

	for (const auto g : graphs){
		// VERY slow for largeG
		output << *g;
		std::cout << "write end" << std::endl;

		if (g->V() < 100000){
			DFS dfs(*g, 0);
			output << dfs;
			output.flush();
			std::cout << "dfs end" << std::endl;
		}

		NonrecursiveDFS dfs2(*g, 0);
		output << dfs2;
		output.flush();
		std::cout << "non-recursive dfs end" << std::endl;

		BFS bfs(*g, 0);
		output << bfs;
		output.flush();
		std::cout << "bfs end" << std::endl;

		CC cc(*g);
		output << cc;
		output.flush();
		std::cout << "cc end" << std::endl;
	}


	// freeing up memory
	for (const Graph *g : graphs){
		delete g;
	}

	output.flush();
	output.close();

	return 0;
}