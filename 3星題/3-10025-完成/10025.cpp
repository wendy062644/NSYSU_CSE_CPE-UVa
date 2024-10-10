#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        int sum = 0, i = 1;
        cin >> n;
        if(!n)
            cout << 3 << endl;
        else
        {
            while(1)
            {
                sum += i;
                if(sum == abs(n) || (abs(abs(n)-sum)%2 == 0 && sum > abs(n)))
                    break;
                i++;
            }
            cout << i << endl;
        }
        if(t)
            cout << endl;
    }
    return 0;
}
