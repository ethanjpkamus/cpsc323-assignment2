//OHHHHHH MYYYYYYYYYYY
#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void parser(vector<sig_item> v)
{
	//print out token and lexeme here

	for(int i = 0; i < v.size(); ++i)
	{
		// cout << setw(10) << v[i].token  << " | " << v[i].lexeme << endl;
		cout << v[i].lexeme << " ";
	}
	cout << endl;
	//print out associated rules here
	//validate?
}

/*
 * Declarative Production Rules
 */

//<Statement> -> <Declarative>
bool isStatement()
{
	cout << "<Statement> -> <Declarative>" << endl;
	//return isDeclarative();
}
//<Declarative> -> <Type> <ID>
bool isDeclarative()
{
	cout << "<Declarative> -> <Type> <ID>" << endl;
	//isType()
	//isID()
}
//<Type> -> bool | float | int
bool isType()
{
	cout << "<Type> -> bool | float | int" << endl;
}

/*
 * Arithmetic Production Rules
 */

//<Expression> -> <Expression> + <Term> | <Expression> - <Term> | <Term>
bool isExpression()
{
	cout << "<Expression> -> <Expression> + <Term> | <Expression> - <Term> | <Term>" << endl;
}
//<Term> -> <Term> * <Factor> | <Term> / <Factor> | <Factor>
bool isTerm()
{
	cout << "<Term> -> <Term> * <Factor> | <Term> / <Factor> | <Factor>" << endl;
}
//<Factor> -> ( <Expression> ) | <ID> | <Num>
bool isFactor()
{
	cout << "<Factor> -> ( <Expression> ) | <ID> | <Num>" << endl;
}
//<ID> -> id
bool isID()
{
	cout << "<ID> -> id" << endl;
}

/*
 * Assignment Production Rules
 */

//<Statement> -> <Assign>
bool isStatement()
{
	cout << "<Statement> -> <Assign>" << endl;
}
//<Assign> -> <ID> = <Expression>;
bool isAssign()
{
	cout << "<Assign> -> <ID> = <Expression>;" << endl;
}

/*
  Declarative Statements
 */

//<Statement> -> <Declarative>
bool decStatement()
{
    cout << "<Statement> -> <Declarative>" << endl;
}

//<Declarative> -> <Type> <ID>
bool declarative()
{
    cout << "<Declarative> -> <Type> <ID><Declarative> -> <Type> <ID>" << endl;
}

//<Type> -> bool | float | int
bool Type()
{
    cout << "<Type> -> bool | float | int" << endl;
}
