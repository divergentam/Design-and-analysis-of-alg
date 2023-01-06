#include <iostream>
#include <list>
#include <queue>

class Graph {
private:
	int V, E = 0;
	std::list<int>* adjList;
	int* order;
public:
	Graph(int V) {
		this->V = V;
		adjList = new std::list<int>[V];
		order = NULL;
	}
	void addEdge(int u, int v) {
		this->E = E++;
		adjList[u].push_back(v);
	}

	void topSort();

	~Graph() {
		delete[] adjList;
		delete[] order;
	}
};

void Graph::topSort() {
	if (order != NULL) {
		delete[] order;
		order = NULL;
	}
	order = new int[V];

	int* inDegree = new int[V];
	//postavljamo ulazni stepen na 0
	for (int i = 0; i < V; i++) {
		inDegree[i] = 0;
	}

	//racunamo ulazni stepen
	for (int i = 0; i < V; i++) {
		std::list<int> neighbours = adjList[i];
		for (auto v : neighbours) {
			inDegree[v]++;
		}
	}
	//pravimo red i onaj cvor koji ima ulazni stepen 0 ubacujemo u red
	std::queue<int> nodeQueue;
	for (int i = 0; i < V; i++) {
		if (inDegree[i] == 0) {
			nodeQueue.push(i);
		}
	}


	int count = 0;	// promenljiva koja broji koliko smo cvorova obisli

	while (!nodeQueue.empty()) {
		int u = nodeQueue.front();
		nodeQueue.pop();
		order[count++] = u;
		
		// Kad ispisemo cvor u onda brisemo taj cvor - 
		// odnosno smanjujmo ulazni stepen svim cvorovima koji su bili u vezi s njim
		// za onaj cvor koji tada ima ulazni stepen 0 dodamo ga u red
		std::list<int> neighbours = adjList[u];
		for (auto v : neighbours) {
			inDegree[v]--;
			if (inDegree[v] == 0) {
				nodeQueue.push(v);
			}
		}
	}

	// Ukoliko smo obisli V tj sve cvorove onde postoji topolosko sortiranje
	// u suprotnom ne postoji

	if (count == V) {
		std::cout << "Postoji topolosko sortiranje: " << std::endl;
		for (int i = 0; i < V; i++) {
			std::cout << order[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "Ne postoji topolosko sortiranje za dati graf" << std::endl;
	}

}


int main() {
	Graph graph = Graph(6);
	graph.addEdge(1, 0);
	graph.addEdge(2, 0);
	graph.addEdge(4, 2);
	graph.addEdge(3, 5);

	graph.topSort();

	return 0;
}