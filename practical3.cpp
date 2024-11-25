#include <iostream>
using namespace std;

void state1(string w, int i, int state)
{
    if (w.length() == i)
    {
        if (state == 1 or state == 2 or state == 3 or state == 4)
            cout << "String is Rejected!\n";
        if (state == 6 or state == 7 or state == 9 or state == 10)
            cout << "String is Rejected!\n";
        if (state == 11 or state == 13 or state == 14)
            cout << "String is Rejected!\n";
        if (state == 5 or state == 8 or state == 12 or state == 15)
            cout << "String is Accepted!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            if (state == 1)
                state1(w, i + 1, 2);
            else if (state == 2)
                state1(w, i + 1, 3);
            else if (state == 3)
                state1(w, i + 1, 4);
            else if (state == 4)
                state1(w, i + 1, 5);
            else if (state == 5)
                state1(w, i + 1, 5);
            else if (state == 6)
                state1(w, i + 1, 7);
            else if (state == 7)
                state1(w, i + 1, 7);
            else if (state == 8)
                state1(w, i + 1, 7);
            else if (state == 9)
                state1(w, i + 1, 13);
            else if (state == 10)
                state1(w, i + 1, 10);
            else if (state == 11)
                state1(w, i + 1, 10);
            else if (state == 12)
                state1(w, i + 1, 12);
            else if (state == 13)
                state1(w, i + 1, 13);
            else if (state == 14)
                state1(w, i + 1, 15);
            else if (state == 15)
                state1(w, i + 1, 13);
        if (w[i] == 'b')
            if (state == 1)
                state1(w, i + 1, 9);
            else if (state == 2)
                state1(w, i + 1, 6);
            else if (state == 3)
                state1(w, i + 1, 3);
            else if (state == 4)
                state1(w, i + 1, 3);
            else if (state == 5)
                state1(w, i + 1, 3);
            else if (state == 6)
                state1(w, i + 1, 6);
            else if (state == 7)
                state1(w, i + 1, 8);
            else if (state == 8)
                state1(w, i + 1, 6);
            else if (state == 9)
                state1(w, i + 1, 10);
            else if (state == 10)
                state1(w, i + 1, 11);
            else if (state == 11)
                state1(w, i + 1, 12);
            else if (state == 12)
                state1(w, i + 1, 10);
            else if (state == 13)
                state1(w, i + 1, 14);
            else if (state == 14)
                state1(w, i + 1, 14);
            else if (state == 15)
                state1(w, i + 1, 14);
    }
}
int main()
{
    string w;
    cout << "Enter String : ";
    cin >> w;
    state1(w, 0, 1);
    return 0;
}