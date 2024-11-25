#include <iostream>
using namespace std;

void state2(string w, int i);
void state3(string w, int i);
void state4(string w, int i);
void state5(string w, int i);

void state1(string w, int i)
{
    if (w.length() == i)
    {
        cout << "String is Rejected!!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state1(w, i + 1);
        if (w[i] == 'b')
            state2(w, i + 1);
    }
}

void state2(string w, int i)
{
    if (w.length() == i)
    {
        cout << "String is Rejected!!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state2(w, i + 1);
        if (w[i] == 'b')
            state3(w, i + 1);
    }
}

void state3(string w, int i)
{
    if (w.length() == i)
    {
        cout << "String is Accepted!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state3(w, i + 1);
        if (w[i] == 'b')
            state4(w, i + 1);
    }
}

void state4(string w, int i)
{
    if (w.length() == i)
    {
        cout << "String is Accepted!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state4(w, i + 1);
        if (w[i] == 'b')
            state5(w, i + 1);
    }
}

void state5(string w, int i)
{
    if (w.length() == i)
    {
        cout << "String is Rejected!!\n";
        return;
    }
    else
    {
        if (w[i] == 'a')
            state5(w, i + 1);
        if (w[i] == 'b')
            state5(w, i + 1);
    }
}

int main()
{
    string w;
    cout << "Enter String : ";
    cin >> w;
    state1(w, 0);
    return 0;
}