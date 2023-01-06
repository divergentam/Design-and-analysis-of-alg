#include <iostream>
#include <utility>
#include <limits.h>
#include <vector>

class Graph {
public:
    int V, E = 0;
	std::vector<std::pair<int, int>>* adjList; //pamtimo kao pair da bi mogli da pamtimo i tezinu
	int* distance;  // niz za pracenje najmanje distance 
	bool* visited;  // za oznacavanje posecenog cvora
	Graph(int v) {
		V = v;
		adjList = new std::vector<std::pair<int, int>> [V];
		visited = new bool[V];
		distance = new int[V];
	}
	void addEdge(int u, int v, int weight) {
		adjList[u].push_back(std::pair<int, int>(v, weight));
		adjList[v].push_back(std::pair<int, int>(u, weight));
	}
	void print() {
		int v, w;
		for (int i = 0; i < V; i++) {
			std::cout << "Cvor " << i << " je u vezi sa cvorovima: \n";
			for (auto it = adjList[i].begin(); it != adjList[i].end(); it++){
				v = it->first;
				w = it->second;
				std::cout << "\t " << v << " i tezinom =" << w << "\n";
			}
			std::cout << std::endl;
		}
	}
	
};

// vracamo minimalnu distancu cvora koji nije posecen
int minimumDistance(Graph graph) {
	int min = INT_MAX, index;

	for (int i = 0; i < graph.V; i++) {
		if (graph.visited[i] == false && graph.distance[i] <= min) {
			min = graph.distance[i];
			index = i;
		}
	}

	return index;
}

void Dijkstra(Graph graph, int src) {
	// postavljamo infinity distancu za svaki od cvorova (tj najvecu mogucu - INT_MAX)
	// postavljamo sve cvorove na neposecene - false

	for (int i = 0; i < graph.V; i++) {
		graph.visited[i] = false;
		graph.distance[i] = INT_MAX;
	}

	// za src cvor distance postavljamo na 0
	graph.distance[src] = 0; // moramo da stavimo da je za pocetni cvor distance 0 
	// kako bi od njega mogli da krenemo

	for (int i = 0; i < graph.V; i++) {
		int m = minimumDistance(graph); 
		// kad nadjemo cvor proglasavamo ga za visited
		graph.visited[m] = true;

		// uzimamo adjListu cvora m da bi videli sa kojim cvorovima je sve m u vezi
		std::vector<std::pair<int, int>> neigh_m = graph.adjList[m];

		for (int i = 0; i < graph.V; i++) {
			for (auto v : neigh_m) {
				if (v.first == i) { // zelimo da vidimo da li su uopste cvor m i cvor v u vezi
					if (!graph.visited[i] && graph.distance[m] != INT_MAX &&
						graph.distance[m] + v.second < graph.distance[i]) {
						// ako su u vezi pitamo proveravamo da li je cvor i neposecen
						// da li je distanca[m] != infinity
						// i da li je distanca od m + tezina grane(m, i) manja od trenutno upisane distance za i 
						graph.distance[i] = graph.distance[m] + v.second;
						// ako jeste tu novu duzinu upisemo u distance[i]
					}
				}
			}
		}

	}

	std::cout << "Cvor\t\t Udaljenost od pocetnog cvora" << std::endl;
	for (int i = 0; i < 6; i++)
	{ 
		std::cout << i << "\t\t\t" << graph.distance[i] << std::endl;
	}

}


int main() {
	Graph graph = Graph(6);
	
	graph.addEdge(0, 1, 10);
	graph.addEdge(0, 2, 20);
	graph.addEdge(1, 3, 50);
	graph.addEdge(1, 4, 10);
	graph.addEdge(2, 3, 20);
	graph.addEdge(2, 4, 33);
	graph.addEdge(3, 4, 20);
	graph.addEdge(3, 5, 2);
	graph.addEdge(4, 5, 1);

	//graph.print();

    Dijkstra(graph, 0);
	
	return 0;
}