#include<bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> v;
    for(int i = 2; i <= 100; i++)
    {
        bool isPrime = 1;
        for(int j = 2; j <= sqrt(i); j++)
            if(i%j == 0)
            {
                isPrime = 0;
                break;
            }
        if(isPrime)
            v.push_back(i);
    }
    int n;
    while(cin >> n)
    {
        if(!n)
            break;
        cout << setw(3) << n << "! =";
        int arr[100] = {0}, Max = 0;
        for(int i = 2; i <= n; i++)
        {
            int n = i;
            while(n-1)
            {
                for(int j = 0; j < v.size(); j++)
                {
                    while(n%v[j] == 0)
                    {
                        n /= v[j];
                        arr[v[j]]++;
                        Max = max(Max, j);
                    }
                }
            }
        }
        for(int i = 0; i <= Max; i++)
        {
            if(i == 15)
                cout << "\n      ";
            cout << setw(3) << arr[v[i]];
        }
        cout << endl;
    }
    return 0;
}
