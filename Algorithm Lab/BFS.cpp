#include <bits/stdc++.h>
using namespace std;

// Welcome to my Code!

#define ll long long

int n, m;
vector<char> v[1000];
char visited[1000];


void bfs(char node)
{
	queue<char> q;
 
    q.push(node);
    visited[node] = 1;
 
    while (!q.empty()) {
 
        char f = q.front();
        q.pop();
 
        cout << f << "->";
 
        for (auto i: v[f]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{

      freopen("graph.txt", "r", stdin);
    
	 cin >> n >> m;
   
	 for (int i = 1; i <= m; i++) {
        char u, p;
        cin >> u >> p;
		v[u].push_back(p);
		v[p].push_back(u);
	 }
  bfs('b');


	return 0;
}