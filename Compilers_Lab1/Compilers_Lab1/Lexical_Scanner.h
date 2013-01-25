#ifndef LEXICAL_SCANNER
#define LEXICAL_SCANNER

#include <string>
#include <vector>

using namespace std;

const enum token_type {ADD, SUB, MUL, DIV, ID, AS, LIT, END};

class token
{
	static int counter;
	int type;
	int id;

public:
	token(int t) : type(t), id(0)
	{
		if ( type == ID )
		{
			int id = counter;
			counter++;
		}
	}

	token(int t, int id) : type(t), id(id)
	{
	}

	int getType() const
	{
		return type;
	}
	int getID() const
	{
		return id;
	}
};

int token::counter = 0;

class Scanner
{
private:
	char * source;

	char character;
	int position;
	vector<token> tokens;

public:
	Scanner(char * s);

	void Read_in();

	vector<token> getTokens();
};

Scanner::Scanner(char * s) : source(s) 
{
	position = 0;
}

void Scanner::Read_in()
{
	char c = source[position];

	if ( c == ' ' )
	{
		Read_in();
	}
	else if ( isdigit(c) )
	{
		int temp = 0;

		while ( isdigit(c) )
		{
			temp = 10 * temp + atoi(&c);
			position++;
			c = source[position];
		}

		tokens.push_back(token(LIT, temp));

		Read_in();
	}
	else if ( c == '+' )
	{
		tokens.push_back(token(ADD));

		position++;

		Read_in();
	}
	else if ( c == '-' )
	{
		tokens.push_back(token(SUB));

		position++;

		Read_in();
	}
	else if ( c == '*' )
	{
		tokens.push_back(token(MUL));

		position++;

		Read_in();
	}
	else if ( c == '/' )
	{
		tokens.push_back(token(DIV));

		position++;

		Read_in();
	}
	else if ( c == '=' )
	{
		tokens.push_back(token(AS));

		position++;

		Read_in();
	}
	else if ( c == ';' )
	{
		tokens.push_back(token(END));
	}
	else
	{
		cout << "Problem?";
	}
}

vector<token> Scanner::getTokens()
{
	return tokens;
}








#endif LEXICAL_SCANNER