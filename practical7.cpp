#include <iostream>
#include <stack>
using namespace std;

void pda(string w)
{
    stack<char> s;
    bool flag = false;
    for (int i = 0; i < w.length(); i++)
    {
        if (flag and w[i] == 'a')
            break;
        if (!flag and w[i] == 'a')
            s.push(w[i]);
        else if (w[i] == 'b')
        {
            flag = true;
            s.pop();
        }
    }

    s.empty() ? cout << "String is Accepted!\n" : cout << "String is Rejected!\n";
}

int main()
{
    string w;
    cout << "Enter a String : ";
    cin >> w;

    pda(w);
    return 0;
}