#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while(cin >> n && n)
    {
        vector<int> v(n);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for(int i = 1; i < n; i++)
        {
            m = v[0] + v[1];
            sum += m;
            v.erase(v.begin());
            v.erase(v.begin());
            auto mid = lower_bound(v.begin(), v.end(), m);
            if(v.size())
                v.insert(mid, m);
        }
        cout << sum << endl;
    }
    return 0;
}
