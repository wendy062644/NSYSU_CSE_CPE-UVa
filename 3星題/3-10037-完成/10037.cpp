#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, input, had_print = 0;
    cin >> t;
    while(t--) {
        if(had_print)
            cout << endl;
        cin >> n;
        vector<int> v(n);
        int sum = 0, i;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        stringstream ss;
        for(i = v.size()-1; i >= 3; i-=2) {
            int a = v[1] + v[i] + v[0] + v[1];
            int b = v[i-1] + v[0] + v[i] + v[0];
            if(a > b){
                sum += b;
                ss << v[0] << " " << v[i-1] << "\n" << v[0] << "\n" << v[0] << " " << v[i] << "\n" << v[0] << "\n";
            }
            else {
                sum += a;
                ss << v[0] << " " << v[1] << "\n" << v[0] << "\n" << v[i-1] << " " << v[i] << "\n" << v[1] << "\n";
            }
        }
        if(i == 1) {
            cout << sum+v[1] << endl;
            cout << ss.str() << v[0] << " " << v[1] << endl;
        } else if(i == 0) {
            cout << sum+v[0] << endl;
            cout << ss.str() << v[0] << endl;
        }
        else {
            cout << sum+v[1]+v[0]+v[2] << endl;
            cout << ss.str() << v[0] << " " << v[1] << endl << v[0] << endl << v[0] << " " << v[2] << endl;
        }
        had_print = 1;
    }
    return 0;
}
