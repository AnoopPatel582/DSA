#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    vector<vector<int>> redAdj(n), blueAdj(n);

    for (auto &e : redEdges)
    {
        redAdj[e[0]].push_back(e[1]);
    }

    for (auto &e : blueEdges)
    {
        blueAdj[e[0]].push_back(e[1]);
    }
    vector<vector<int>> dist(n, vector<int>(2, -1));
    queue<pair<int, int>> q;

    // lastColor = 0 → red
    // lastColor = 1 → blue
    q.push({0, 0});
    q.push({0, 1});

    dist[0][0] = 0;
    dist[0][1] = 0;
    while (!q.empty())
    {
        auto [u, lastColor] = q.front();
        q.pop();

        if (lastColor == 0)
        {
            // last was red → take blue edges
            for (int v : blueAdj[u])
            {
                if (dist[v][1] == -1)
                {
                    dist[v][1] = dist[u][0] + 1;
                    q.push({v, 1});
                }
            }
        }
        else
        {
            // last was blue → take red edges
            for (int v : redAdj[u])
            {
                if (dist[v][0] == -1)
                {
                    dist[v][0] = dist[u][1] + 1;
                    q.push({v, 0});
                }
            }
        }
    }
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        if (dist[i][0] == -1 && dist[i][1] == -1)
            ans[i] = -1;
        else if (dist[i][0] == -1)
            ans[i] = dist[i][1];
        else if (dist[i][1] == -1)
            ans[i] = dist[i][0];
        else
            ans[i] = min(dist[i][0], dist[i][1]);
    }
    return ans;
}

int main()
{
    int n, m, p;
    cout << "Enter the number of nodes:";
    cin >> n;
    cout << "Enter the numbers of red nodes:";
    cin >> m;
    vector<vector<int>> redEdges;
    vector<vector<int>> blueEdges;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the first element of redEdges array:";
        cin >> a;
        cout << "Enter the second element of redEdges array:";
        cin >> b;
        redEdges.push_back({a, b});
    }
    cout << "Enter the numbers of blue nodes:";
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cout << "Enter the first element of blueEdges array:";
        cin >> a;
        cout << "Enter the second element of blueEdges array:";
        cin >> b;
        blueEdges.push_back({a, b});
    }
    vector<int> result = shortestAlternatingPaths(n, redEdges, blueEdges);
    cout << "\nThe result: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}