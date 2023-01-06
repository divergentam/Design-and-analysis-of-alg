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

	int* inputDegree = new int[V];
	// postavljamo ulazni stepen na 0
	for (int i = 0; i < V; i++) {
		inputDegree[i] = 0;
	}
	// racunamo ulazni stepen
	for (int i = 0; i < V; i++) {
		std::list<int> neighbours = adjList[i];
		for (auto v : neighbours) {
			inputDegree[v]++;
		}
	}

	std::queue<int> nodeQueue;
	for (int i = 0; i < V; i++) {
		if (inputDegree[i] == 0) {
			nodeQueue.push(i);
		}
	}

	int count = 0; // promenljiva koja broji koliko smo cvorova do sada obisli

	// vadimo redom cvorove iz reda
	while (!nodeQueue.empty()) {
		int u = nodeQueue.front();
		nodeQueue.pop();
		order[count] = u;
		count++;
		
		// Svim susedima cvora u smanjujemo ulazni stepen 1
		std::list<int> neighbours = adjList[u];
		for (auto v : neighbours) {
			inputDegree[v]--;
			// ako ulazni stepen posane 0 staviti taj cvor u red
			if (inputDegree[v] == 0) {
				nodeQueue.push(v);
			}
		}
	
	}

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
	
	Graph graph = Graph(4);


	graph.addEdge(1, 0);
	graph.addEdge(0, 2);
	graph.addEdge(3, 2);
	graph.addEdge(0, 3);

	graph.topSort();
	
	return 0;
}