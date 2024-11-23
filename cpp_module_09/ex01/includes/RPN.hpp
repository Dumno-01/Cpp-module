#ifndef RPN_HPP
#define RPN_HPP
# include <stack>
# include <string>
# include <cstdlib>
# include <iostream>
class RPN
{
public:
	RPN();
	~RPN();
	RPN(const std::string &s);
	RPN(const RPN &rpn);
	RPN& operator=(const RPN &rpn);
	class DivByZero : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
private:
	int do_calc(char ope, int nb1, int nb2);
	std::stack<int> calc;
};


#endif