#include<bits/stdc++.h>
#define int long long int
using namespace std;
int t, n, a, b;
int arr[48] = {1, 1};
void f(int l, int r, int pos, bool bit)
{
    if(a > r || b < l) //超出邊界 剪枝
        return;
    else if(l == r)
    {
        cout << bit;
        return;
    }
    f(l, l + arr[pos-2]-1, pos-2, bit); //前半 f(n-2)
    f(l + arr[pos-2], r, pos-1, !bit); //後半 f(n-1)
}
signed main() //1, 1, 2, 3, 5, 8, 13, 21, 34
{
    for(int i = 2; i < 48; i++)
    {
        arr[i] = arr[i-2] + arr[i-1];
    }
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b;
        auto it = upper_bound(arr, arr+47, b) - arr;
        it += (n%2 != it%2);
        f(0, arr[it]-1, it, it%2);
        cout << endl;
    }
    return 0;
}
