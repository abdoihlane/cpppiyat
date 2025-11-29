#include <iostream>
#include <string>

using namespace std;

int main()
{
    string  ss = "HI THI IS BRAIN";
    string *stringPTR = &ss;
    string &stringREF = ss;

    cout << &ss << endl;
    cout << stringPTR << endl;
    cout << &stringREF << endl;

    cout << ss << endl;
    cout << *stringPTR << endl;
    cout << stringREF << endl;
}
