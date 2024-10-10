#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int n, m, input;
    while(cin >> n && n) {
        cin >> m;
        int dp[m+2][m+2];
        memset(dp, 0, sizeof(dp));
        v.push_back(0);
        for(int i = 1; i <= m; i++) {
            cin >> input;
            v.push_back(input);
        }
        v.push_back(n);
        for(int i = 1; i < v.size(); i++) // 總切割點
        {
            for(int j = 0; j < v.size() - i; j++) { // 區間長度
                int l = j, r = j + i;
                for(int k = l+1; k < r; k++) {
                    if(dp[l][r] == 0)
                        dp[l][r] = dp[l][k] + dp[k][r] + v[r] - v[l];
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + v[r] - v[l]);
                }
            }
        }
        cout << "The minimum cutting is " << dp[0][m+1] << ".\n";
        v.clear();
    }
    return 0;
}
