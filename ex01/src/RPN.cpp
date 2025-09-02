/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:46 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/02 18:30:48 by sadoming         ###   ########.fr       */
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
RPN::RPN(const RPN &other) : _input(other._input), _stack(other._stack), _result(other._result) {}
RPN::~RPN() { }
/* ----- */

/* Operator overloads */
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
		_input = other._input;
		_result = other._result;
	}
	return (*this);
}
/* ----- */

/* Utils	*/
bool	RPN::isoperator(std::string c)
{
	if (c == "+" || c == "-" || c == "*" || c == "/")
		return true;
	return false;
}
//**/
int	RPN::ft_atoi(const std::string str)
{
	int		cnt;
	int		sign;
	int		find;

	find = '\0';
	cnt = -1;
	sign = 1;
	while (str[++cnt] < 33)
		if ((str[cnt] < 9 || str[cnt] > 13) && str[cnt] != ' ')
			return ('\0');
	if (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == '-')
			sign *= -1;
		cnt++;
	}
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		find *= 10;
		find += str[cnt] - '0';
		cnt++;
	}
	return (find * sign);
}
//**/
void	RPN::split(const char *to_split, char sep)
{
	std::stringstream _line(to_split);
	std::string	value;
	std::stack<std::string>	tmp;
	while (std::getline(_line, value, sep) || std::getline(_line, value))
		tmp.push(value);
	while (!tmp.empty())
	{
		_input.push(tmp.top());
		tmp.pop();
	}
}
//**/
void	RPN::calculate(char op)
{
	int	tmp;
	switch (op)
	{
		case '+':
			tmp = ft_atoi(_stack.top());
			_stack.pop();
			_result = ft_atoi(_stack.top()) + tmp;
			break;
		case '-':
			tmp = ft_atoi(_stack.top());
			_stack.pop();
			_result = ft_atoi(_stack.top()) - tmp;
			break;
		case '*':
			tmp = ft_atoi(_stack.top());
			_stack.pop();
			_result = ft_atoi(_stack.top()) * tmp;
			break;
		case '/':
			tmp = ft_atoi(_stack.top());
			_stack.pop();
			_result = ft_atoi(_stack.top()) / tmp;
			break;
	}
	_stack.pop();
	std::ostringstream oss;
	oss << _result;
	_stack.push(oss.str());
}
/* ----- */

/*	RPN	*/
void	RPN::rpn(const char *arg)
{
	split(arg, ' ');
	while (!_input.empty())
	{
		if (ft_atoi(_input.top()) != '\0' || _input.top() == "0")
			_stack.push(_input.top());
		else if (isoperator(_input.top()))
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error: Insuficient numbers" << std::endl;
				return ;
			}
			calculate(_input.top()[0]);
		}
		else
		{
			std::cout << "Error: Unexpected character found!" << std::endl;
			return ;
		}
		_input.pop();
	}
	if (_stack.size() > 2)
		std::cout << "Error: Insuficient operators!" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}
/* ----- */
