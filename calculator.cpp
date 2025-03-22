#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
    float result = 0;
    bool first = true;

    // Put text file in append mode
    ofstream outFile("calculator.txt", ios::app);

    // Check if there is a file to open
    if (!outFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    cout << "Welcome to the C++ calculator!" << endl;
    cout << "q to quit\nc to clear\nd to delete history\nl to load history\nEnter an expression:" << endl;

    // Main calculator loop
    while (true)
    {
        cout << ">> ";

        // Get input
        string input;
        getline(cin, input);

        outFile << ">> " << input << endl;

        // Quits program
        if (input == "q")
        {
            cout << "Program terminated." << endl;
            break;
        }

        // Clears result
        if (input == "c")
        {
            result = 0;
            first = true;
            cout << "Result cleared." << endl;
            continue;
        }

        // Clears history file
        if (input == "d")
        {
            ofstream outFile("calculator.txt");
            cout << "History cleared." << endl;
            continue;
        }

        // Load and read history file
        if (input == "l")
        {
            ifstream file("calculator.txt");

            if (!file)
            {
                cerr << "Error opening file!" << endl;
                return 1;
            }

            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }

            file.close();

            continue;
        }

        stringstream ss(input);
        float x, y;
        char op;

        // If it is the first time after running or clearing
        // use 2 variables and an operator
        if (first)
        {
            ss >> x >> op >> y;

            result = x;
            first = false;
        }
        else
        {
            ss >> op >> y;
        }

        // Checks for valid input
        if (ss.fail()) {
            cout << "Invalid input format, try again." << endl;
            continue;
        }

        // Checks operators and performs operations based on
        // them
        switch (op)
        {
            case '+':
                result += y;
                break;
            case '-':
                result -= y;
                break;
            case '*':
                result *= y;
                break;
            case '/':
                if (y == 0)
                {
                    cout << "Undefined (divide by 0)" << endl;
                    continue;
                }

                result /= y;
                break;

            case '^':
                if (!first)
                {
                    x = result;
                }

                result = pow(x, y);
                break;

            default:
                cout << "Invalid operator, try again. (+ - * / ^)" << endl;
                continue;
        }

        // Prints and saves result to history
        cout << result << endl;
        outFile << result << endl;
    }
    
    return 0;
}