#include<bits/stdc++.h>
using namespace std;
struct N{
    int x, y, t = 0;
};
int Y1, y2, x1, x2;
queue<N> q;
int Move[8][2] = {{1, 2}, {2, 1}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int f(bool pos[8][8])
{
    //cout << q.front().x << ' ' << q.front().y << endl;
    if(q.front().x == x2 && q.front().y == y2)
    {
        cout << q.front().t << " knight moves.\n";
        return 1;
    }
    if(!q.empty())
    {
        for(int i = 0; i < 8; i++)
        {
            int x = q.front().x + Move[i][0], y = q.front().y + Move[i][1];
            if(x >= 0&&x < 8&&y >= 0&& y < 8&&pos[y][x] == 0)
            {
                N temp;
                temp.x = x;
                temp.y = y;
                temp.t = q.front().t + 1;
                pos[y][x] = 1;
                q.push(temp);
            }
        }
        q.pop();
        f(pos);
    }
    return 0;
}
int main()
{
    char a, b;
    bool pos[8][8];
    while(cin >> a >> x1 >> b >> x2)
    {
        printf("To get from %c%d to %c%d takes ", a, x1, b, x2);
        Y1 = a - 'a';
        y2 = b - 'a';
        x1--; x2--;
        N temp;
        temp.x = x1;
        temp.y = Y1;
        temp.t = 0;
        //cout << x1 << ' ' << Y1 << ' ' << x2 << ' ' << y2 << endl;
        q.push(temp);
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                pos[i][j] = 0;
        pos[Y1][x1] = 1;
        f(pos);
        while(!q.empty())
            q.pop();
    }
    return 0;
}
