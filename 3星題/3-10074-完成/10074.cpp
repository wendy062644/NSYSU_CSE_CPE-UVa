#include<bits/stdc++.h>
using namespace std;
void f(int a, int b) {
    int n = a, m = b, ans = 0;
    int arr[n][m], num[n+1][m+1];
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(j != 0)
                arr[i][j] += arr[i][j-1];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0)
                num[i+1][j+1] = arr[i][j];
            else if(i == 0)
                num[i+1][j+1] = arr[i][j];
            else if(j == 0)
                num[i+1][j+1] = num[i][j+1] + arr[i][j];
            else
                num[i+1][j+1] = arr[i][j] + num[i][j+1];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = i; k <= n; k++) {
                for(int l = j; l <= m; l++) {
                    if(num[k][l] + num[i-1][j-1] - num[k][j-1] - num[i-1][l] == 0) {
                        ans = max(ans, (k-i+1)*(l-j+1));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int a, b;
    while(cin >> a >> b && a*b) {
        f(a, b);
    }
    return 0;
}
