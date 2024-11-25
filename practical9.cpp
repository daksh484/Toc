#include <iostream>
#include <vector>
using namespace std;

class TuringMachine
{
    vector<char> tape;
    size_t head;
public:
    TuringMachine() : head(0), tape(1, '_') {}

    // Write
    // Read
    // Left Move
    // Right Move
    // Print Tape

    char readTape()
    {
        return tape[head];
    }

    void writeTape(const char symbol)
    {
        tape[head] = symbol;
    }

    void moveLeft()
    {
        if (head > 0)
            head--;
    }

    void moveRight()
    {
        head++;
        if (head >= tape.size())
            tape.push_back('_');
    }

    void printTape()
    {
        for (int i = 0; i < tape.size(); i++)
            cout << tape.at(i) << " ";
        cout << endl;
    }
};

class TuringMachineLogic
{
    string str;
    TuringMachine tm;

public:
    TuringMachineLogic(string str)
    {
        this->str = str;
        for (int i = 0; i < str.length(); i++)
        {
            tm.moveRight();
            tm.writeTape(str[i]);
        }
        tm.moveRight();
        for (int i = 0; i < str.length() + 1; i++)
            if (tm.readTape() != '_' or i == 0)
                tm.moveLeft();
    }

    bool process()
    {
        int result = 0, flag = 2;

        tm.moveRight();
        for (int i = 0; i < str.length() * (str.length() / 3 + 1); i++)
        {
            if (result == 0 and flag == 2)
            {
                flag = state1(str, i % (str.length() - 1));
                if (flag == 1)
                    result = 1, flag = 2;
            }
            else if (result == 1 and flag == 2)
            {
                flag = state2(str, i % (str.length() - 1));
                if (flag == 1)
                    result = 2, flag = 2;
            }
            else if (result == 2 and flag == 2)
            {
                flag = state3(str, i % (str.length() - 1));
                if (flag == 1)
                    result = 4, flag = 2;
            }
            else if (result == 4 and flag == 2)
            {
                for (int j = 0; j < str.length(); j++)
                {
                    if (tm.readTape() != '_' or j == 0)
                        tm.moveLeft();
                }
                result = 0;
                tm.moveRight();
            }
            if (!flag)
                break;
        }

        return flag ? true : false;
    }

    int state1(string str, int i)
    {
        int f = 2;
        if (tm.readTape() == 'd')
        {
            tm.moveRight();
            f = 2; // successfully right move
        }
        else if (tm.readTape() == 'a')
        {
            tm.writeTape('d');
            tm.moveRight();
            f = 1; // successfully write and right move
        }
        else if (tm.readTape() == 'b' or tm.readTape() == 'c')
            f = 0;
        return f;
    }
    int state2(string str, int i)
    {
        int f;
        if (tm.readTape() == 'a' or tm.readTape() == 'd')
        {
            tm.moveRight();
            f = 2;
        }
        else if (tm.readTape() == 'b')
        {
            tm.writeTape('d');
            tm.moveRight();
            return 1;
        }
        else if (tm.readTape() == '_' or tm.readTape() == 'c')
            f = 0;

        return f;
    }
    int state3(string str, int i)
    {
        int f;
        if (tm.readTape() == 'b' or tm.readTape() == 'd')
        {
            tm.moveRight();
            f = 2;
        }
        else if (tm.readTape() == 'c')
        {
            tm.writeTape('d');
            tm.moveRight();
            f = 1;
        }
        else if (tm.readTape() == 'a' or tm.readTape() == '_')
            f = 0;

        return f;
    }
};

int main()
{
    string str;
    cout << "Enter String : ";
    cin >> str;
    TuringMachineLogic tml(str);
    tml.process() ? cout << "String is Accepted!\n" : cout << "String is Rejected!\n";

    return 0;
}