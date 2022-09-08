#include "convert.h"

Convert::Convert()
{
    //ctor
    Interface();
}

Convert::~Convert()
{
    //dtor
}

int Convert::BinaryToInteger(string binary)
{
    ///********************************************
    vector<int> KeyNums;

    long long int  n =1;

    while(n <9007199254740992)/// this number raises convention accuracy up to 16 digits
    {
        KeyNums.push_back(n);
        n=n*2;
    }
    ///**********************************************

    int length = binary.size();
    int Number=0;
    int count =length;

    for(int x=0;x<length;x++)
    {
        if(binary[x]=='1')
        {
            Number = Number + KeyNums[count-1];
        }
        else if(binary[x]=='0')
        {
        }
        else
        {
            cerr<< "The provided number is not binary"<< endl;
            return 0;
        }
        count--;
    }
    return Number;
}

string Convert::BinaryToText(string binary)
{
    stringstream ss;
    return ss.str();

}

Convert::Convert(const Convert& other)
{
    //copy ctor
}

string Convert::TextToBinary(string text)
{
    /// this Function converts any text to binary
    stringstream ss;

    //these numbers are the key to converting any number to binary;
    int KeyNums[11]={1,2,4,8,16,32,64,128,256,512,1024};

    int length = text.size();
    int List[length]= {0}; // this list store the character number of each character in the text provided

    for(int x=0;x<length;x++)
    {
        // check each character in text and set it to its equivalent number in c++ character list
        char T = text[x];
        char S =0;
        for(int y=0;y<255;y++)
        {
            S=y;
            if(S==T)
            {
                List[x] = y; /// setting list
            }
        }
    }

    ///**************************************************
    /*
        after getting the 1D array of integers of each character in the text provided.
        i will now convert each integer to binary and later display the each binary number.
        Note!!! each integer represent a character in the character list.
    */
    ///**************************************************

    for(int x=0;x<length;x++)
    {
        ss<<"0"; /// for some reason binary conversions start with a zero;
        int number;
        number = List[x];

        int Count = 0;
        int term=0; /// this gives us the term we start in on the 1D array of KeyNumbers

        while(KeyNums[Count] <= number)
        {
            term = Count;
            Count++;
        }

        int temp;
        int total = number;

        ///this is the calculation that pushes back a zero or one to the binary number
        for(int x=term;x>=0;x--)
        {
            //i used the mathematical conversion to binary
            //i minused a keyNumber from the total, it i get a zero then i stopp then and there
            if((total - KeyNums[x]) >=0)
            {
                temp = total-KeyNums[x];
                ss << "1";
                total = temp;
            }
            else
            {
                ss<<"0";
            }
        }
        ss<< " ";
    }

    return "Binary Number: "+ ss.str();
}

string Convert::IntegerToBinary(int integer)
{

    /// this Function converts any text to binary
    stringstream ss;

    //these numbers are the key to converting any number to binary;
    vector<int> KeyNums;

    long long int  n =1;

    while(n <9007199254740992)/// this number raises convention accuracy up to 16 digits
    {
        KeyNums.push_back(n);
        n=n*2;
    }

    ss<<"0"; /// for some reason binary conversions start with a zero;
    int number= integer;
    int Count = 0;
    int term=0; /// this gives us the term we start in on the 1D array of KeyNumbers

    while(KeyNums[Count] <= number)
    {
        term = Count;
        Count++;
    }

    int temp;
    int total = number;

    ///this is the calculation that pushes back a zero or one to the binary number
    for(int x=term;x>=0;x--)
    {
        //i used the mathematical conversion to binary
        //i minused a keyNumber from the total, it i get a zero then i stopp then and there
        if((total - KeyNums[x]) >=0)
        {
            temp = total-KeyNums[x];
            ss << "1";
            total = temp;
        }
        else
        {
            ss<<"0";
        }
    }
    ss<< " ";

    return "Binary Number: "+ss.str();
}

void Convert::Interface()
{
    bool Continue = true;
    char letter;

    do
    {
        system("cls");
        cout << "-------Convert Stuff To and From Binary!!-------"<< endl;
        cout << "Enter an Equavalent letter for an option"<< endl;
        cout << "T - Convert Text to binary"<<endl;
        cout << "N - Convert a Number to Binary"<<endl;
        cout << "B - Convert Binary Number to Integer"<< endl;
        cout << "S - Convert Binary Number to Text" << endl;
        cout << "X - Exit"<< endl;

        cout << endl;
        cin >> letter;

        switch(letter)
        {
        case 'x':
        case 'X':
            Continue = false;
            break;
        case 'T':
        case 't':
            {
                string text;
                cout << "Enter the text you wish to convert"<< endl;

                cin.clear();
                std::cin.ignore();
                getline(cin,text);
                cout <<TextToBinary(text)<< endl;
                system("Pause");

                break;
            }
        case 'N':
        case 'n':
            {
                int number;
                string nu;
                cout << "Enter the number you want to convert"<< endl;
                cin.clear();
                std::cin.ignore();
                getline(cin,nu);
                stringstream ss;
                ss<< nu;
                ss>> number;
                cout <<IntegerToBinary(number)<< endl;
                system("Pause");
            }
            break;
        case 'b':
        case 'B':
            {
                string binary;
                cin.clear();
                cin.ignore();
                cout << "Enter the binary code"<< endl;
                getline(cin,binary);
                cout <<"The integer conversion is '" <<BinaryToInteger(binary)<<"'."<< endl;
                system("pause");
                break;
            }
        case 's':
        case 'S':
            cout << "Sorry i am current working on this function"<< endl;
            system("pause");
            break;
        default:
            cout << "Wrong Command!!"<< endl;
            break;
        }

    }
    while(Continue == true);
}
