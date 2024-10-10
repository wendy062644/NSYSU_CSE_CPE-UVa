#include<bits/stdc++.h>
using namespace std;
long long int n, arr[1000001] = {0};
int main()
{
    for(long long int i = 4; i < 1000001; i++)
    {
        arr[i] = arr[i-1] + ((i-1) * (i-2)/2 - (i-1)/2)/2;
    }
    while(cin >> n && n > 2)
    {
        cout << arr[n] << endl;
    }
    return 0;
}
