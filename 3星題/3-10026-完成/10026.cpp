#include<bits/stdc++.h>
using namespace std;
struct Case{
    int days, pay, n;
    double percent;
};

bool cmp(Case a, Case b)
{
    if(a.percent == b.percent)
        return a.n < b.n;
    return a.percent > b.percent;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        Case arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i].days >> arr[i].pay;
            arr[i].n = i+1;
            arr[i].percent = double(arr[i].pay) / arr[i].days;
        }
        sort(arr, arr+n, cmp);
        for(int i = 0; i < n; i++)
            cout << arr[i].n << (i < n-1?" ":"");
        cout << "\n" << (t?"\n":"");
    }
    return 0;
}
