#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Open file
    ifstream inputFile("problem-13/numbers.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    vector<string> lines;

    // Fill lines with values
    string line;
    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }

    const int lineLength = lines.at(0).length();

    int carryOver = 0;
    string result = "";

    for (int strIndex = lineLength - 1; strIndex >= 0; strIndex--)
    {
        int columnSum = carryOver;
        for (string line : lines)
        {
            columnSum += int(line[strIndex] - '0');
        }

        // Split between digit and carry over
        string digit = to_string(columnSum % 10);
        carryOver = columnSum / 10;

        // Append to beginning of resulting string
        result = digit + result;
    }

    // Append left over carry over to beginning of the result
    result = to_string(carryOver) + result;

    cout << result.substr(0, 10) << endl;
}