#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * From: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c#answer-46931770
 * */
vector<string> split(const string &s, const string &delimiter)
{
    vector<string> tokens;
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        tokens.push_back(token);
    }
    tokens.push_back(s.substr(pos_start));

    return tokens;
}

int main()
{
    string data;

    // Open file with sequence
    ifstream File("problem-8/sequence.txt");

    // Read from the file
    getline(File, data);

    // Split on 0 because any segment with a 0 cannot be the largest
    vector<string> sequences = split(data, "0");

    int64_t maxProduct = 0;

    for (auto sequence : sequences)
    {
        if (sequence.length() < 13)
            continue;

        int64_t product = 1;
        int baseIndex = 0; // Tracks the index of the first digit being used within the token
        int index = 0;
        for (auto character : sequence)
        {
            // Convert character to numerical value
            int64_t digit = character - '0';

            if (index < 13)
            {
                product *= digit;

                if (index != 12)
                {
                    index++;
                    // Do not check product against max product
                    continue;
                }
            }
            else
            {
                int64_t baseDigit = sequence[baseIndex] - '0';
                // Remove base from product
                product /= baseDigit;

                product *= digit;
                baseIndex++;
            }

            if (maxProduct < product)
            {
                maxProduct = product;
            }

            index++;
        }
    }

    cout << maxProduct << endl;

    File.close();

    return 0;
}