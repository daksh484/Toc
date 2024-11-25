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
        tm.moveRight();
        tm.writeTape('0');
        for (int i = 0; i < str.length(); i++)
        {
            tm.moveRight();
            tm.writeTape(str[i]);
        }
        tm.moveRight();
    }

    string process()
    {
        string result = "";
        tm.moveLeft();
        for (int i = 0; i <= str.length(); i++)
        {
            if (tm.readTape() == '0')
            {
                tm.writeTape('1');
                break;
            }
            else if (tm.readTape() == '1')
            {
                tm.writeTape('0');
                tm.moveLeft();
            }
        }

        // Head Move Left Starting Point
        for (int i = 0; i < str.length(); i++)
        {
            if (tm.readTape() != '_')
                tm.moveLeft();
        }

        // Data Store in Variable with moving head
        tm.moveRight();
        for (int i = 0; i <= str.length(); i++)
        {
            if (tm.readTape() != '_')
            {
                result += tm.readTape();
                tm.moveRight();
            }
        }
        return result;
    }
};

int main()
{
    string str;
    cout << "Enter String : ";
    cin >> str;
    TuringMachineLogic tml(str);
    cout <<"After incrementing the binary number by 1 "<<str<<" : "<< tml.process();
    
    return 0;
}