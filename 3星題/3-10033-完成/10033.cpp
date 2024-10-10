#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    getline(cin, str);
    while(t--){
        int reg[10] = {0}, mem[1000] = {0}, pointer = 0, executed = 0;
        while(getline(cin, str) && str != "") {
            mem[pointer++] = stoi(str);
        }
        pointer = 0;
        while(mem[pointer] != 100) {
            executed++;
            int a = mem[pointer]/100, b = mem[pointer]%100/10, c = mem[pointer]%10;
            pointer++;
            if(a == 2) {
                reg[b] = c;
            } else if(a == 3) {
                reg[b] += c;
            } else if(a == 4) {
                reg[b] *= c;
            } else if(a == 5) {
                reg[b] = reg[c];
            } else if(a == 6) {
                reg[b] += reg[c];
            } else if(a == 7) {
                reg[b] *= reg[c];
            } else if(a == 8) {
                reg[b] = mem[reg[c]];
            } else if(a == 9) {
                mem[reg[c]] = reg[b];
            } else if(a == 0) {
                if(reg[c])
                    pointer = reg[b];
            }
            reg[b]%=1000;
        }
        cout << executed+1 << endl << (t > 0 ? "\n":"");
    }
    return 0;
}

/*
1

221
422
425
000
311
712
712
913
031
*/
