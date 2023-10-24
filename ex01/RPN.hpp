#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:

		std::stack<int> operands;

	public:

		RPN();
		RPN(std::string args);
		RPN(const RPN &other);
    	RPN& operator=(const RPN &other);
		~RPN();
		std::stack<int> getOperands();
		void execOperations(char sign);
};

std::ostream& operator<<(std::ostream& os, std::stack<int>& s);

#endif