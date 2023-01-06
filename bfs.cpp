#include <iostream>
#include <list>
#include <queue>

// Udaljenost cvorova od startnog svora

class Graph
{
private:
	int V, E = 0;
	std::list<int>* adjList;
	bool* visited;
	int* distance;
public:
	Graph(int V) {
		this->V = V;
		adjList = new std::list<int> [V];
		visited = NULL;
		distance = NULL;
	}
	void addEdge(int u, int v) {
		this->E = E++;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	void BFS(int src);

	~Graph() {
		delete[] adjList;
		delete[] visited;
		delete[] distance;
	}
};

void Graph::BFS(int src) {
	//Podesi da svaki cvor nije posecen
	if (visited != NULL) {
		delete[] visited;
		visited = NULL;
	}
	visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	if (distance != NULL) {
		delete[] distance;
		distance = NULL;
	}
	distance = new int[V];
	for (int i = 0; i < V; i++) {
		distance[i] = -1;
	}

	distance[src] = 0; // startni cvor je na udaljenosti 0 od samog sebe

	//Kreiramo red
	std::queue<int> queueNode;

	// Dodaje se startni cvor na pocetak reda i oznacava se kao posecen
	queueNode.push(src);
	visited[src] = true;

	while (!queueNode.empty()) {
		int u = queueNode.front();
		queueNode.pop();
		std::cout << "Cvor " << u << " je udaljen " << distance[u] << " od cvora " << src << std::endl;
		std::list<int> neighbours = adjList[u];
		for (auto v : neighbours) {
			if (visited[v] == false) {
				visited[v] = true;
				distance[v] = distance[u] + 1;
				queueNode.push(v);
			}
		}
	}

}





int main() {
	Graph graph = Graph(7);

	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 3);
	graph.addEdge(3, 4);
	graph.addEdge(3, 0);
	graph.addEdge(4, 0);
	graph.addEdge(5, 6);

	graph.BFS(0);

	return 0;
}