#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int arr[n] = {0};
        bool dp[n+1][m] = {0};
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            for(int j = 0; j < m; j++) {
                if(dp[i][j]) {
                    dp[i+1][(j+arr[i]+10000*m)%m] = 1;
                    dp[i+1][(j-arr[i]+10000*m)%m] = 1;
                }
            }
        }
        if(dp[n][0])
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;
    }
    return 0;
}
