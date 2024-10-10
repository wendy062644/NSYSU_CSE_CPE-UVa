#include<bits/stdc++.h>
using namespace std;
int n, x, a, b, times = 1;
int dfs(bool path[101][101], int finishing[101], int l[101], int x)
{
    for(int i = 1; i <= n; i++)
    {
        if(path[x][i] && l[i] > 0)
        {
            if(l[i] + 1 >= l[x] && finishing[i] < finishing[x])
            {
                finishing[x] = finishing[i];
            }
            else if(l[i] + 1 > l[x])
            {
                finishing[x] = finishing[i];
                l[x] = l[i] + 1;
            }
        }
        else if(path[x][i])
        {
            int temp = dfs(path, finishing, l, i) + 1;
            if(temp > l[x])
            {
                l[x] = temp;
                finishing[x] = finishing[i];
            }
            else if(temp >= l[x])
            {
                if(finishing[x] > finishing[i])
                    finishing[x] = finishing[i];
            }
        }
    }
    return l[x];
}
int main()
{
    while(cin >> n)
    {
        if(!n)
            break;
        cin >> x;
        bool path[101][101] = {0};
        int l[101] = {0}, finishing[101] = {0};
        for(int i = 1; i < 101; i++)
            finishing[i] = i;
        while(cin >> a >> b)
        {
            if(!a * !b)
                break;
            path[a][b] = 1;
        }
        dfs(path, finishing, l, x);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", times++, x, l[x], finishing[x]);
    }
    return 0;
}
