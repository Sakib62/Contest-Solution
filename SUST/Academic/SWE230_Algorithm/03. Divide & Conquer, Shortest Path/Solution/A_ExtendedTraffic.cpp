// Problem: A - Extended Traffic
// Contest: Virtual Judge - Divide & Conquer, Shortest Path (With or without Negative Cycle)
// URL: https://vjudge.net/contest/528717#problem/A
// Time Limit: 1000 ms Memory Limit: 64 MB
// Parsed at: 2022-11-24 12:00:52

/*
    Bismillahir Rahmanir Rahim
    Author: Sakib62
*/
#include <bits/stdc++.h>
using namespace std;

#define limit 10000 //to define unreachable state //cost of each edge will be maximum of (20-0)^3=8000

int main() {
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    //#endif
    ios::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    cin >> testCase;
    int tt = 1;
    while(testCase--) {
        int n;
        cin >> n;
        int busyness[n + 1], distance[n + 1];
        for(int i = 1; i <= n; i++) {
        	cin >> busyness[i];
        	distance[i] = limit;
        }
        distance[1] = 0;
        int m;
        cin >> m;
        vector < pair < int, pair < int, int > > > edge;
        for(int i = 0; i < m; i++) {
        	int u, v;
        	cin >> u >> v;
        	int tmp = (busyness[v] - busyness[u]);
        	int weight = tmp * tmp * tmp;
        	edge.push_back({weight, {u, v}});
        }
        //bellman ford
        int sz = edge.size();
        for(int i = 1; i < n; i++) {
        	for(int j = 0; j < sz; j++) {
        		int src = edge[j].second.first;
        		int des = edge[j].second.second;
        		int weight = edge[j].first;
        		if(distance[src] != limit && distance[des] > distance[src] + weight) 
        			distance[des] = distance[src] + weight;
        	}
        }
        int q;
        cin >> q;
        cout << "Case " << tt++ << ":\n";
        for(int i = 1; i <= q; i++) {
        	int des;
        	cin >> des;
        	if(distance[des] < 3 || distance[des] == limit) cout << "?\n";
        	else cout << distance[des] << "\n";
        }
    }
}