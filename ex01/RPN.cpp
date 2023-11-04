#include "RPN.hpp"

RPN::RPN()
{
	;
}

RPN::RPN(std::string args)
{
	int i = 0;
	int ns;

	while (args[i])
	{
		if (args[i] != ' ')
		{
			if (args[i] <= '9' && args[i] >= '0')
				this->operands.push(args[i] - 48);
			else if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/')
			{
				execOperations(args[i]);
				ns++;
			}
			else
				throw std::exception(); // to replace
		}
		i++;
	}
	// if (this->operands.size() - ns != 1)
	// 	throw std::exception(); // to replace
}

RPN::RPN(const RPN &other)
{
	this->operands = other.operands;
}

RPN& RPN::operator=(const RPN &other)
{
	this->operands = other.operands;
	return (*this);
}

RPN::~RPN()
{
	;
}

std::stack<int> RPN::getOperands()
{
	return operands;
}

void RPN::execOperations(char sign)
{
	int n2 = this->operands.top();
	this->operands.pop();
	int n1 = this->operands.top();
	this->operands.pop();
	if (sign == '+')
		this->operands.push(n1 + n2);
	else if (sign == '-')
		this->operands.push(n1 - n2);
	else if (sign == '*')
		this->operands.push(n1 * n2);
	else if (sign == '/')
		this->operands.push(n1 / n2);
}

// std::ostream& operator<<(std::ostream& os, std::list<int> &l)
// {
// 	os << "[";

// 	std::stack<int>::iterator it = l.begin();
// 	while (it != l.end())
// 	{
// 		os << *it;
// 		it++;
// 		if (it != l.end())
// 			os << " ";
// 	}

// 	os << "]";
// 	return os;
// }
