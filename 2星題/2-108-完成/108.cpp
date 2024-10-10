#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n){
        int pre_sum[n+1][n+1] = {0}, ans = -1e8;
        for(int i = 1; i <= n; i++){
            cin >> pre_sum[i][1];
            pre_sum[0][i] = 0;
            pre_sum[i][0] = 0;
            for(int j = 2; j <= n; j++){
                cin >> pre_sum[i][j];
                pre_sum[i][j] += pre_sum[i][j-1];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= n; j++){
                int sum = 0;
                for(int k = 1; k <= n; k++){
                    //cout << pre_sum[k][j] << ' ' << pre_sum[k][i] << endl;
                    sum += pre_sum[k][j] - pre_sum[k][i];
                    ans = max(ans, sum);
                    if(sum < 0)
                        sum = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
