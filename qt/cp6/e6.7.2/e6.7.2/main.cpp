#include <fstream>
#include <iostream>
#include <string>
#include "arglist.h"
#include "birthdays.h"

using std::ifstream;
using std::ostream;
using std::cout;
using std::cin;
using std::string;

void writeBirthdayToFule(ostream& os);

int main(int argc, char *argv[])
{
	Birthdays b;
	ifstream inf;
	inf.open("test.txt");

	while (inf.good())
	{
		inf >> b;
	}

	cout << b;

	getchar();

	return 0;
}

void writeBirthdayToFule(ostream& os)
{

}