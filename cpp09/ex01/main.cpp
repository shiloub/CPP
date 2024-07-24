#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stack>

int valid_number(std::string number)
{
	int i(0);
	std::string valid("0123456789");

	while (number[i])
	{
		if (valid.find_first_of(number[i]) == std::string::npos)
			return (0);
		i++;
	}
	if (atof(number.c_str()) > 2147483647)
		return (0);
	return (1);
}

void	deal_with_token(std::stack<int> &stack, char c)
{
	int a;
	int b;
	int res;

	if (stack.size() < 2)
	{
		std::cout << "ERROR\n";
		exit (0);
	}
	b = stack.top();
	//std::cout << "jenleve " << stack.top() << std::endl;
	stack.pop();
	a = stack.top();
	//std::cout << "jenleve " << stack.top() << std::endl;
	stack.pop();
	if (c == '/' && b == 0)
	{
		std::cout << "[1]    133948 segmentation fault (core dumped)  ./RPN\n" ;
		exit (0);
	}
	if (c == '*')
		res = a * b;
	if (c == '-')
		res = a - b;
	if (c == '/')
		res = a / b;
	if (c == '+')
		res = a + b;
	//std::cout << a << " " <<  c << " "<<  b << std::endl;
	stack.push(res);
	//std::cout << "ajoute " << stack.top() << std::endl;

}

int main(int ac, char **av)
{
	std::string tokens = "+-/*";
	if (ac != 2)
	{
		std::cout << "Im waiting for one argument\n";
		return (0);
	}
	std::stack<int> stack;
	std::string calcul = av[1];
	std::istringstream calcul_stream(calcul);
	std::string value;

	while (std::getline(calcul_stream, value, ' '))
	{
		if (valid_number(value))
		{
			stack.push(atoi(value.c_str()));
			//std::cout << "jajoute " << stack.top() << std::endl;

		}
		else if (value.size() == 1 && tokens.find_first_of(value[0]) != std::string::npos){
			deal_with_token(stack, value[0]);
		}
		else {
			std::cout << "Erreur\n";
			exit (0);
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
	{
		std::cout << "Not a valid expression\n";
		// while (stack.size())
		// {
		// 	std::cout << stack.top() << " <- ";
		// 	stack.pop();
		// }
		// std::cout << std::endl;

	}
}