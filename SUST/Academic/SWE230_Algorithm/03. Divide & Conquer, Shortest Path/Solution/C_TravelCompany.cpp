// Problem: C - Travel Company
// Contest: Virtual Judge - Divide & Conquer, Shortest Path (With or without Negative Cycle)
// URL: https://vjudge.net/contest/528717#problem/C
// Time Limit: 2000 ms Memory Limit: 64 MB
// Parsed at: 2022-11-27 12:20:11

/*
    Bismillahir Rahmanir Rahim
    Author: Sakib62
*/
#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, weight;
	edge(int u, int v, int w): from(u), to(v), weight(w){} 
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    cin >> testCase;
    int tt = 1, limit = 1e9;
    while(testCase--) {
  
        int totalNode, totalEdge, ratio;
        cin >> totalNode >> totalEdge >> ratio;
        
        vector < edge > graph;
        vector < int > dist(totalNode, limit);
        dist[0] = 0;
 
//income/expense > ratio, income > ratio * expense
//So, (ratio * expense - income) is negative -> Desired condition for each road.
//If weight of a cycle is negative, then it is a good route where income/expense > ratio
//So need to find a negative cycle via Bellman Ford, if found good route exists!
 
        for(int i = 1; i <= totalEdge; i++) {
        	int u, v, inc, exp, w;
        	cin >> u >> v >> inc >> exp;
        	w = ratio * exp - inc;
        	graph.push_back(edge(u, v, w));
        }
        
        cout << "Case " << tt++ << ": ";
        
        for(int i = 0; i < totalNode - 1; i++) {
			for(auto edge : graph) {
				if(dist[edge.from] + edge.weight < dist[edge.to])
					dist[edge.to] = dist[edge.from] + edge.weight;
			}
        }
        
        bool ans = false;
        for(auto edge : graph) {
        	if(dist[edge.from] + edge.weight < dist[edge.to]) {
        		ans = true;
        		break;
        	}
        }
            
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}