#include <string>

using namespace std;

int concat(int x, int y)
{

    string s1 = to_string(x);
    string s2 = to_string(y);

    string s = s1 + s2;

    int z = stoi(s);

    return z;
}