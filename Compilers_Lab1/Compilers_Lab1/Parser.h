#ifndef PARSER
#define PARSER

#include "Lexical_Scanner.h"
#include <iostream>
#include <stack>

using namespace std;

class Parser
{
private:
	int counter;
	vector<token> tokens;
	stack<token> opstack;
	token tok;
	stack<token> postfix;

public:
	Parser(vector<token> ts) : counter(0), tokens(ts), tok(0)
	{
		tok = tokens.at(counter);
	}

	void lookAhead()
	{
		counter++;
		tok = tokens.at(counter);
	}

	void expr()
	{
		term();

		while(true)
		{
			if (tok.getType() == ADD)
			{
				match(ADD);
				term();

				if (!opstack.empty())
				{
					if ( opstack.top().getType() < tok.getType() )
					{
						opstack.push(tok);
					}
					else
					{
						postfix.push(opstack.top());
						opstack.pop();
						opstack.push(tok);
					}
				}
				else
					opstack.push(tok);

				cout << "+";
			}
			else if ( tok.getType() == SUB)
			{
				match(SUB);
				term();

				if (!opstack.empty())
				{
					if ( opstack.top().getType() < tok.getType() )
					{
						opstack.push(tok);
					}
					else
					{
						postfix.push(opstack.top());
						opstack.pop();
						opstack.push(tok);
					}
				}
				else
					opstack.push(tok);

				cout << "-";
			}
			else if ( tok.getType() == MUL)
			{
				match(MUL);
				term();

				if (!opstack.empty())
				{
					if ( opstack.top().getType() < tok.getType() )
					{
						opstack.push(tok);
					}
					else
					{
						postfix.push(opstack.top());
						opstack.pop();
						opstack.push(tok);
					}
				}
				else
					opstack.push(tok);

				cout << "*";
			}
			else if ( tok.getType() == DIV)
			{
				match(DIV);
				term();

				if (!opstack.empty())
				{
					if ( opstack.top().getType() < tok.getType() )
					{
						opstack.push(tok);
					}
					else
					{
						postfix.push(opstack.top());
						opstack.pop();
						opstack.push(tok);
					}
				}
				else
					opstack.push(tok);

				cout << "/";
			}
			else if ( tok.getType() == END )
			{
				while (!opstack.empty())
				{
					postfix.push(opstack.top());
					opstack.pop();
				}

				break;
			}
			else
			{
				cout << "Error" << endl;
			}
		}
	}

	void term()
	{
		if ( tok.getType() == LIT )
		{
			postfix.push(tok);

			cout << tok.getID();

			match((token_type)tok.getType());
		}
		else
		{
			cout << "ERROR";
		}

	}

	void match(token_type tt)
	{
		if ( tok.getType() == tt )
		{
			lookAhead();
		}
		else
		{
			cout << "Syntax error";
		}
	}

	void PrintPostFix()
	{
		stack<token> temp(postfix);

		while (!temp.empty())
		{
			token current_token = temp.top();

			switch ((token_type)current_token.getType())
			{
			case ADD : 
				{
					cout << "+"; 
					break;
				}
			case SUB :
				{
					cout << "-";
					break;
				}
			case MUL :
				{
					cout << "*";
					break;
				}
			case DIV :
				{
					cout << "/";
					break;
				}
			case AS :
				{
					cout << "=";
					break;
				}
			case LIT :
				{
					cout << temp.top().getID();
					break;
				}
			default :
				{
					cout << "Somethin is broke" << std::endl;
					break;
				}
			}

			temp.pop();
		}

	}
};















#endif