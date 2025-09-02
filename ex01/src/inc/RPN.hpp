/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:18 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/02 17:20:02 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stack>

class RPN
{
	private:
		std::stack<std::string>	_input;
		std::stack<std::string>	_stack;
		int	_result;

	protected:
		bool	isoperator(std::string c);
		int		ft_atoi(const std::string str);
		void	calculate(char op);
		void	split(const char *to_split, char sep);

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
