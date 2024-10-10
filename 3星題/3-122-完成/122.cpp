#include<bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node *R;
    node *L;
    node()
    {
        value = -1;
        R = nullptr;
        L = nullptr;
    }
};

bool isComplete = 1;
queue<node*> q;
vector<int> v;
void print(node *root)
{
    q.pop();
    if(root -> value == -1)
    {
        isComplete = 0;
        return;
    }
    v.push_back(root -> value);
    if(root -> L != nullptr)
        q.push(root -> L);
    if(root -> R != nullptr)
        q.push(root -> R);
    delete(root);
    if(!q.empty())
        print(q.front());
}

int main()
{
    string input;
    int index = 0, n = 0;
    while(cin >> input)
    {
        node *root = new node;
        isComplete = 1;
        while(1)
        {
            node *current = root;
            index = 0;
            n = 0;
            for(index++; input[index] != ','; index++)
            {
                n *= 10;
                n += input[index] - '0';
            }
            for(index++; input[index] != ')'; index++)
            {
                if(input[index] == 'R')
                {
                    if(current -> R == nullptr)
                    {
                        current -> R = new node;
                    }
                    current = current -> R;
                }
                else
                {
                    if(current -> L == nullptr)
                    {
                        current -> L = new node;
                    }
                    current = current -> L;
                }
            }
            if(current -> value != -1)
                isComplete = 0;
            else
                current -> value = n;
            cin >> input;
            if(input == "()")
                break;
        }
        q.push(root);
        print(root);
        if(isComplete)
            for(int i = 0; i < v.size(); i++)
                if(i < v.size()-1)
                    cout << v[i] << ' ';
                else
                    cout << v[i];
        else
            cout << "not complete";
        cout << endl;
        v.clear();
        while(!q.empty())
            q.pop();
    }
    return 0;
}
