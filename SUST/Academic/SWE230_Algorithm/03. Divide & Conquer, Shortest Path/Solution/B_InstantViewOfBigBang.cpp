// Problem: B - Instant View of Big Bang
// Contest: Virtual Judge - Divide & Conquer, Shortest Path (With or without Negative Cycle)
// URL: https://vjudge.net/contest/528717#problem/B
// Time Limit: 1000 ms Memory Limit: 64 MB
// Parsed at: 2022-11-24 22:52:56

/*
    Bismillahir Rahmanir Rahim
    Author: Sakib62
*/
#include <bits/stdc++.h>
using namespace std;
#define limit 2000

int main() {
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    //#endif
    ios::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    cin >> testCase;
    int tt = 1;
    while(testCase--) {
        int n, m;
        cin >> n >> m;
        int distance[n + 1];//for ease of use
        bool visited[n + 1];
        for(int i = 1; i <= n; i++) {
        	distance[i] = limit;
        	visited[i] = false;
        }
        distance[1] = 0;
        vector < pair < int, pair < int, int > > > edge;//can be implmented by structure
        vector < int > incoming[n + 1];//nodes through which current node can be visited
        
        for(int i = 1; i <= m; i++) {
        	int src, des, cost;
        	cin >> src >> des >> cost;
        	//for convenience
        	src++;
        	des++;
        	edge.push_back({cost, {src, des}});
        	incoming[des].push_back(src);//will be used to find entrance nodes to negative cycle
        }

        cout << "Case " << tt++ << ":";
        int sz = edge.size();
        for(int i = 1; i < n; i++) {
        	for(int j = 0; j < sz; j++) {
        		int src = edge[j].second.first;
        		int des = edge[j].second.second;
        		int cost = edge[j].first;
	//We only want the nodes which are within a negative cycle.
	//Then check incoming edge to find nodes that connects to the nodes of this cycle.
	
//Problem:: In Bellman Ford, the cost in nth iteration decreases if it is within a negative cycle or it is reachable from a negative cycle.
//Solution:: Reversing the graph -> prevention of the decrement of cost for any node that are not part of the negative cycle.
	//Doesn't effect edges in neg cycle
        		if(distance[des] + cost < distance[src]) {
        			distance[src] = distance[des] + cost;//if(distance[des]==limit) -> even if disconnected component & negative edge, condition will be true
        		}
        	}
        }

        bool ok = false;
        vector < int > store;
        for(int i = 0; i < sz; i++) {
        	int src = edge[i].second.first;
        	int des = edge[i].second.second;
        	int cost = edge[i].first;
        	if(distance[des] + cost < distance[src]) {//works for negative cycle in disconnected component too
        		ok = true;//negative cyle exist
        		store.push_back(src);
//iterating through incoming edge, we will get list of entrance node in this cycle
        	}
        }
        if(!ok) {cout << " impossible\n"; continue;}
        
        int len = store.size();
        for(int i = 0; i < len; i++) {
        	int u = store[i];
        	if(visited[u]) continue;
        	visited[u] = true;
        	for(int v : incoming[u]) store.push_back(v);
        	len = store.size();
        }
        
        for(int i = 1; i <=n; i++) {
        	if(visited[i]) cout << " " << i - 1;//as node number was incremented before
        }
        cout << "\n";
    }
}