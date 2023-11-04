#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	try
	{
		RPN rpn = RPN(argv[1]);
		std::cout << rpn.getOperands().top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// #include <stack>
// #include <iostream>

// int main()
// {
// 	std::stack<int> s;

// 	s.push(3);
// 	s.push(5);
// 	s.push(2);
// 	s.push(9);
// 	s.push(s.top() + 2);

// 	std::cout << s.top() << std::endl;

// 	s.pop();
// 	std::cout << s.top() << std::endl;
// }