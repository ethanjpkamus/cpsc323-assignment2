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
using std::isdigit;
using std::stoi;

// string terminals[] ={"+", "-", "*", "/", ";"};
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

void parser(vector<sig_item>);
bool E(vector<sig_item> &v);
bool EP(vector<sig_item> &v);
bool T(vector<sig_item> &v);
bool TP(vector<sig_item> &v);
bool F(vector<sig_item> &v);
void advance(int);

void parser(vector<sig_item> v)
{
	vector<sig_item> v2 = v;

	if(v2.size() != 0){	//check for empty vector
		v2.push_back(sig_item("END", "$"));
		cout << "[ ";
		for(int i = 0; i < v2.size(); ++i)
		{
			cout << "(" << v2[i].lexeme << ", " << v2[i].token << "), ";
		}
		cout << "]" <<endl;

		cout << (E(v2)? "valid" : "invalid") << endl;
		// cout << endl;
	}
	look = 0;
	cout << endl;
}

//E
bool E(vector<sig_item> &v)
{
	// cout << "E" << endl;
	bool result = false;
	if(T(v))
	{
		if(EP(v))
		{
			cout << "E  -> TE'" << endl;
			result = true;
		}
	}
	return result;
}
//Q
bool EP(vector<sig_item> &v)
{
	// cout << "EP" << endl;
	bool result = false;
	advance(v.size());
	string s = v[look].lexeme;
	if(s == "+" || s == "-")
	{
		if(T(v))
		{
			if(EP(v))
			{
				cout << "E' -> +TE'" << endl;
				result = true;
			}
		}
	} else {
		if (s == ")" || s == "$") 
		{
			--look;
			cout << "E' -> eps" << endl;
			result = true;
		}
	}
	return result;
}
//T
bool T(vector<sig_item> &v)
{
	// cout << "T" << endl;
	bool result = false;
	if(F(v))
	{
		if(TP(v))
		{
			cout << "T  -> FT'" << endl;
			result = true;
		}
	}
	return result;
}
//R
bool TP(vector<sig_item> &v)
{
	// cout << "TP" << endl;
	bool result = false;
	advance(v.size());
	string s = v[look].lexeme;
	if(s == "*" || s == "/")
	{
		if(F(v))
		{
			if (TP(v))
			{
				cout << "T' -> *FT'" << endl;
				result = true;
			}
		}
	} else {
		if (s == "+" || s == "-" || s == ")" || s == "$") 
		{
			cout << "T' -> eps" << endl;
			--look;
			result = true;
		}
	}
	return result;
}

bool F(vector<sig_item> &v)
{
	// cout << "F" << endl;
	bool result = false;
	advance(v.size());
	if(v[look].token == "IDENTIFIER")
	{
		cout << "F -> id" << endl;
		result = true;
		// advance(v.size());
	} else if(v[look].lexeme == "("/* lexeme is "(" */) {
		if(E(v))
		{
			if(v[look].lexeme == ")"/*lexeme is ")" */)
			cout << "F -> (E)";
		}
	}
	return result;
}

void advance(int size)
{
	// cout << "adv" << endl;
	if (look < size)
	{
		look++;
	} else {
		cout << "size reached" << endl;
	}
}