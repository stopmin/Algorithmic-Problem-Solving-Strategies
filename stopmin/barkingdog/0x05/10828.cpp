//
// Created by 정지민 on 8/15/24.
//

#include <bits/stdc++.h>
using namespace std;
int main(void) {
    stack<int> s;
    int N;
    cin >> N;

    while (N--) {
        string op;
        cin>>op;
        if(op == "push"){
            int i;
            cin>>i;
            s.push(i);
        }
        else if (op == "top"){
            if (s.empty()) cout << "-1\n";
            else cout<<s.top()<<"\n";
        } else if (op == "size") {
            cout<<s.size()<<"\n";
        } else if (op == "pop") {
            if (s.empty()) cout << "-1\n";
            else {
                cout<<s.top()<<"\n";
                s.pop();
            }
        } else if (op == "empty") {
            if (s.empty()) cout<<"1\n";
            else cout << "0\n";
        }
    }
}