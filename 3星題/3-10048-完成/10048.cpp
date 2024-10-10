#include<bits/stdc++.h>
using namespace std;
int main()
{
    int C, s, q, t = 1, a, b, c, had_print = 0;
    while(cin >> C >> s >> q && C*s*q) {
        if(had_print)
            cout << endl;
        cout << "Case #" << t++ << endl;
        int arr[C+1][C+1];
        for(int i = 1; i <= C; i++) {
            for(int j = 1; j <= C; j++) {
                arr[i][j] = 1e9;
            }
        }
        for(int i = 0; i < s; i++) {
            cin >> a >> b >> c;
            arr[a][b] = c;
            arr[b][a] = c;
        }
        for(int k = 1; k <= C; k++) {
            for(int i = 1; i <= C; i++) {
                for(int j = 1; j <= C; j++) {
                    arr[i][j] = min(arr[i][j], max(arr[i][k], arr[k][j]));
                }
            }
        }
        for(int i = 0; i < q; i++) {
            cin >> a >> b;
            if(arr[a][b] == 1e9)
                cout << "no path" << endl;
            else
                cout << arr[a][b] << endl;
        }
        had_print = 1;
    }
    return 0;
}
