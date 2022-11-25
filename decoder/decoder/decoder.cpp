#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    ifstream inf;
    ofstream outf;
    inf.open("INPUT.txt");
    outf.open("OUTPUT.txt");

    string base_albhabet = "abcdefghijklmnopqrstuvwxyz ";
    string encoded_alphabet = "0123456789ABCDEFGHIJKLMNOPQ";
    string code;
    inf >> code;

    for(int i = 0; code.length() > i; i += 1) {
        outf << base_albhabet[((encoded_alphabet.find(code[i])+25-i)%27)];
    }
    inf.close();
    outf.close();
}
