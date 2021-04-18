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












//Testing
string keyword[SIZE]={"numbers", "decimals", "words", 	"if",
                  "else", "check", "expr"	"stop", "repeatTill","send"
				 };

//Functions Definitions
void SyntaxAnalyzer::setSourceCode(string code)
{
	s=code;

}
//Display Source Code
void SyntaxAnalyzer::display()
{
	cout<<s<<endl;

}
void SyntaxAnalyzer::separateWords()
{
	int index=0;
	char c;
	string word="";

	myFile.open("generatedTokens.txt");


	while(index < s.length() ) // In String length there is extra increase of length by 2
	{
		c=s.at(index);

		if(isChar(c))
		{
			word=word+c;

		}

		if(isString(c))
		{
			word=word+c;
			while(true)
			{
				index++;
				c=s.at(index);
				word=word+c;
				if(c== 34)
				{
					//Generates String "Hello World !"
					//cout<<word<<endl;
					generateToken(word, 'S');



					word="";
					break;
				}

			}
		}

		if(isSymbol(c) || c == 32  )
		{

			if(word != "")
			{//Generates Keyword or Identifier
			//cout<<word<<endl;

				if(checkKeyword(word) == true)
				{
					generateToken(word, 'K');


				}
				//Checking Identifier repective to Regular Expression
				else if(checkIdentifier(word)  == true)
				{
					generateToken(word, 'I');


				}
				else
				{
					//For Constants
					generateToken(word, 'L');


				}
				word="";
			}


			if(c!=32)
			{
				//For Logical Operator e.g == , !=, >=, <=
				if((c== '='|| c=='>' || c=='<' || c=='!') && '='==s.at(index+1) || c=='|' || c=='&')
				{
				string logical_O="";
				logical_O +=c;
				logical_O +=s.at(index+1);
				generateToken(logical_O, 'O');

				//cout<<logical_O<<endl;
				index++;
				}
				else if(c!=10)
				{
					//Generates Symbols like *,-,/...etc
					//cout<<c<<endl;
					string s(1, c); // Casting char into string
					generateToken(s, 'O');


				}

			}

		}

		index++;

	}


	myFile.close();
}

bool SyntaxAnalyzer::isChar(char c)
{
	if((c>=65 && c<=90) ||  (c>=97 && c<=122) ||  (c>=48 && c<=57) )
	{
		return true;
	}
	return false;
}

bool SyntaxAnalyzer::isSymbol(char c)
{
	//c==10 for printing last character
	if((c>=35 && c<=47) || c==33 || c == 10 || (c>=58 && c<=64) || (c>=91 && c<=96) || (c>=123 && c<=125))
	{
		return true;
	}
	return false;
}

bool SyntaxAnalyzer::isString(char c)
{
	if(c == 34)
	{
		return true;
	}
	return false;
}

bool SyntaxAnalyzer::checkKeyword(string word)
{
	for(int i=0; i<SIZE; i++)
	{
		if(keyword[i] == word)
		{
			return true;
		}
	}
	return false;
}

void SyntaxAnalyzer::generateToken(string word, char c)
{
	if(word=="(")
	{
		openP++;
	}
	else if(word==")")
	{
		closeP++;
	}
	else if(word==";")
	{
		semicolon++;
	}
	else if(word== "{")
	{
		openB++;
	}
	else if(word=="}")
	{
		closeB++;
	}



	myFile<<word<<"\n";

	if(word.at(0) == 34)
	{
		tokenString=word;
	}

	count++;
	switch(c)
	{
		case'K':
		keyW++;
		//cout<<"< Keyword#"<<keyW<<", "<<word<<" >\n"<<endl;

		break;

		case'I':
		id++;
		//cout<<"< Idenfier#"<<id<<", "<<word<<" >\n"<<endl;

		break;

		case'O':
		sym++;
		//cout<<"< Symbol#"<<sym<<", "<<word<<" >\n"<<endl;

		break;

		case'S':
		str++;
		//cout<<"< String#"<<str<<", "<<word<<" >\n"<<endl;

		break;

		case'L':
		lit++;
		//cout<<"< Literals#"<<lit<<", "<<word<<" >\n"<<endl;

		break;

	}


}

bool SyntaxAnalyzer::checkIdentifier(string word)
{
	//If string starts from letters a, b,c..z or A, B, ..z
	if((word.at(0)>=65 && word.at(0)<=90) || (word.at(0)>=97 && word.at(0)<=122) )
	{
		//Checking for string such assasd!# which is not accepted
		for(int i=1; i<word.length(); i++)
		{

			if(word.at(i) >= 48 && word.at(i) <= 57 || word.at(i) >= 65 && word.at(i) <= 90 || word.at(i) >= 97 && word.at(i) <= 122 )
			{

			}
			else
			{
				return false;
			}
		}
		return true;
	}

	return false;
}


