#include<bits/stdc++.h>
using namespace std;
char M[1000][1000];
struct node
{
    int x, y, n = 0;
}temp;
int t, n, m, x, y, ans, x2, y2, step[2][1000][1000], dir[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
queue<node> q;
void bfs(int k)
{
    while(!q.empty())
    {
        node tmp = q.front();
        q.pop();
        if(k && (tmp.n < step[0][tmp.y][tmp.x] || step[0][tmp.y][tmp.x] == -1) && (tmp.y == 0 || tmp.x == 0 || tmp.y == n-1 || tmp.x == m-1))
            ans = min(ans, tmp.n+1);
        for(int i = 0; i < 4; i++)
        {
            int x = tmp.x + dir[i][0], y = tmp.y + dir[i][1];
            if(x >= 0 && x < m && y >= 0 && y < n && step[k][y][x] < 0 && M[y][x] != '#')
            {
                step[k][y][x] = tmp.n+1;
                temp.x = x;
                temp.y = y;
                temp.n = tmp.n+1;
                q.push(temp);
            }
        }
    }
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ans = 1e6;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> M[i][j];
                step[0][i][j] = -1;
                step[1][i][j] = -1;
                if(M[i][j] == 'J')
                {
                    x = j;
                    y = i;
                    step[1][i][j] = 0;
                }
                if(M[i][j] == 'F')
                {
                    step[0][i][j] = 0;
                    temp.x = j;
                    temp.y = i;
                    temp.n = 0;
                    q.push(temp);
                }
            }
        bfs(0);
        temp.x = x;
        temp.y = y;
        temp.n = 0;
        q.push(temp);
        bfs(1);
        if(ans == 1e6)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << endl;
    }
    return 0;
}
