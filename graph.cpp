#include <iostream>
#include <list>

//typedef struct Node {
//	int data;
//	struct Node* link;
//}Node;
//
//typedef struct Graph {
//	struct Node** adjList;
//	int n;
//}Graph;

/*Graf zadajemo na sledeci nacin:
5 1
1 4
5 4
3 2
3 5
3 4
*/

class Graph {
private:
public:
	int V, E;
	std::list<int>* adj;
	Graph(){
		std::cout << "Unesite broj cvorova i broj grana: " << std::endl;
		std::cin >> V >> E; // broj lista i broj grana
		adj = new std::list<int>[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			std::cout << "Unesite cvorove koji su u vezi: " << std::endl;
			std::cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u); // bez ovog je usmeren
		}
	}
	~Graph() {
		delete[] adj;
	}
};

int main() {
	Graph graph;
	//prolazak kroz sve susede cvora 3
	std::list<int> node = graph.adj[3];
	for (auto adj : node) {
		std::cout << adj << " ";
	}
	std::cout << std::endl;

	return 0;
}