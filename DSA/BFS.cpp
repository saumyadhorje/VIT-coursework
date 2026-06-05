#include <iostream>
using namespace std;
#include<queue>
#include<vector>
//read
void readgraph(vector<vector<int>>&adjList, int vertices , int edges){
    
    for(int i=0; i<edges;i++){
        cout<<"Enter edges(u,v):"<<edges<<endl;
        int u , v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
//bfs
void bfs(vector<vector<int>>& adjList, int start) {
    int vertices=adjList.size();
    vector<bool>visited(vertices , false);
    queue<int>q;

    visited[start]=true;
    q.push(start);
    cout<<"bfs traversal starting from vertext:"<<start<<endl;
    while(!q.empty()){
        int current=q.front();//put from queue in current 
        q.pop();//pop from queue
        cout<<current<<" ";//print current

        //get all neighbours of current now
        for(int neighbour:adjList[current]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    cout<<endl;
}
int main(){
    int vertices , edges , choice;
    cout<<"enter number of vertuces and edges:";
    cin>>vertices>>edges;
    vector<vector<int>> adjList(vertices);
   while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Read Graph (Adjacency List)\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            readgraph(adjList, vertices, edges);
        }
        else if (choice == 2) {
            int startNode;
            cout << "Enter starting node: ";
            cin >> startNode;

            bfs(adjList, startNode);
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