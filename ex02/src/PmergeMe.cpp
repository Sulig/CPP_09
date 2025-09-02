/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:46 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/02 18:30:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/PmergeMe.hpp"

/* Constructor & destructor */
PmergeMe::PmergeMe() {  }
PmergeMe::PmergeMe(const char *arg)
{

}
PmergeMe::PmergeMe(const PmergeMe &other) {}
PmergeMe::~PmergeMe() { }
/* ----- */

/* Operator overloads */
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{

	}
	return (*this);
}
/* ----- */

/* Utils	*/
int	PmergeMe::ft_atoi(const std::string str)
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
/* ----- */

/*	PmergeMe	*/
void	PmergeMe::pmergeMe(const char *arg)
{

}
/* ----- */
