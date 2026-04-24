
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int subtree_size[MAXN];
int n, k;
vector<int> results;

void dfs(int u, int p) {
    subtree_size[u] = 1;
    bool ok = true;
    int total_children_size = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
        total_children_size += subtree_size[v];
        if (subtree_size[v] > k) {
            ok = false;
        }
    }
    
    int rest_size = n - subtree_size[u];
    if (rest_size > k) {
        ok = false;
    }
    
    if (ok) {
        results.push_back(u);
    }
}

int main() {
    if (!(cin >> n >> k)) return 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        if (!(cin >> u >> v)) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    if (results.empty()) {
        cout << "None" << endl;
    } else {
        sort(results.rbegin(), results.rend());
        for (int i = 0; i < results.size(); ++i) {
            cout << results[i] << (i == results.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    
    return 0;
}
