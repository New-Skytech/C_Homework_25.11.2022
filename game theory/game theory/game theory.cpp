#include <iostream>
#include <fstream>

using namespace std;

int field[100][100];

int main()
{
    ifstream inf;
    ofstream outf;
    inf.open("INPUT.txt");
    outf.open("OUTPT.txt");
    int x_field, y_field, min_max = 1000, max_min = -1000, min, max = -1000;
    inf >> x_field >> y_field;
    for (int x = 0; x < x_field; x++) {
        for (int y = 0; y < y_field; y++) {
            inf >> field[x][y];
        }
    }

    for (int x = 0; x < x_field; x++) {
        min = 1000;
        for (int y = 0; y < y_field; y++) {
            if (field[x][y] < min) {
                min = field[x][y];
            }
        }
        if (min > max) {
            max = min;
        }
    }
    outf << max << ' ';

    min = 1000;

    for (int x = 0; x < x_field; x++) {
        max = -1000;
        for (int y = 0; y < y_field; y++) {
            if (field[x][y] > max) {
                max = field[x][y];
            }
        }
        if (min > max) {
            min = max;
        }
    }
    outf << min;
}