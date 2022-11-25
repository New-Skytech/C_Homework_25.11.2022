#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string field[202][202];

int main()
{
	ifstream inf;
	ofstream outf;

	string base = "1234567";
	string modified = "2345678";

	inf.open("INPUT.txt");
	outf.open("OUTPUT.txt");

	int x_field, y_field, mine_count, x_mine, y_mine;
	for (int x = 0; x < 202; x++) { 
		for (int y = 0; y < 202; y++) {
			field[x][y] = ".";
		}
	} //Создаём игровое поле

	inf >> x_field >> y_field >> mine_count;
	for (int i = 0; i < mine_count; i++) {
		inf >> x_mine >> y_mine;
		field[x_mine][y_mine] = "*"; // создаем мину
		for (int x = -1; x < 2; x++) {
			for (int y = -1; y < 2; y++) {
				if (field[x_mine - x][y_mine - y] != "*") { //увеличиваем значения в области 3х3 на 1
					if (field[x_mine - x][y_mine - y] == ".") {
						field[x_mine - x][y_mine - y] = "1";
					}
					else
					{
						field[x_mine - x][y_mine - y] = modified[base.find(field[x_mine - x][y_mine - y])];
					}
				}
			}
		}
	}

	for (int x = 1; x <= x_field; x++) {
		for (int y = 1; y <= y_field; y++) {
			outf << field[x][y];
		}
		outf << endl;
	}
	inf.close();
	outf.close();
}
