#include <iostream>
#include "Parser.h"

using std::cout;
using std::cin;
using std::endl;


int main(void)
{
	char * string = {"4+10;"};

	Scanner scan(string);

	scan.Read_in();

	Parser parser(scan.getTokens());

	parser.expr();

	cout << endl;

	parser.PrintPostFix();

	getchar();

	return 0;
}