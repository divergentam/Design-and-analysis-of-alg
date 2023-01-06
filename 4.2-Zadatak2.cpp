#include <iostream>
#include <list>
#include <queue>

#define N 8

class Graph {
protected:
	int V, E = 0;
	std::list<int>* adjList;
	static const int dx[N];
	static const int dy[N];
	bool* visited;
	int* distance;
	int* parent;

	int start, end;
public:
	Graph(int n) {
		char** graph;
		graph = new char*[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new char[n];
			std::cout << "Unesite red: ";
			for (int j = 0; j < n; j++) {
				std::cin >> graph[i][j];
				if (graph[i][j] == 'S') {
					start = i * n + j;
				}
				else if (graph[i][j] == 'E') {
					end = i * n + j;
				}
			}
		}

		// formiranje grana
		V = n * n;
		adjList = new std::list<int>[V];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] != 'X') {
					for (int k = 0; k < N; k++) {
						int x = dx[k] + i;
						int y = dy[k] + j;
						if (x >= 0 && y >= 0 && x < n && y < n && graph[x][y] != 'X') {
							adjList[i * n + j].push_back(x * n + y);
							E++;
						}
					}
				}
			}
		}
		visited = NULL;
		distance = NULL;
		parent = NULL;
	}

	void BFS(int start);
	void zad2();

	~Graph() {
		delete[] adjList;
		delete[] visited;
		delete[] parent;
	}

};

const int Graph::dx[N] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int Graph::dy[N] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void Graph::BFS(int start) {
	// podesavamo svaki cvor kao neposecen
	if (visited != NULL) {
		delete[] visited;
		visited = NULL;
	}
	visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	// podesavanje rastojanja distance cvora i od cvora start
	if (distance != NULL) {
		delete[] distance;
		distance = NULL;
	}
	distance = new int[V];
	for (int i = 0; i < V; i++) {
		distance[i] = -1;
	}
	distance[start] = 0; // pocetni cvor je na udaljenosti 0  od sebe

	// podesavanje niza perent
	if (parent != NULL) {
		delete[] parent;
		parent = NULL;
	}
	parent = new int[V];
	// na pocetku ni jedan cvor nema perenta
	for (int i = 0; i < V; i++) {
		parent[i] = -1;
	}

	std::queue<int> queueNode;

	queueNode.push(start);
	visited[start] = true;

	while (!queueNode.empty()) {
		int u = queueNode.front();
		queueNode.pop();
		std::list<int> neighbours = adjList[u];
		for (auto node : neighbours) {
			if (visited[node] == false) {
				visited[node] = true;
				parent[node] = u;
				distance[node] = distance[u] + 1;
				queueNode.push(node);
			}
		}

	}
}

void Graph::zad2() {
	// pustamo bfs iz strtnog cvora kako bi dobili najkrace udaljenosti od cvora start do ostalih cvorova
	BFS(start);

	// ako ne postoji put od start do end cvora onda je distance = -1
	if (distance[end] == -1) {
		std::cout << "NIJE MOGUCE - da se dodje iz S do E" << std::endl;
	}
	else {
		std::cout << "MOGUCE JE - da se dodje iz S do E" << std::endl;
		// ispisivanje te putanje od cvora s do e
		std::cout << distance[end] << std::endl;
		int node = end;
		int n = sqrt(this->V);
		while (node != -1)
		{
			int x = node / n;
			int y = node % n;
			std::cout << "(" << x << ", " << y << ") ";
			node = this->parent[node];
		}
	}

}


int main() {
	int n = 4;
	Graph *graph = new Graph(n);
	graph->zad2();

	return 0;
}