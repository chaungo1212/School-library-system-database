#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include"School_system.h"
#include"Books.h"
#include"Course.h"
using namespace std;

int main()
{
	School_system* school = new School_system();
	ifstream myfile("test_commands.txt"); // The commands file to read.
	string input;
	if (myfile.is_open())
	{
		while (getline(myfile, input))
		{
			//cout << input << '\n';
			school->commandParser(input);
		}
		myfile.close();
	}
	else
		cout << "Unable to open file\n";


	system("PAUSE");
	return 0;

}
