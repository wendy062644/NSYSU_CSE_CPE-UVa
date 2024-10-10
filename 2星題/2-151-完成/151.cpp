#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        int m = 0, now = 0;
        if(!n)
            break;
        while(++m)
        {
            now = 0;
            for(int i = 1; i < n; i++)
                now = (now + m)%i;
            if(now == 11)
                break;
        }
        cout << m << endl;
    }
    return 0;
}
