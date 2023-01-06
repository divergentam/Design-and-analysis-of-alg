#include <iostream>
#include <list>
#include <queue>

// Graf G sadrzi ciklus akko postoji grana uv takva da u grafu
// G - uv postoji put od u do v (jer taj put sa granom uv cini ciklus)

//Prilikom poziva dfs(u) linija if(visited[v] == false) kada vrati false 
// odnosno kad je cvor v vec posecen, to se desava jedino u slucaju 
// kada je v vec perent cvoru u -> parent[u] = v ili kad postoji grana izmedju
// nekog trenutnog cvora u i nekog ranije obidzenog cvora v.
//Drugi slucaj garantuje da postoji ciklus jer postoji put od u do v i
// povratna grana od v do u koja nije deo tog ciklusa.

class Graph {
private:
	int V, E = 0;
	std::list<int>* adjList;
	bool* visited;
	int* parent;
public:
	bool cycleFound;
	Graph(int V) {
		this->V = V;
		adjList = new std::list<int>[V];
		visited = NULL;
		parent = NULL; 
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
		delete[] parent;
	}
};

void Graph::DFS() {
	if (visited != NULL) {
		delete[] visited;
		visited = NULL;
	}
	visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	if (parent != NULL) {
		delete[] parent;
		parent = NULL;
	}
	parent = new int[V];
	for (int i = 0; i < V; i++) {
		parent[i] = -1;
	}

	cycleFound = false;

	// za svaki cvor iz grafa G pusi dfs iz tog cvora ako nije posecen
	for (int i = 0; i < V; i++) {
		if (visited[i] == false && cycleFound == false) {
			DFSFromNode(i);
		}
	}

	if (cycleFound) {
		std::cout << "DA" << std::endl;
	}
	else {
		std::cout << "NE" << std::endl;
	}


}

void Graph::DFSFromNode(int u) {
	std::cout << u << "\n";
	visited[u] = true;
	std::list<int> neighbours = adjList[u];
	for (auto v : neighbours) {
		if (visited[v] == false) {
			parent[v] = u;
			DFSFromNode(v);
		}
		else {
			if (parent[u] != v) {
				cycleFound = true;
			}
		}
	}
}

int main() {
	Graph graph = Graph(5);

	graph.addEdge(0, 3);
	graph.addEdge(2, 4);
	graph.addEdge(4, 0);
	graph.addEdge(1, 3);
	graph.addEdge(0, 2);

	graph.DFS();
	

	return 0;
}