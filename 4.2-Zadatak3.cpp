#include <iostream>
#include <list>

class Graph
{
private:
	int n, m;
	std::list<int>* adjList;
	bool* visited;
	int currentComponentSize; // velicina trenutne komponente
	int numofComponent; // broj komponenti
	int maxComponentSize; // velicina najvece komponente
	static const int dx[4];
	static const int dy[4];
public:
	Graph() {
		std::cout << "Unesite dimenzije matrice: ";
		std::cin >> n >> m;
		char** graph;
		graph = new char* [n];
		for (int i = 0; i < n; i++) {
			graph[i] = new char[m];
			std::cout << "Unesite red: ";
			for (int j = 0; j < m; j++) {
				std::cin >> graph[i][j]; // ili 'X' ili 'O'
			}
		}

		// formiranje grana
		adjList = new std::list<int>[n * m]; // kolioko cvorova ima - onoliko koliko iam O - ali stavljamo adjListu i za x cvorove jer nam je potrebno da bi znali da li je neki cvor 'X'
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 'O') { // proveriti susede gore, dole, levo, desno i ako je neki sused isto 'O' stavljamo granu izmedju njih
					// ako se nalazimo u graph[i][j]
					// gore  - graph[i - 1][j]
					// dole  - garph[i + 1][j]
					// levo  - graph[i][j - 1]
					// desno - graph[i][j + 1] 
					// dx = {-1, 1, 0, 0}
					// dy = {0, 0, -1, 1}
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == 'O') { // prvo da li postoji takav el.
							adjList[i * m + j].push_back(x * m + y);
							// i * m + j  je redni broj cvora
							// x * m + y je redni broj suseda
						} 
					}
				}
			}
		}
		visited = NULL;
		currentComponentSize = 0;
		maxComponentSize = 0;
		numofComponent = 0;
	}

	void DFS();
	void DFSFromNode(int u);

	~Graph() {
		delete[] adjList;
		delete[] visited;

	}
};

const int Graph::dx[4] = {-1, 1, 0, 0};
const int Graph::dy[4] = {0, 0, -1, 1};

void Graph::DFS() {
	if (visited != NULL) {
		delete[] visited;
		visited = NULL;
	}
	visited = new bool[n * m];

	for (int i = 0; i < n * m; i++) {
		visited[i] = false;
	}
	
	numofComponent = 0;
	maxComponentSize = 0;

	for (int i = 0; i < n * m; i++) {
		if (visited[i] == false && adjList[i].size() > 0) {
			currentComponentSize = 0;
			numofComponent++;
			DFSFromNode(i);
			if (currentComponentSize > maxComponentSize) {
				maxComponentSize = currentComponentSize;
			}
		}
	}

	std::cout << std::endl << "Ima ukupno " << numofComponent << " komponenti" << std::endl;
	std::cout << "Najveci deo ima " << maxComponentSize << " polja" << std::endl;
}

void Graph::DFSFromNode(int u) {
	std::cout << u << "\n";
	currentComponentSize++;
	visited[u] = true;
	std::list<int> neighbours = adjList[u];
	for (auto v : neighbours){
		if (visited[v] == false) {
			DFSFromNode(v);
		}
	}
}

int main() {
	Graph graph;
	graph.DFS();

	return 0;
}
