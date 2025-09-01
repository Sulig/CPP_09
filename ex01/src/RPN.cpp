/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:46 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/01 20:15:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/RPN.hpp"

/* Constructor & destructor */
RPN::RPN() { _result = 0; }
RPN::RPN(const char *arg)
{
	_result = 0;
	rpn(arg);
}
RPN::RPN(const RPN &other) : _stack(other._stack), _result(other._result) {}
RPN::~RPN() { }
/* ----- */

/* Operator overloads */
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
		_result = other._result;
	}
	return (*this);
}
/* ----- */

/* Utils	*/
bool	RPN::isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

//**/
void	RPN::calculate(char op)
{
	switch (op)
	{
		case '+':
			_result = _stack.top() - '0';
			_stack.pop();
			_result += _stack.top() - '0';
			break;
		case '-':
			break;
		case '*':
			break;
		case '/':
			//coonsider case 0
			break;
	}
}
/* ----- */

/*	RPN	*/
void	RPN::rpn(const char *arg)
{
	int	size = 0;

	while (arg[size])
	{
		if (arg[size] == ' ')
		{
			size++;
			continue ;
		}
		else if (isdigit(arg[size]))
			_stack.push(arg[size]);
		else if (isoperator(arg[size]))
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error: Insuficient numbers" << std::endl;
				return ;
			}
			std::cout << "in progress" << std::endl;
		}
		else
		{
			std::cout << "Error: Unexpected character found!" << std::endl;
			return ;
		}
		size++;
	}
}
/* ----- */
