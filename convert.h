#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


class Convert
{
    /// this class lets you convert data to binary
    public:
        Convert();
        ~Convert();
        Convert(const Convert& other);
        void Interface();
        string TextToBinary(string text);
        string IntegerToBinary(int integer );
        int BinaryToInteger(string binary);
        string BinaryToText(string binary);

    protected:

    private:
};

#endif // CONVERT_H
