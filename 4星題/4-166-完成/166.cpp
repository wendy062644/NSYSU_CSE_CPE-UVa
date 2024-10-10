#include<bits/stdc++.h>
#define l 1e8
using namespace std;
int main()
{
    int n[6], money[6] = {5, 10, 20, 50, 100, 200}, a, b, index = 5;
    char temp;
    int change[501] = {0};
    for(int i = 5; i < 501; i += 5)
    {
        change[i] = l;
        for(int j = 0; j < 6; j++)
        {
            if(i >= money[j])
                change[i] = min(change[i], change[i- money[j]]+1);
        }
    }
    while(cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4] >> n[5])
    {
        int payment[501] = {0}, ans = l;
        for(int i = 1; i < 501; i++)
            payment[i] = l;
        if(!n[0] && !n[1] && !n[2] && !n[3] && !n[4] && !n[5])
            break;
        cin >> a >> temp >> b;
        a = a * 100 + b;
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < n[i]; j++)
            {
                for(int k = 500; k >= money[i]; k -= 5)
                {
                    payment[k] = min(payment[k], payment[k-money[i]]+1);
                }
            }
        }
        for(int i = a; i < 501; i += 5)
            ans = min(ans, payment[i] + change[i - a]);
        cout << setw(3) << ans << endl;
    }
    return 0;
}
