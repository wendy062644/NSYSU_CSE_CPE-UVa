#include<bits/stdc++.h>
using namespace std;
bool connect[101][101] = {0};
int n, a, b, num[101] = {0};
void f(bool arr[101], int l)
{
    for(int i = 1; i <= n; i++)
    {
        if(!arr[i] && connect[l][i])
        {
            arr[i] = 1;
            f(arr, i);
        }
    }
}
int main()
{
    string str;
    while(cin >> n)
    {
        int ans = 0;
        if(!n)
            break;
        for(int i = 1; i <= n; i++)
        {
            num[i] = 0;
            for(int j = 1; j <= n; j++)
            {
                connect[i][j] = 0;
                connect[j][i] = 0;
            }
        }
        while(getline(cin, str) && str != "0")
        {
            stringstream ss(str);
            ss >> a;
            while(ss >> b)
            {
                connect[a][b] = true;
                connect[b][a] = true;
                num[a]++;
                num[b]++;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            bool arr[101] = {0};
            int num = 0;
            for(int j = 1; j <= n; j++)
            {
                if(connect[i][j] && !arr[j])
                {
                    arr[i] = 1;
                    arr[j] = 1;
                    f(arr, j);
                    num++;
                }
            }
            if(num > 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
