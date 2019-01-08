#include "pch.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
using namespace std;
int main()
{
	fstream lux, spa;
	char x[50];
	cout << "\t\t\tHey guys, welcome to DK's Epic Luxor to Sparkle converter :)" << endl << endl;;
	cout << "For this program to work, the .obj file should be named as path.obj.\nThis is just an alpha version of the program." << endl <<endl;
	cout<<"Press any key to continue." << endl;
	_getch();
	lux.open("path.obj", ios::in);
	spa.open("output.path.xml", ios::out);
	int count = 0;
	int c1 = 0;
	while (1)
	{
		lux >> x;
		if (lux.eof())
			break;
		if(x[0]=='#'||x[0]==' ')
			lux.ignore(INT_MAX, '\n');
		if (x[0] == 'f')
			break;
			if (count % 2 == 0)
			{
				if (isdigit(x[0]) || x[0] == '-'|| x[0] == 'f')
				{
					spa << "  <pos x=\"";
					spa << x << "\"";
					count++;
				}
			}
			else
			{
				spa << " y=\"";
				if (isdigit(x[1]) || isdigit(x[0]))
				{
					if (isdigit(x[0]))
						for (int i = 0; i <= 1; i++)
						{
							if (isdigit(x[i]))
								spa << x[i];
						}
					else if (isdigit(x[1]))
							for (int i = 0; i <= 3; i++)
								if (isdigit(x[i]))
									spa << x[i];
				}
				count++;
				spa << "\" />" << endl;
				c1++;
			}
			if (c1 == 1)
			{
				c1 = 0;
				lux.ignore(INT_MAX, '\n');
			}

	}
	lux.close();
	spa.close();
	cout << "Thank you for choosing my program, have a great day!";
	_getch();
	return 0;
}
