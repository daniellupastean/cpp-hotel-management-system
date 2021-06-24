#include "Functii.h"
#include <sstream>

vector<string> Functii::split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos)
    {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

string Functii::to_string_with_precision(const float a_value, const int n)
{
    ostringstream out;
    out.precision(n);
    out << fixed << a_value;
    return out.str();
}

string Functii::ivector_to_string(vector<int> input, string separator)
{
    string s;
    for (int element: input) {
        s+= to_string(element) + separator;
    }
    s.pop_back();
    return s;
}