int SyntaxAnalyzer::getSize()
{
	return count;
}

bool SyntaxAnalyzer::start(string returnType)
{
	if(DataType(returnType) ==  true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int SyntaxAnalyzer::funcDeclaration(string array[])
{
	int flag=0;

	//Checking keyword for return type
	if(start(array[0]) == true)
	{

		//Next Phase to check Function Name
		if(checkIdentifier( array[1]) == true)
		{

			if(array[2] =="(" && openP == 1)
			{


				for(int i=3; i<count-2; i=i+3)
				{
					if(DataType(array[i]) == true)
					{
						 if(checkIdentifier( array[i+1]) == true)
						{
							if(array[i+2] == "," || i + 2 == count-2)
							{
								flag=1;
							}
							else
							{
								nameOfError="Error : There is Error on/before/After of , ";
								flag=0;
								break;
							}
						}
						else
						{
							nameOfError="Error : There is Error on/before/After of Parameter Variable name ";
							flag=0;
							break;
						}

					}
					else
					{
						nameOfError="Error : There is Error  on/before/After of Parameter Data Type ";
						flag=0;
						break;
					}

				}

				if( flag == 1 )
				{

					if( array[count-2] ==")" && closeP == 1 )
					{
						if( array[count-1] ==";" && semicolon == 1 )
						{
							return 1;
						}
						else
						{
							//Error
							nameOfError="Error : There is Error on/before/After of semicolon ; ";
							return 0;
						}

					}
					else
					{
						//Error
						nameOfError="Error : There is Error on/before/After of closing parenthesis ";
						return 0;
					}
				}
				else
				{
					//Error
					nameOfError="Error : There is Error  before ) closing paranthesis ";
					return 0;
				}
			}
			else
			{
			//Error
			nameOfError="Error : There is Error on/before/After of Open Parenthesis ( ";
			return 0;
			}
		}
		else
		{
		//Error
			nameOfError="Error : There is Error on/before/After of Function Name ";
			return 0;
		}

	}
	else
	{
		//Error
		nameOfError="Error : There is Error on/before/After of Return Type ";
		return 0;
	}


}

bool SyntaxAnalyzer::DataType(string returnType)
{
	if(returnType == "numbers" || returnType == "decimals" || returnType == "words")
	{
		return true;
	}
	else
	{
		return false;
	}
}

string SyntaxAnalyzer::getError()
{
	openP=0;
	closeP=0;
	semicolon=0;
	count=0;
	openB=0;
	closeB=0;
	return nameOfError;
}

void SyntaxAnalyzer::check()
{
	cout<<"OpenP:  "<<openP<<endl;
	cout<<"CloseP:"<<closeP<<endl;
	cout<<"Semicolon: "<<semicolon<<endl;
	cout<<"count: "<<count<<endl;

}

int SyntaxAnalyzer::funcCalling(string array[])
{
	int flag=0;



		//Next Phase to check Function Name
		if(checkIdentifier( array[0]) == true)
		{

			if(array[1] =="(" && openP == 1)
			{


				for(int i=2; i<count-2; i=i+2)
				{

					 if(checkIdentifier( array[i]) == true)
					{
						if(array[i+1] == "," || i + 1 == count-2)
						{
							flag=1;
						}
						else
						{
							nameOfError="Error : There is Error on/before/After of , ";
							flag=0;
							break;
						}
					}
					else
					{
						nameOfError="Error : There is Error on/before/After of Parameter Variable name ";
						flag=0;
						break;
					}



				}

				if( flag == 1 )
				{

					if( array[count-2] ==")" && closeP == 1 )
					{
						if( array[count-1] ==";" && semicolon == 1 )
						{
							return 1;
						}
						else
						{
							//Error
							nameOfError="Error : There is Error on/before/After of semicolon ; ";
							return 0;
						}

					}
					else
					{
						//Error
						nameOfError="Error : There is Error on/before/After of closing parenthesis ";
						return 0;
					}
				}
				else
				{
					//Error
					nameOfError="Error : There is Error  before ) closing paranthesis ";
					return 0;
				}
			}
			else
			{
			//Error
			nameOfError="Error : There is Error on/before/After of Open Parenthesis ( ";
			return 0;
			}
		}
		else
		{
		//Error
			nameOfError="Error : There is Error on/before/After of Function Name ";
			return 0;
		}



}
