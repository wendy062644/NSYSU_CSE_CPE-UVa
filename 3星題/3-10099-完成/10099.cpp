#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, t = 1, a, b, c;
    while(cin >> n >> m && n*m) {
        cout << "Scenario #" << t++ << endl;
        int arr[n+1][n+1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                arr[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            arr[a][b] = c;
            arr[b][a] = c;
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    arr[i][j] = max(arr[i][j], min(arr[i][k], arr[k][j]));
                }
            }
        }
        cin >> a >> b >> c;
        cout << "Minimum Number of Trips = " << ceil(c*1.0/(arr[a][b]-1)) << endl << endl;
    }
    return 0;
}
