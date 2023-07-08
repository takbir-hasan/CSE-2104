#include <bits/stdc++.h>
using namespace std;

// Welcome to my Code!

#define ll long long

int n, m;
vector<int> parent(1000,-1);
vector<pair<int, int> > adj[1000];
int visited[1000];


void dijkstra(vector<pair<int, int> > adj[], int n, int src, int des)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
 
   
    vector<int> dist(n+1, INT_MAX);
 
  
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();
      
        for (auto x : adj[u]) {

            int v = x.first;
            int w = x.second;
        
 
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
                parent[v]= u;
            }
        }
    }

        vector<int> path;
        int current = des;
        while(current!=-1){
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(),path.end());
        cout << "Minimum distance of the destiantion is: " << dist[des] << endl;
        cout << "The path is:\n";
        for(auto x: path) cout << x <<"-->";
}


int main()
{

     freopen("graph.txt", "r", stdin);
    
	 cin >> n >> m;
   
	 for (int i = 1; i <= m; i++) {
        int u, v, p;
        cin >> u >> v >> p;

        adj[u].push_back(make_pair(v,p));
        adj[v].push_back(make_pair(u,p));


    }
      int source, destination;
      cin>> source >> destination;
      
	dijkstra(adj, n,source, destination);

	return 0;
}