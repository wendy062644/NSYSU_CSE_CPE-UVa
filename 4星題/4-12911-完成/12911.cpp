#include<bits/stdc++.h>
#define int long long int
using namespace std;
int v[40], n, p, input, is_b, sum = 0;
map<int, int> ma, mb;
void f(int sum, int a, int b)
{
    if(a == b)
    {
        if(is_b)
            mb[sum]++;
        else
            ma[sum]++;
        return;
    }
    f(sum + v[a], a+1, b);
    f(sum, a+1, b);
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(cin >> n >> p)
    {
        is_b = 0;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        f(0, 0, n/2);
        is_b = 1;
        f(0, n/2, n);
        for(auto i : ma)
        {
            sum += i.second * mb[p-i.first];
        }
        cout << (p?sum : sum-1) << endl;
        ma.clear();
        mb.clear();
    }
    return 0;
}
