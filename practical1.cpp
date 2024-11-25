#include <iostream>
using namespace std;

void state1(string w, int i, int state)
{
    if (w.length() == i)
    {
        if (state == 1 or state == 2 or state == 3)
            cout << "String is Rejected!\n";
        if (state == 4)
            cout << "String is Accepted!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            if (state == 1)
                state1(w, i + 1, 1);
            else if (state == 2)
                state1(w, i + 1, 1);
            else if (state == 3)
                state1(w, i + 1, 1);
            else if (state == 4)
                state1(w, i + 1, 4);
        if (w[i] == 'b')
            if (state == 1)
                state1(w, i + 1, 2);
            else if (state == 2)
                state1(w, i + 1, 3);
            else if (state == 3)
                state1(w, i + 1, 4);
            else if (state == 4)
                state1(w, i + 1, 4);
    }
}

int main()
{
    string w;
    cout << "Enter String : ";
    cin >> w;
    state1(w, 0,1);
    return 0;
}