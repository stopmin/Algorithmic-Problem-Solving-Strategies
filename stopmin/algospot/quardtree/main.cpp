#include <iostream>
#include <string>
using namespace std;

string reserse_(string::iterator &it) {
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w') {
        return string(1, head);
    }
    string upperLeft = reserse_(it);
    string upperRight = reserse_(it);
    string lowerLeft = reserse_(it);
    string lowerRight = reserse_(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        string compressed;
        cin >> compressed;
        string::iterator it = compressed.begin();
        cout << reserse_(it) << endl;
    }
    return 0;
}
