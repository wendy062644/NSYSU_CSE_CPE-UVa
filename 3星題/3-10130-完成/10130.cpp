#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, l;
    cin >> t;
    while(t--) {
        cin >> n;
        int w[n], p[n], sum = 0;
        for(int i = 0; i < n; i++)
            cin >> p[i] >> w[i];
        cin >> m;
        int arr[1000] = {0};
        for(int j = 0; j < n; j++) {
            for(int k = 999; k > 0; k--) {
                if(k >= w[j]) {
                    arr[k] = max(arr[k], arr[k-w[j]] + p[j]);
                }
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> l;
            sum += arr[l];
        }
        cout << sum << endl;
    }
    return 0;
}
