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
PmergeMe::PmergeMe() { }
PmergeMe::PmergeMe(const char **arg, int argc)
{
	checkArg(arg, argc);
}
PmergeMe::PmergeMe(const PmergeMe &other) : _vect(other._vect) {}
PmergeMe::~PmergeMe() { }
/* ----- */

/* Operator overloads */
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vect = other._vect;
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
void	PmergeMe::checkArg(const char **arg, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		if (arg[i][0] == '0')
			continue ;
		if (ft_atoi(arg[i]) == '\0')
		{
			std::cout << "Error: Unexpected character found!" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (ft_atoi(arg[i]) < 0)
		{
			std::cout << "Error: Negative number not suported!" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}
/* ----- */

/*	PmergeMe	*/
void	PmergeMe::pmergeMe(const char **arg, int argc)
{
	//crono
	//call vector?
	vector(arg, argc);
	//stop crono

	//crono 2
	//ccall //
	//stop crono 2
}
/* ----- */

// -- Solved with `Vector` zone -->
#pragma region VECTOR

void	PmergeMe::vector(const char **arg, int argc)
{
	// Parse
	for (int i = 0; i < argc; i++)
		_vect[i] = ft_atoi(arg[i + 1]);

	// Separate into pairs
}

#pragma endregion
