#include<iostream>
#include<list>

using namespace std;

class Graph {
	int V;
	list<int> *adjVerts;    
	// A recursive function used by DFS
	void DFSUtil(int v, bool visited[]);
 public:
	 Graph(int V);
	 void addEdge(int v, int w);
	 void BFS(int s);
	 void DFS(int v);
};

Graph::Graph(int V) {
	this->V = V;
	adjVerts = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adjVerts[v].push_back(w);
}


void Graph::DFSUtil(int v, bool visited[]) {
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v) {
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function
	// to print DFS traversal
	DFSUtil(v, visited);
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	visited[s] = true;

	list <int>::iterator i;

	while (!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = adjVerts[s].begin(); i != adjVerts[s].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

}

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";

	g.BFS(2);
	return 0;
}