/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr >         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-23 16:10:26 by ffreze            #+#    #+#             */
/*   Updated: 2024-10-23 16:10:26 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RPN.hpp"

RPN::RPN() {}

RPN::~RPN()
{
	while (!this->calc.empty())
	{
		calc.pop();
	}
}

RPN::RPN(const RPN &rpn)
{
	this->calc = rpn.calc;
}

bool isInvalidChar(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '/' || c == '*' || (c >= 48 && c <= 57))
		return false;
	return true;
}

RPN::RPN(const std::string &s)
{
	int nb1;
	int nb2;
	char ope;
	int tmp;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (isInvalidChar(s[i]))
		{
			std::cout << "Using invalid characters !" << std::endl;
			return ;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			tmp = atoi(&s[i]);
			if (tmp > 9 || tmp < 0)
			{
				std::cout << "Number higher than 9 or lower than 0 \n";
				return;
			}
			this->calc.push(tmp);
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
		{
			ope = s[i];
			if (this->calc.size() < 2)
			{
				std::cout << "Need more number for this operation !\n";
				return;
			}
			nb2 = this->calc.top();
			this->calc.pop();
			nb1 = this->calc.top();
			this->calc.pop();
			try
			{
				this->calc.push(do_calc(ope, nb1, nb2));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				exit(EXIT_FAILURE);
			}
		}
	}
	if (this->calc.size() != 1)
		std::cout << "Error, need more operator !" << std::endl;
	else
		std::cout << "Result : " << this->calc.top() << std::endl;
}

RPN &RPN::operator=(const RPN &rpn)
{
	this->calc = rpn.calc;
	return *this;
}

int RPN::do_calc(char ope, int nb1, int nb2)
{
	if (ope == '+')
		return (nb1 + nb2);
	if (ope == '-')
		return (nb1 - nb2);
	if (ope == '*')
		return (nb1 * nb2);
	if (ope == '/')
	{
		if (nb2 == 0)
		{
			throw DivByZero();
		}
		return (nb1 / nb2);
	}
	return (0);
}

const char* RPN::DivByZero::what() const throw()
{
	return "You can't divide by 0";
}