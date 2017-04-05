#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define rf(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

const int INF = 2147483647;

typedef long long ll;
typedef pair<int, int> pii;

int n, e, D[5005]; //nodes, edges, distance array
vector<pair<int, int> > adj[5005]; //adjacence list

void dijkstra() {
    for(int i = 0; i < n; i++) D[i] = INF;
    D[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push({0,0});

    while(!q.empty()) {
        pair<int,int> p = q.top();
        q.pop();

        int u = p.second, dist = p.first;
        if(dist > D[u]) continue;

        for(pair<int,int> pr : adj[u]) {
            int v = pr.first;
            int next_dist = dist + pr.second;

            if(next_dist < D[v]) {
                D[v] = next_dist;
                q.push({next_dist,v});
            }
        }
    }
}
