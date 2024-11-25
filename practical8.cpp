#include <iostream>
#include <stack>
using namespace std;

bool pda(string w)
{
    stack<char> s;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < w.length(); i++)
    {
        if (!flag and (w[i] == 'a' or w[i] == 'b'))
            s.push(w[i]);
        else if (ispunct(w[i]))
            flag = true;
        else if (flag and s.empty() and (w[i] == 'a' or w[i] == 'b'))
            break;
        else if (flag and (w[i] == 'a' or w[i] == 'b'))
            if (w[i] == s.top())
                s.pop();
            else
                break;
        count++;
    }

    return s.empty() and flag and count == w.length() ? true : false;
}

int main()
{
    string str;
    bool checkPDA;
    cout << "Enter a String : ";
    cin >> str;
    checkPDA = pda(str);
    checkPDA ? cout << "String is Accepted!\n" : cout << "String is Rejected!\n";
    return 0;
}