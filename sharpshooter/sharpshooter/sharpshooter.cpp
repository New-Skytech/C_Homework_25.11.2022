#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inf;
    ofstream outf;
    inf.open("INPUT.txt");
    outf.open("OUTPT.txt");
    bool positive_zero = true, negative_zero = true, uniqe;
    int x, y, targets_count, angle, counter = 0;
    int first_and_second_quaters[20], third_and_forth_quaters[20];
    inf >> targets_count;
    for (int i = 0; i < targets_count; i++) {
        inf >> x >> y;
        if (y >= 0) {
            if (y == 0) {
                if (x == 0) {
                    cout << "wrong target location:(0;0)";
                    return 0;
                }
                if (x > 0 and positive_zero) {
                    counter++;
                    positive_zero = false;
                }
                if (x < 0 and negative_zero){
                    counter++;
                    negative_zero = false;
                }
            }
            angle = x / y;
            uniqe = true;
            for (int z = 0; z < 20; z++) {
                if (first_and_second_quaters[z] == angle) {
                    uniqe = false;
                }
            }
            if (uniqe) {
                counter++;
                first_and_second_quaters[i] = angle;
            }
        }
        if (y < 0) {
            angle = x / y;
            uniqe = true;
            for (int z = 0; z < 20; z++) {
                if (third_and_forth_quaters[z] == angle) {
                    uniqe = false;
                }
            }
            if (uniqe) {
                counter++;
                third_and_forth_quaters[i] = angle;
            }
        }
    }
    outf << counter;
    outf.close();
    inf.close();

}