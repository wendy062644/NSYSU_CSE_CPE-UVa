#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        int arr[n], r, l = 1, Min = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            r += arr[i];
            Min = max(Min, arr[i]);
        }
        while(l < r)
        {
            int mid = (r+l)/2, now = 0, times = 0;
            for(int i = 0; i < n; i++)
            {
                if(now + arr[i] > mid)
                {
                    now = arr[i];
                    times++;
                }
                else
                    now += arr[i];
            }
            if(times >= m)
                l = mid+1;
            else
                r = mid;
        }
        if(Min > l)
            cout << Min << endl;
        else
            cout << l << endl;
    }
    return 0;
}
