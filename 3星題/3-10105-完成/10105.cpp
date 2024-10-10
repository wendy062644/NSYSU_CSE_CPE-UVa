#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, m, arr[14] = {1}, input;
    for(int i = 1; i < 14; i++) {
        arr[i] = arr[i-1] * i;
    }
    while(cin >> n >> m) {
        int ans = arr[n];
        for(int i = 0; i < m; i++) {
            cin >> input;
            ans /= arr[input];
        }
        cout << ans << endl;
    }
    return 0;
}
