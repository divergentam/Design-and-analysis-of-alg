#include <iostream>
#include <list>



class Graph
{
private:
	int V, E = 0;
	std::list<int>* adjList;
	bool* visited;
public:
	Graph(int V) {
		this->V = V;
		adjList = new std::list<int>[V];
		visited = NULL;
	}
	void addEdge(int u, int v) {
		this->E = E++;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	void DFS();
	void DFSFromNode(int u);

	~Graph() {
		delete[] adjList;
		delete[] visited;
	}
};

void Graph::DFS() {
	//podesi da svaki cvor nije posecen
	if (visited != NULL) {
		delete[] visited;
		visited = NULL;
	}
	visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	// za svaki cvor iz grafa G pusti DFS iz tog cvora ako nije posecen
	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			DFSFromNode(i);
		}
	}
}

void Graph::DFSFromNode(int u) {
	std::cout << u << "\n";
	visited[u] = true;
	std::list<int> neighbours = adjList[u];
	for (auto node : neighbours) {
		if (visited[node] == false) {
			DFSFromNode(node);
		}
	}
}


int main() {
	Graph graph = Graph(6);

	graph.addEdge(0, 2);
	graph.addEdge(0, 1);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	graph.addEdge(3, 5);
	graph.addEdge(4, 5);

	graph.DFS();

	return 0;
}