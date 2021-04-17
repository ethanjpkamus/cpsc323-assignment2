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
		cout << "Token: " << v[i].token << " Lexeme: " << v[i].lexeme << endl;
	}
	cout << endl;
	//print out associated rules here
	//validate?
}

/*
 * Declarative Production Rules
 */

//<Statement> -> <Declarative> 
//<Declarative> -> <Type> <ID> 
//<Type> -> bool | float | int

/*
 * Arithmetic Production Rules
 */

//<Expression> -> <Expression> + <Term> | <Expression> - <Term> | <Term> 
//<Term> -> <Term> * <Factor> | <Term> / <Factor> | <Factor>
//<Factor> -> ( <Expression> ) | <ID> | <Num>
//<ID> -> id

/*
 * Assignment Production Rules
 */

//<Statement> -> <Assign>
//<Assign> -> <ID> = <Expression>;


