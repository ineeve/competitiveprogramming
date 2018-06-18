//this includes all needed libraries
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
int num_of_visited_nodes;
int dfs(int s) {
// process node s
    num_of_visited_nodes++;
    if (visited[s]) {
        return 0;
    }
    visited[s] = 1;
    for (auto u : adj[s]) {
        if (dfs(u) == 0){
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); //input and output become more efficient.
    cin.tie();
    int num_nodes;
    int num_edges;
    cin >> num_nodes >> num_edges;
    adj.resize(num_nodes+1);
    visited.resize(num_nodes+1);
    num_of_visited_nodes = 0;
    while(num_edges-- > 0){
        int node1;
        int node2;
        cin >> node1 >> node2;
        adj.at(node1).push_back(node2);
    }
    int isTree = dfs(1) && (num_of_visited_nodes == num_nodes);
    if (isTree){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    
}