#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <iomanip>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::setw;

string terminals[] ={"+", "-", "*", "/", ";"};
int look = 0;

/*
 * Arithmetic Production Rules
 * <Expression> -> <Expression> + <Term> | <Expression> - <Term> | <Term> 
 * <Term> -> <Term> * <Factor> | <Term> / <Factor> | <Factor>
 * <Factor> -> ( <Expression> ) | <ID> 
 * <ID> -> id
 *
 * or
 * 
 * E  -> TE'
 * E' -> +TE' | eps
 * 
 * T  -> FT'
 * T' -> *FT' | eps
 * 
 * F -> (E) | id
 */

//E
bool expression(vector<sig_item> &v)
{
	result = false;
	if(term(v))
	{
		if(expression_prime(v))
		{
			cout << "E  -> TE'" << endl;
			result = true;
		}
	}
	return result;
}
//Q
bool expression_prime(vector<sig_item> &v)
{
	result = false;
	string s = v[look].lexeme;
	if(s == "+")
	{
		if(term(v))
		{
			if(expression_prime(v))
			{
				cout << "E' -> +TE'" << endl;
				result = true;
			}
		}
	} else if (s == ")" || s == "$") {
		--look;
		cout << "E' -> eps" << endl;
		result = true;
	}
	return result;
}
//T
bool term(vector<sig_item> &v)
{
	result = false;
	if(factor(v))
	{
		if(term_prime(v))
		{
			cout << "T  -> FT'" << endl;
			result = true;
		}
	}
	return result;
}
//R
bool term_prime(vector<sig_item> &v)
{
	result = false;
	string s = v[look].lexeme;
	if(s == "*")
	{
		if(factor(v))
		{
			if (term_prime(v))
			{
				cout << "T' -> *FT'" endl;
				result = true;
			}
		}
	} else if (s == "+" || s == ")" || s == "$") {
		cout << "T' -> eps" endl;
		--look;
		result = true;
	}
}

bool factor(vector<sig_item> &v)
{
	result = false;
	if(v[look].token == "IDENTIFIER"/*token is identifier*/)
	{
		cout << "F -> id" << endl;
		result = true;
	} else if(v[look].lexeme == "("/* lexeme is "(" */){
		if(expression(v))
		{
			if(v[look].lexeme == "("/*lexeme is ")" */)
			cout << "F -> (E)"
		}
	}
}

void parser(vector<sig_item> v)
{
	//print out token and lexeme here

	vector<sig_item> v2 = v;

	if(v2.size() != 0){	//check for empty vector
		v2.push_back(sig_item("END", "$"));

		//start parse
		expression(v2);
	}
	//print out associated rules here
	//validate?
}

