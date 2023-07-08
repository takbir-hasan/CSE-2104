#include <bits/stdc++.h>
using namespace std;

// Welcome to my Code!

#define ll long long

int n, m;
vector<char> v[1000];
char visited[1000];


void dfs(char node)
{
	visited[node] = 1;

	cout <<  node << "->";

	for (auto x : v[node])
	{
		if (!visited[x])
		{
			dfs(x);
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
  dfs('b');


	return 0;
}