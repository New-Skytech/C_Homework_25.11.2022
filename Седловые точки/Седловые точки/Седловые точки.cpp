#include <iostream>
#include <fstream>

using namespace std;

int field[750][750];

int main()
{
    ifstream inf;
    ofstream outf;
    inf.open("INPUT.txt");
    outf.open("OUTPT.txt");
    bool flagmax = true, flagmin = true;
    int x_field, y_field, min = 1000, max = -1000, counter = 0;
    inf >> x_field >> y_field;
    for (int x = 0; x < x_field; x++) {
        for (int y = 0; y < y_field; y++) {
            inf >> field[x][y];
            
        }
    }

    for (int x_subject = 0; x_subject < x_field; x_subject++) {
        for (int y_subject = 0; y_subject < y_field; y_subject++) {
            flagmax = true;
            flagmin = true;
            for (int x = 0; x < x_field; x++) {
                if (field[x][y_subject] < field[x_subject][y_subject]) {
                    flagmin = false;
                }
            }
            for (int y = 0; y < y_field; y++) {
                if (field[x_subject][y] > field[x_subject][y_subject]) {
                    flagmax = false;
                }
            }
            if (flagmax and flagmin) {
                counter++;
            }
        }
    }
    outf << counter;
    outf.close();
    inf.close();
}
