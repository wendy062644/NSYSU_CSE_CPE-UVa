#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int arr[20] = {0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4};
    while(cin >> s && s != "0")
    {
        int n = 0;
        for(char i : s)
        {
            n *= 10;
            n += i-'0';
            n %= 100;
        }
        cout << (arr[n%20] + n/20*4)%10 << endl;
    }
    return 0;
}
