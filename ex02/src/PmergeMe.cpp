/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:46 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/16 17:36:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/PmergeMe.hpp"

/* Constructor & destructor */
PmergeMe::PmergeMe()
{
	_compV = 0;
	_actualJBV = 0;
	nextJacobstal(_actualJBV);
}
PmergeMe::PmergeMe(const char **arg, int argc)
{
	_compV = 0;
	_actualJBV = 0;
	nextJacobstal(_actualJBV);
	checkArg(arg, argc);
	pmergeMe(arg, argc);
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
	// Parse
	for (int i = 1; i < argc; i++)
	{
		t_numV	temp;
		temp.value = ft_atoi(arg[i]);
		_vect.push_back(temp);
	}

	std::cout << "Original Vector stack: ->" << std::endl;
	printVector(_vect, 0);
	_orgV = _vect;
	mergeInsertionV(_vect);
	//stop crono

	//crono 2
	//ccall //
	//stop crono 2
}
/* ----- */

// -- Solved with `Vector` zone -->
#pragma region VECTOR

void	PmergeMe::printVector(std::vector<t_numV> vec, int all)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << "[" << i << "] = " << vec[i].value << std::endl;
		if (all)
		{
			std::cout << "   Groups: ";
			for (size_t j = 0; j < vec[i]._group.size(); j++)
				std::cout << vec[i]._group[j] << ", ";
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

size_t	PmergeMe::nextJacobstal(size_t actual)
{
	if (_jacobstalV.size() == 0)
	{
		_jacobstalV.push_back(2);
		_jacobstalV.push_back(2);
		_jacobstalV.push_back(6);
	}
	if (actual >= _jacobstalV.size())
		_jacobstalV.push_back((_jacobstalV.back() / 2 + 2 * _jacobstalV[_jacobstalV.back() - 1]) * 2);
	return (actual);
}

size_t	PmergeMe::binarySearchV(std::vector<t_numV> vec, size_t num)
{
	size_t	i = vec.size() / 2 - 1;

	while (i > 0 && i < vec.size())
	{
		// Num is the bigger one ->
		if (num > vec.back().value)
		{
			_compV++;
			return (vec.size() - 1);
		}
		// In Middle
		else if (num > vec[i].value && num < vec[i + 1].value)
		{
			_compV++;
			return (i + 1);
		}
		// Num is in half smaller ->
		else if (num < vec[i].value)
		{
			_compV++;
			if (i == 0 || i == 1)
			{
				if (num < vec[0].value)
				{
					_compV++;
					return (0);
				}
				if (num < vec[1].value)
				{
					_compV++;
					return (1);
				}
			}
			i /= 2;
		}
		// Num is in half bigger ->
		else if (num > vec[i].value)
		{
			_compV++;
			i *= 2;
		}
	}
	if (i > vec.size())
		return (vec.size() - 1);
	return (i);
}

size_t	PmergeMe::pairtoInsert(std::vector<t_numV> major, std::vector<t_numV> minor)
{
	size_t to_insert = 0;
	for (to_insert = 0; to_insert < minor.size(); to_insert++)
		if (minor[to_insert]._group[minor[to_insert]._group.size() - 1] == major[0]._group[major[0]._group.size() - 1])
			return (to_insert);
	return (to_insert);
}

std::vector<t_numV>	PmergeMe::popPositionV(std::vector<t_numV> org, size_t pos)
{
	std::vector<t_numV>	vect;
	for (size_t i = 0; i < org.size(); i++)
		if (i != pos)
			vect.push_back(org[i]);
	org.clear();
	return (vect);
}

std::vector<t_numV>	PmergeMe::pushPositionV(std::vector<t_numV> org, t_numV to_push, size_t pos)
{
	std::vector<t_numV>	tmp;
	for (size_t i = 0; i < org.size(); i++)
	{
		if (i != pos)
			tmp.push_back(org[i]);
		else
		{
			tmp.push_back(to_push);
			tmp.push_back(org[i]);
		}
	}
	return (tmp);
}

void	PmergeMe::mergeInsertionV(std::vector<t_numV> sort)
{
	if (sort.size() <= 1)
		return ;

	std::vector<t_numV>	major, minor;
	size_t	gr = 0;

	// Separate into pairs
	for (size_t i = 0; i < sort.size(); i++)
	{
		if (i + 1 >= sort.size())
			minor.push_back(sort[i]);
		else
		{
			if (sort[i].value > sort[i + 1].value)
			{
				_compV++;
				sort[i]._group.push_back(gr);
				major.push_back(sort[i]);
				if (i + 1 < sort.size())
				{
					sort[i + 1]._group.push_back(gr);
					minor.push_back(sort[i + 1]);
				}
				i++;
				gr++;
			}
			else if (sort[i].value < sort[i + 1].value)
			{
				_compV++;
				sort[i]._group.push_back(gr);
				if (i + 1 < sort.size())
				{
					sort[i + 1]._group.push_back(gr);
					major.push_back(sort[i + 1]);
				}
				minor.push_back(sort[i]);
				gr++;
				i++;
			}
		}
	}

	std::cout << "Major stack: ->" << std::endl;
	printVector(major, 1);
	std::cout << "Minor stack: ->" << std::endl;
	printVector(minor, 1);

	// Keep separating the major stack until only have 1 element ->
	mergeInsertionV(major);

	std::cout << "AFTER RECURSION -->" << std::endl;
	std::cout << "Minor stack: ->" << std::endl;
	printVector(minor, 1);

	//* Insertion ->
	//--> Look for minor number's pair in major stack
	size_t	to_insert = 0;
	if (major.size() == 1)
		to_insert = pairtoInsert(major, minor);
	else
		to_insert = pairtoInsert(_vect, minor);

	sort.clear();
	sort.push_back(minor[to_insert]);
	if (sort.back()._group.size())
		sort.back()._group.pop_back();
	// Remember to remove the inserted element in minor stack!
	minor = popPositionV(minor, to_insert);
	if (major.size() == 1)
		for (size_t i = 0; i < major.size(); i++)
			sort.push_back(major[i]);
	else
		for (size_t i = 0; i < _vect.size(); i++)
			sort.push_back(_vect[i]);
	_vect = sort;
	std::cout << "Sort vector ->" << std::endl;
	printVector(_vect, 1);

	if (minor[0]._group.size() <= 1)
	{
		//--> Group the restant elements in groups, each one with size of respective Jacobstall serie x2
		std::vector<std::vector<t_numV> >	groups;

		size_t	i = 0;
		while (i < minor.size())
		{
			std::cout << "-- Group size JB --> " << _jacobstalV[_actualJBV] << std::endl;
			std::vector<t_numV>	temp;
			for (size_t j = 0; j < _jacobstalV[_actualJBV]; j++)
			{
				if (i >= minor.size())
					break ;
				temp.push_back(minor[i]);
				i++;
			}
			std::cout << "- Temp -->" << std::endl;
			printVector(temp, 1);
			groups.push_back(temp);
			//Get next Jacobstal number
			_actualJBV = nextJacobstal(++_actualJBV);
		}
		//--> In groups (n1, n2, etc..), insert first the larger index
		/*	Group 1 & 2-> Insert first [1], later [0]
		*	Group 3 -> Insert first [5], [4], [3] .. etc (if insuficient numbers, start by the larger index)
		*	- Insert them in `sort` list using binary search.
		*/
		for (size_t i = 0; i < groups.size(); i++)
		{
			std::vector<t_numV>	temp = groups[i];
			for (size_t j = temp.size() - 1; j >= 0; j--)
			{
				size_t	position = binarySearchV(_vect, temp[j].value);
				std::cout << "Value = " << temp[j].value << " of group: " << i << " to insert in: " << position << std::endl;
				_vect = pushPositionV(_vect, temp[j], position);
				if (j == 0)
					break ;
				std::cout << std::endl << "Actual vector -->" << std::endl;
				printVector(_vect, 0);
			}
		}

		std::cout << "Final vector:" << std::endl;
		printVector(_vect, 1);
	}
}

#pragma endregion
