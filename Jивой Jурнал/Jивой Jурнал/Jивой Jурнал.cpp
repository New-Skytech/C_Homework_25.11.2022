#include <iostream>
#include <fstream>

using namespace std;

string frend[200], not_frend[200], also_frend_of[200], Mutual_friend[200];

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("INPUT.txt");
    fout.open("OUTPUT.txt");
    int frends, not_frends, also_frends_of = 0, mutual_friends = 0;
    bool flag;
    

    fin >> frends;
    fout << "Friends: ";
    for (int i = 0; i < frends; i++) {
        fin >> frend[i];
        if (i + 1 != frends){
            fout << frend[i] << ", ";
        }
        else
        {
            fout << frend[i] << endl;
        }
    }
    fin >> not_frends;
    for (int i = 0; i < not_frends; i++) {
        fin >> not_frend[i];
    }
    for (int i = 0; i < not_frends; i++) {
        flag = true;
        for (int z = 0; z < frends; z++) {
            if (not_frend[i] == frend[z]) {
                flag = false;
            }
        }
        if (flag) {
            also_frend_of[also_frends_of] = not_frend[i];
            also_frends_of++;
        }
        else
        {
            Mutual_friend[mutual_friends] = not_frend[i];
            mutual_friends++;
        }
    }
    fout << "Mutual friendx: ";
    for (int i = 0; i < mutual_friends; i++) {
        if (i + 1 != mutual_friends) {
            fout << Mutual_friend[i] << ", ";
        }
        else
        {
            fout << Mutual_friend[i] << endl;
        }
    }
    fout << "Also Friend of: ";
    for (int i = 0; i < also_frends_of; i++) {
        if(i + 1 != also_frends_of) {
            fout << also_frend_of[i] << ", ";
        }
        else
        {
            fout << also_frend_of[i] << endl;
        }
    }
    fout.close();
    fin.close();
}
