#include<bits/stdc++.h>
using namespace std;
char arr[10][10];
int t, n, dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int f(int x, int y)
{
    if(x == n)
    {
        x = 0;
        y++;
    }
    if(y == n)
        return 1;
    else if(arr[y][x] != '.')
    {
        if(f(x+1, y))
            return 1;
    }
    else
    {
        for(int i = 0; i < 26; i++)
        {
            bool ok = 1;
            for(int j = 0; j < 4; j++)
            {
                int X = x + dir[j][0], Y = y + dir[j][1];
                if(X > -1 && X < n && Y > -1 && Y < n && arr[Y][X] == 'A' + i)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                arr[y][x] = 'A' + i;
                if(f(x+1, y))
                    return 1;
                arr[y][x] = '.';
            }
        }
    }
    return 0;
}
int main()
{
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        f(0, 0);
        cout << "Case " << k << ":\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
