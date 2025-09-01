/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:18 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/01 20:05:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
	private:
		std::stack<char>	_stack;
		int	_result;

	protected:
		bool	isoperator(char c);
		int		ft_atoi(const std::string str);
		void	calculate(char op);

	public:
		RPN();
		RPN(const char *arg);
		RPN(const RPN &other);
		~RPN();

		RPN &operator=(const RPN &other);
		//** */
		void	rpn(const char *arg);
};
#endif
