#include <iostream>
using namespace std;
#include <vector>

void readgraph(vector<vector<int>>&adjList , int vertices , int edges){
    cout<<"enter vertices and edges";
    for(int i=0 ; i<edges; i++){
        int u , v;
        cin>>u,v;
        adjList[v].push_back(u);
        adjList[u].push_back(v);

    }

}
void dfs(vector<vector<int>>&adjList , int current , vector<bool>&visited){
    visited[current]=true;
    cout<<current<<" ";


    for(int neighbour:adjList[current]){
        if (!visited[neighbour]){
            visited[neighbour]=true;
            dfs(adjList, neighbour, visited);
        }
    }
}
int main() {
    int totalVertices, totalEdges, choice;

    cout << "Enter number of vertices: ";
    cin >> totalVertices;
    cout << "Enter number of edges: ";
    cin >> totalEdges;

    vector<vector<int>> adjList(totalVertices);

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Read Graph\n";
        cout << "2. DFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            readgraph(adjList, totalVertices, totalEdges);
        }
        else if (choice == 2) {
            int startNode;
            cout << "Enter starting node: ";
            cin >> startNode;

            vector<bool> visited(totalVertices, false);
            cout << "\nDFS Traversal: ";
            dfs(adjList, startNode, visited);
            cout << "\n";
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}