#include <vector>
#include <string>

using namespace std;

/**
 * From: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c#answer-46931770
 * */
vector<string> StringSplit(const string &s, const string &delimiter)
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