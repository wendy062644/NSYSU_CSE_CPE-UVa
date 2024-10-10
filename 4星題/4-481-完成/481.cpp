#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0;
    vector<int> v;
    while(cin >> n)
    {
        v.push_back(n);
    }
    vector<vector<int>> dp(v.size());
    int arr[v.size()];
    for(int i = 0; i < v.size(); i++)
        arr[i] = -2e8;
    for(int i = 0; i < v.size(); i++)
    {
        auto it = lower_bound(arr, arr+ans, v[i]);
        if(it-arr+1 >= ans)
        {
            ans = it-arr+1;
        }
        arr[it-arr] = v[i];
        if(it-arr)
        {
            dp[it-arr].assign(dp[it-arr-1].begin(), dp[it-arr-1].end());
            dp[it-arr].push_back(v[i]);
        }
        else
        {
            if(dp[0].size())
                dp[0][0] = v[i];
            else
                dp[0].push_back(v[i]);
        }
    }
    cout << ans << "\n-\n";
    for(int i = 0; i < ans; i++)
        cout << dp[ans-1][i] << endl;
    return 0;
}
