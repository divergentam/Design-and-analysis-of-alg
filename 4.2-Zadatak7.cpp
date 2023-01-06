#include <iostream>
#include <list>
#include <queue>

class Graph {
private:
	int V, E = 0;
	std::list<int>* adjList;
	bool* visited;
public:
	Graph(int v) {
		V = v;
		adjList = new std::list<int>[V];
		visited = NULL;
	}
	void addEdge(int u, int v) {
		this->E++;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	void BFS(int start, int d[]);
	int zad7(int a, int b);

	~Graph() {
		delete[] adjList;
		delete[] visited;
	}

};

void Graph::BFS(int start, int d[]) {
	if (visited != NULL) {
		delete[] visited;
		visited = NULL;
	}
	visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < V; i++) {
		d[i] = -1;
	}
	d[start] = 0;

	std::queue<int> queueNodes;
	queueNodes.push(start);
	visited[start] = true;

	while (!queueNodes.empty()) {
		int u = queueNodes.front();
		queueNodes.pop();
		std::cout << "Cvor " << u << " na razdaljini " << d[u] << " od cvora " << start << std::endl;
		std::list<int> neighbours = adjList[u];
		for (auto v : neighbours) {
			if (visited[v] == false) {
				visited[v] = true;
				d[v] = d[u] + 1;
				queueNodes.push(v);
			}
		}
	}
}

int Graph::zad7(int a, int b){
	int distance_a[5];
	int distance_b[5];

	BFS(a, distance_a);
	BFS(b, distance_b);

	int count = 0;
	std::cout << "Dobri cvorovi: ";
	for (int i = 0; i < V; i++) {
		if (distance_a[i] + distance_b[i] == distance_a[b]) {
			count++;
			std::cout << i << " ";
		}
	}
	return count;
}

int main() {
	Graph graph = Graph(5);

	graph.addEdge(0, 1);
	graph.addEdge(1, 4);
	graph.addEdge(0, 2);
	graph.addEdge(2, 4);
	graph.addEdge(2, 3);

	std::cout << std::endl << "Ima ih ukupno " << graph.zad7(0, 4);

	return 0;
}