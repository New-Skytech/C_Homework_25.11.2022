#include <iostream>
#include <fstream>

using namespace std;

#include <iostream>
#include <cmath>

int convert(int x)
{
    int result = 0;

    for (int i = 0; x != 0; i++) {
        result += (x % 10) * pow(3, i);
        x /= 10;
    }
    return result;
}


int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("INPUT.txt");
    fout.open("OUTPUT.txt");
    int first, second, result;
    fin >> first >> second;
    result = convert(first) + convert(second);
    fout << result;
}
