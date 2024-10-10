#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        double n = abs(a-b), m = 43200.0 / n * (24 * 60 * 60 - b) / 60;
        int M = (int(round(m + 720))-720) % (12*60) + 720;
        //cout << M << endl;
        printf("%d %d %02d:%02d\n", a, b, (M/60-1)%12+1, int(round(M))%60);
    }
    return 0;
}
