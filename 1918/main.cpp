#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string str;
	stack<char> operators;
	cin >> str;

	for(char & ch : str)
	{
		if(ch>='A' && ch<='Z')
			printf("%c",ch);
		else
		{
			if(ch=='+' || ch=='-')
			{
				char opt=' ';
				if(!operators.empty())
					opt = operators.top();
				while(opt == '+' || opt == '-' || opt == '*' || opt == '/')
				{
					printf("%c",opt);
					operators.pop();
					if(operators.empty()) break;
					opt = operators.top();
				}
				operators.push(ch);
			}
			else if(ch=='(')
				operators.push(ch);
			else if(ch==')'){
				char opt = ' ';
				if(!operators.empty())
					opt = operators.top();
				while(opt!='(')
				{
					printf("%c",opt);
					operators.pop();
					if(operators.empty()) break;
					opt = operators.top();
				}
				operators.pop();
			}
			else if(ch=='*' || ch=='/')
			{
				char opt=' ';
				if(!operators.empty())
					opt = operators.top();
				while(opt == '*' || opt == '/')
				{
					printf("%c",opt);
					operators.pop();
					if(operators.empty()) break;
					opt = operators.top();
				}
				operators.push(ch);
			}
		}
	}

	while(!operators.empty())
	{
		printf("%c",operators.top());
		operators.pop();
	}



	return 0;
}
