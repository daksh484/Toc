#include <iostream>
using namespace std;

// a. Union of the languages L1 and L2
void UState(string w, int i, int state)
{
    if (w.length() == i)
    {
        if (state == 1 or state == 2 or state == 3 or state == 4)
            cout << "String is Rejected!\n";
        else if (state == 8 or state == 12 or state == 9 or state == 10 or state == 13)
            cout << "String is Rejected!\n";
        else if (state == 5 or state == 6 or state == 7 or state == 11 or state == 14)
            cout << "String is Accepted!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            if (state == 1)
                UState(w, i + 1, 2);
            else if (state == 2)
                UState(w, i + 1, 3);
            else if (state == 3)
                UState(w, i + 1, 4);
            else if (state == 4)
                UState(w, i + 1, 5);
            else if (state == 5)
                UState(w, i + 1, 5);
            else if (state == 6)
                UState(w, i + 1, 4);
            else if (state == 7)
                UState(w, i + 1, 4);
            else if (state == 8)
                UState(w, i + 1, 12);
            else if (state == 9)
                UState(w, i + 1, 9);
            else if (state == 10)
                UState(w, i + 1, 9);
            else if (state == 11)
                UState(w, i + 1, 9);
            else if (state == 12)
                UState(w, i + 1, 12);
            else if (state == 13)
                UState(w, i + 1, 14);
            else if (state == 14)
                UState(w, i + 1, 12);
        if (w[i] == 'b')
            if (state == 1)
                UState(w, i + 1, 8);
            else if (state == 2)
                UState(w, i + 1, 6);
            else if (state == 3)
                UState(w, i + 1, 7);
            else if (state == 4)
                UState(w, i + 1, 7);
            else if (state == 5)
                UState(w, i + 1, 7);
            else if (state == 6)
                UState(w, i + 1, 6);
            else if (state == 7)
                UState(w, i + 1, 7);
            else if (state == 8)
                UState(w, i + 1, 9);
            else if (state == 9)
                UState(w, i + 1, 10);
            else if (state == 10)
                UState(w, i + 1, 11);
            else if (state == 11)
                UState(w, i + 1, 11);
            else if (state == 12)
                UState(w, i + 1, 13);
            else if (state == 13)
                UState(w, i + 1, 13);
            else if (state == 14)
                UState(w, i + 1, 13);
    }
}

// b. Intersection of the languages L1 and L2
void IState(string w, int i, int state)
{
    if (w.length() == i)
    {
        if (state == 1 or state == 2 or state == 3 or state == 4 or state == 6)
            cout << "String is Rejected!\n";
        else if (state == 5)
            cout << "String is Accepted!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            if (state == 1)
                IState(w, i + 1, 2);
            else if (state == 2)
                IState(w, i + 1, 6);
            else if (state == 3)
                IState(w, i + 1, 4);
            else if (state == 4)
                IState(w, i + 1, 5);
            else if (state == 5)
                IState(w, i + 1, 4);
            else if (state == 6)
                IState(w, i + 1, 6);
        if (w[i] == 'b')
            if (state == 1)
                IState(w, i + 1, 6);
            else if (state == 2)
                IState(w, i + 1, 3);
            else if (state == 3)
                IState(w, i + 1, 3);
            else if (state == 4)
                IState(w, i + 1, 5);
            else if (state == 5)
                IState(w, i + 1, 3);
            else if (state == 6)
                IState(w, i + 1, 6);
    }
}

void CState(string w, int i, int state)
{
    if (w.length() == i)
    {
        if (state == 1 or state == 2 or state == 3 or state == 4 or state == 5)
            cout << "String is Rejected!\n";
        else if (state == 6 or state == 7 or state == 11 or state == 13)
            cout << "String is Rejected!\n";
        else if (state == 16 or state == 17 or state == 15)
            cout << "String is Rejected!\n";
        else if (state == 8 or state == 12 or state == 9 or state == 10 or state == 13)
            cout << "String is Rejected!\n";
        else if (state == 14)
            cout << "String is Accepted!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            if (state == 1)
                CState(w, i + 1, 2);
            else if (state == 2)
                CState(w, i + 1, 3);
            else if (state == 3)
                CState(w, i + 1, 4);
            else if (state == 4)
                CState(w, i + 1, 5);
            else if (state == 5)
                CState(w, i + 1, 13);
            else if (state == 6)
                CState(w, i + 1, 7);
            else if (state == 7)
                CState(w, i + 1, 6);
            else if (state == 8)
                CState(w, i + 1, 13);
            else if (state == 9)
                CState(w, i + 1, 15);
            else if (state == 10)
                CState(w, i + 1, 10);
            else if (state == 11)
                CState(w, i + 1, 10);
            else if (state == 12)
                CState(w, i + 1, 13);
            else if (state == 13)
                CState(w, i + 1, 13);
            else if (state == 14)
                CState(w, i + 1, 13);
            else if (state == 15)
                CState(w, i + 1, 15);
            else if (state == 16)
                CState(w, i + 1, 17);
            else if (state == 17)
                CState(w, i + 1, 13);
        if (w[i] == 'b')
            if (state == 1)
                CState(w, i + 1, 9);
            else if (state == 2)
                CState(w, i + 1, 6);
            else if (state == 3)
                CState(w, i + 1, 3);
            else if (state == 4)
                CState(w, i + 1, 3);
            else if (state == 5)
                CState(w, i + 1, 3);
            else if (state == 6)
                CState(w, i + 1, 6);
            else if (state == 7)
                CState(w, i + 1, 8);
            else if (state == 8)
                CState(w, i + 1, 6);
            else if (state == 9)
                CState(w, i + 1, 10);
            else if (state == 10)
                CState(w, i + 1, 11);
            else if (state == 11)
                CState(w, i + 1, 12);
            else if (state == 12)
                CState(w, i + 1, 10);
            else if (state == 13)
                CState(w, i + 1, 14);
            else if (state == 14)
                CState(w, i + 1, 14);
            else if (state == 15)
                CState(w, i + 1, 16);
            else if (state == 16)
                CState(w, i + 1, 15);
            else if (state == 17)
                CState(w, i + 1, 15);
    }
}

int main()
{
    string w;
    cout << "Enter String : ";
    cin >> w;
    UState(w, 0, 1);
    return 0;
}