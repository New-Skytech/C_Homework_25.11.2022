#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("INPUT.txt");
    fout.open("OUTPUT.txt");
    int friends, bottles_count, summ = 0, bottle_price;
    fin >> friends >> bottles_count;
    for (int x = 0; x < (bottles_count / friends); x++) {
        for (int y = 0; y < friends; y++) {
            fin >> bottle_price;
            summ += (x + 1) * bottle_price;
        }
    }
    fout << summ;
    fout.close();
    fin.close();
}
