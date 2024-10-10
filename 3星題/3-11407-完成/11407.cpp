#include<bits/stdc++.h>
using namespace std;
int arr[10001], n, input;
int main()
{
    for(int i = 1; i < 10001; i++)
    {
        arr[i] = 1e5;
        for(int j = 1; j <= sqrt(i); j++)
        {
            arr[i] = min(arr[i], arr[i-j*j] + 1);
        }
    }
    cin >> n;
    while(n--)
    {
        cin >> input;
        cout << arr[input] << endl;
    }
    return 0;
}
