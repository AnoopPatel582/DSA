#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    int freshCount = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0}); // rotten orange at time 0
            }
            else if (grid[i][j] == 1)
            {
                freshCount++; // count fresh oranges
            }
        }
    }
    int time = 0;

    // 4-direction movement
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        int x = front.first.first;
        int y = front.first.second;
        int t = front.second;

        time = max(time, t);

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
            {
                grid[nx][ny] = 2;          // make it rotten
                freshCount--;              // one fresh orange removed
                q.push({{nx, ny}, t + 1}); // next minute
            }
        }
    }
    if (freshCount > 0)
        return -1;
    return time;
}

int main()
{
    int m, n;
    cout << "Enter the size of grid (m*n):";
    cin >> m;
    cin >> n;
    vector<vector<int>> grid;
    cout << "Enter the elements of grid:";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int min_taken = orangesRotting(grid);
    cout << "The total minutes taken to rotten all the oranges: " << min_taken;
}