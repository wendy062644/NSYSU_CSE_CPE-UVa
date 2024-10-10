#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin >> n && n) {
        long long int arr[1000] = {1}, l = 0;
        for(int i = n+2; i <= n*2; i++) {
            for(int j = 0; j <= l; j++) {
                arr[j] *= i;
            }
            for(int j = 0; j < l; j++) {
                if(arr[j] > 9){
                    arr[j+1] += arr[j]/10;
                    arr[j] %= 10;
                }
            }
            while(arr[l] > 9) {
                arr[l+1] = arr[l]/10;
                arr[l] %= 10;
                l++;
            }
        }
        for(int i = l; i >= 0; i--)
            cout << arr[i];
        cout << endl;
    }
    return 0;
}
