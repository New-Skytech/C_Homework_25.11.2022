#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inf;
    ofstream outf;
    inf.open("INPUT.txt");
    outf.open("OUTPUT.txt");
    int trees;
    inf >> trees;
    if (trees < 2) {
        outf << trees;
    }
    else {
        outf << (3 * pow(2, trees - 1));
    }
    inf.close();
    outf.close();
}
