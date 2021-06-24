#ifndef FUNCTII_H
#define FUNCTII_H

#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Functii
{
    public:
        static vector<string> split(string s, string delimiter);
        static string to_string_with_precision(const float a_value, const int n = 6);
        static string ivector_to_string(vector<int> input, string separator);
};

#endif // FUNCTII_H
