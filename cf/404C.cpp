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

typedef long long ll;
typedef pair<int, int> pii;

struct node {
    int k, id;
    node(int k = 0, int id = 0) : k(k), id(id) { }
    bool operator<(const node& m) const {
        return k > m.k;
    }
};

int n, k, a[100005];
vector<int> adj[100005];
int mark[100005];

int main() {

    scanf("%d%d", &n, &k);
    priority_queue<node> heap;

    node st;
    int z = 0;

    fr(i,1,n+1) {
        scanf("%d", &a[i]);
        if (a[i] == 0) st = node(a[i],i);
        else heap.push(node(a[i],i));
        z += (a[i] == 0);
    }

    if (z != 1) { //corner case I guess
        puts("-1");
        return 0;
    }

    queue<node> q;
    q.push(st);

    while(!heap.empty()) {
        node v = q.front(); q.pop();
        fr(i,0,k) {
            node w = heap.top();
            if (v.k+1 == w.k && mark[v.id] < k && mark[w.id] < k) {
                adj[v.id].pb(w.id);
                q.push(w);
                heap.pop();
                mark[v.id]++; mark[w.id]++;
            }
            else break;
            if (heap.empty()) break;
        }
        if (q.empty()) break;
    }

    vector<pii> ans;

    fr(i,1,n+1) {
        int sz = adj[i].size();
        fr(j,0,sz) {
            int w = adj[i][j];
            ans.pb(mp(i,w));
        }
    }

    int sz = ans.size();

    if (sz < n-1) {
        puts("-1");
        return 0;
    }

    printf("%d\n", sz);
    fr(i,0,sz) {
        printf("%d %d\n", ans[i].X, ans[i].Y);
    }

    return 0;
}
