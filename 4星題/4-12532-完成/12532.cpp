#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, a, b, input, pre_sum[2][100001] = {0};
    char mode;
    while(cin >> n >> m)
    {
        int arr[n+1];
        pre_sum[1][0] = 0;
        pre_sum[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> b;
            arr[i] = (b > 0 ? 1 : b < 0 ? -1 : 0);
            if(arr[i] < 0)
            {
                pre_sum[1][i] = pre_sum[1][i-1]+1;
                pre_sum[0][i] = pre_sum[0][i-1];
            }
            else if(arr[i] == 0)
            {
                pre_sum[0][i] = pre_sum[0][i-1]+1;
                pre_sum[1][i] = pre_sum[1][i-1];
            }
            else
            {
                pre_sum[1][i] = pre_sum[1][i-1];
                pre_sum[0][i] = pre_sum[0][i-1];
            }
        }
        for(int i = 0; i < m; i++)
        {
            cin >> mode >> a >> b;
            if(mode == 'C')
            {
                if(arr[a] == -1 && b >= 0)
                {
                    arr[a] = (b > 0 ? 1 : 0);
                    while(a <= n)
                    {
                        pre_sum[1][a]--;
                        if(b == 0)
                            pre_sum[0][a]++;
                        a++;
                    }
                }
                else if(arr[a] == 0 && b != 0)
                {
                    arr[a] = (b > 0 ? 1 : -1);
                    while(a <= n)
                    {
                        pre_sum[0][a]--;
                        if(b < 0)
                            pre_sum[1][a]++;
                        a++;
                    }
                }
                else if(arr[a] == 1 && b <= 0)
                {
                    arr[a] = (b == 0 ? 0 : -1);
                    while(a <= n)
                    {
                        if(b < 0)
                            pre_sum[1][a]++;
                        else
                            pre_sum[0][a]++;
                        a++;
                    }
                }
            }
            else
            {
                if(pre_sum[0][b] - pre_sum[0][a-1])
                    cout << '0';
                else if((pre_sum[1][b] - pre_sum[1][a-1])%2)
                    cout << '-';
                else
                    cout << '+';
            }
        }
        cout << endl;
    }
    return 0;
}
