#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &edge : times)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;
    pq.push({0, k});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int currDist = top.first;
        int u = top.second;

        // skip outdated entries
        if (currDist > dist[u])
            continue;

        // relax neighbors
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int wt = edge.second;

            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 1e9)
        {
            return -1; // unreachable node
        }
        ans = max(ans, dist[i]);
    }

    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes:";
    cin >> n;
    cout << "Enter the number of edge:";
    cin >> m;
    vector<vector<int>> times(m, vector<int>(3));
    cout << "Enter the values of time array:";
    for (int i = 0; i < m; i++)
    {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }
    int k;
    cout << "Enter the source node:";
    cin >> k;
    int ans = networkDelayTime(times, n, k);
    cout << "\nThe minimum time to reach all the nodes: " << ans;
    return 0;
}