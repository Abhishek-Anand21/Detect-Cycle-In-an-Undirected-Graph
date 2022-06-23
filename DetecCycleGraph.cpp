#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool findCycle(int V, vector<int> adj[],int sv,bool isVisited[],int itsParent[]) {
        queue<int> pendingVertices;
        pendingVertices.push(sv);
        isVisited[sv] = true;
        itsParent[sv] = sv;
        while(!pendingVertices.empty()) {
            int currentValue = pendingVertices.front();
            pendingVertices.pop();
            for(int i = 0; i < adj[currentValue].size(); i++) {
                if(!isVisited[adj[currentValue][i]]) {
                    isVisited[adj[currentValue][i]] = true;
                    pendingVertices.push(adj[currentValue][i]);
                    itsParent[adj[currentValue][i]] = currentValue;
                }
                else {
                    if(itsParent[currentValue] !=  adj[currentValue][i])
                        return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool isVisited[V] = {false};
        int itsParent[V];
        for(int i=0;i<V;i++) {
            if(!isVisited[i]) {
                if(findCycle(V,adj,i,isVisited,itsParent))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
