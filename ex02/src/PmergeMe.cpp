/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:46 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/17 20:11:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/PmergeMe.hpp"

/* Constructor & destructor */
PmergeMe::PmergeMe()
{
	_group_size = 0;

	//* Vector start
	_compV = 0;
	_actualJBV = 0;
	nextJacobstalVDouble(_actualJBV);

	//* List start
	_compL = 0;
	_actualJBL = 0;
	//nextJacobstalVDouble(_actualJBV);
}
PmergeMe::PmergeMe(const char **arg, int argc)
{
	_group_size = 0;

	//* Vector start
	_compV = 0;
	_actualJBV = 0;
	nextJacobstalVDouble(_actualJBV);

	//* List start
	_compL = 0;
	_actualJBL = 0;
	//nextJacobstalVDouble(_actualJBV);

	checkArg(arg, argc);
	pmergeMe(arg, argc);
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
	_group_size = other._group_size;

	_compL = other._compL;
	_orgL = other._orgL;
	_list = other._list;
	_jacobstalL = other._jacobstalL;
	_actualJBL = other._actualJBL;

	_compV = other._compV;
	_orgV = other._orgV;
	_vect = other._vect;
	_jacobstalV = other._jacobstalV;
	_actualJBV = other._actualJBV;
}
PmergeMe::~PmergeMe()
{
	_group_size = 0;

	_compL = 0;
	_orgL.clear();
	_list.clear();
	_jacobstalL.clear();
	_actualJBL = 0;

	_compV = 0;
	_orgV.clear();
	_vect.clear();
	_jacobstalV.clear();
	_actualJBV = 0;
}
/* ----- */

/* Operator overloads */
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_group_size = other._group_size;

		_compL = other._compL;
		_orgL = other._orgL;
		_list = other._list;
		_jacobstalL = other._jacobstalL;
		_actualJBL = other._actualJBL;

		_compV = other._compV;
		_orgV = other._orgV;
		_vect = other._vect;
		_jacobstalV = other._jacobstalV;
		_actualJBV = other._actualJBV;
	}
	return (*this);
}
/* ----- */

/* Utils	*/
static long long getMicroseconds()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
}

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
	long long	startV = getMicroseconds();

	// Parse
	for (int i = 1; i < argc; i++)
	{
		t_numV	temp;
		temp.value = ft_atoi(arg[i]);
		_vect.push_back(temp);
	}

	for (size_t t = 0; t < _vect.size(); t++)
	{
		for (size_t v = t + 1; v < _vect.size(); v++)
		{
			if (_vect[t].value == _vect[v].value)
			{
				std::cout << "Error: Can't accept duplicates!" << std::endl;
				return ;
			}
		}
	}
	_orgV = _vect;
	mergeInsertionV(_vect);
	long long endV = getMicroseconds();

	long long startL = getMicroseconds();
	// Parse
	for (int i = 1; i < argc; i++)
	{
		t_numL	temp;
		temp.value = ft_atoi(arg[i]);
		_list.push_back(temp);
	}

	for (size_t t = 0; t < _list.size(); t++)
	{
		for (size_t v = t + 1; v < _list.size(); v++)
		{
			if (list_at(_list, t).value == list_at(_list, v).value)
			{
				std::cout << "Error: Can't accept duplicates!" << std::endl;
				return ;
			}
		}
	}
	_orgL = _list;
	mergeInsertionL(_list);
	long long endL = getMicroseconds();

	std::cout << "Before: \t";
	for (size_t i = 0; i < _orgV.size(); i++)
		std::cout << _orgV[i].value << " ";
	std::cout << std::endl;

	std::cout << "After: \t\t";
	for (size_t i = 0; i < _list.size(); i++)
		std::cout << _vect[i].value << " ";
	std::cout << std::endl;

	if (SHOW_COUNTER)
	{
		std::cout << "Comparations used (for vector): \t" << _compV << std::endl;
		std::cout << "Comparations used (for list): \t\t" << _compL << std::endl;
	}

	double timeV = (double)(endV - startV);
	double timeL = (double)(endL - startL);

	std::cout << "Time to process a range of " << _orgV.size() << " elements with std::vector: \t" << timeV << " ms" << std::endl;
	std::cout << "Time to process a range of " << _orgL.size() << " elements with std::list: \t" << timeL << " ms" << std::endl;

	if (SHOW_SORT)
	{
		std::cout << "Is <vector> sorted?\t::\t";
		if (checkifSortedV(_vect))
			std::cout << "\033[0;32m" << "YES" << std::endl;
		else
			std::cout << "\033[0;31m" << "NOOO!!" << std::endl;
		std::cout << "\033[0m" << std::endl;

		std::cout << "Is <list> sorted?\t::\t";
		if (checkifSortedL(_list))
			std::cout << "\033[0;32m" << "YES" << std::endl;
		else
			std::cout << "\033[0;31m" << "NOOO!!" << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
}
/* ----- */

// -- Solved with `List` zone -->
#pragma region LIST

void	PmergeMe::printList(std::list<t_numL> lst, int all)
{
	for (size_t i = 0; i < lst.size(); i++)
	{
		std::cout << "[" << i << "] = " << list_at(lst, i).value << std::endl;
		if (all)
		{
			std::cout << "   Groups: ";
			for (size_t j = 0; j < list_at(lst, i)._group.size(); j++)
			{
				std::list<size_t>	tmp_g = list_at(lst, i)._group;
				std::cout << list_at(tmp_g, j) << ", ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

bool	PmergeMe::checkifSortedL(std::list<t_numL> lst)
{
	for (size_t t = 0; t < lst.size(); t++)
		for (size_t v = t + 1; v < lst.size(); v++)
			if (list_at(lst, t).value > list_at(lst, t).value)
				return (0);
	return (1);
}

size_t	PmergeMe::nextJacobstalLDouble(size_t actual)
{
	if (_jacobstalL.size() == 0)
	{
		_jacobstalL.push_back(2);
		_jacobstalL.push_back(2);
		_jacobstalL.push_back(6);
	}
	if (actual >= _jacobstalL.size())
	{
		size_t	n = _jacobstalL.size();
		size_t	next = list_at(_jacobstalL, n - 1) + 2 * list_at(_jacobstalL, n - 2);
		next *= 2;
		_jacobstalL.push_back(next);
	}
	return (actual);
}

size_t	PmergeMe::binarySearchL(std::list<t_numL> lst, size_t num)
{
	size_t	left = 0;
	size_t	right = lst.size();
	size_t	mid = (left + right) / 2;

	// Num is the smaller one ->
	if (num < lst.begin()->value)
	{
		_compL++;
		return (0);
	}
	// Num is the bigger one ->
	if (num > lst.back().value)
	{
		_compL++;
		return (lst.size());
	}
	while (left < right)
	{
		mid = (left + right) / 2;
		// In Middle (case 0 [1] 2 ...)
		if (!(mid + 1 > lst.size()))
		{
			if (num > list_at(lst, mid).value && num < list_at(lst, mid + 1).value)
			{
				_compL++;
				return (mid + 1);
			}
		}
		// In Middle (case ... 3 [4] 5)
		if (!(mid - 1 < 0))
		{
			if (num > list_at(lst, mid - 1).value && num < list_at(lst, mid).value)
			{
				_compL++;
				return (mid);
			}
		}
		if (num > list_at(lst, mid).value)
		{
			_compL++;
			left = mid;
		}
		if (num < list_at(lst, mid).value)
		{
			_compL++;
			right = mid;
		}
	}
	return (mid);
}

size_t	PmergeMe::pairtoInsertL(std::list<t_numL> major, std::list<t_numL> minor)
{
	size_t to_insert = 0;
	if (major.empty() || minor.empty())
		return (0);
	size_t	group_id = 0;
	if (major.size())
		group_id = major.begin()->_group.back();
	for (to_insert = 0; to_insert < minor.size(); to_insert++)
		if (!list_at(minor, to_insert)._group.empty())
			if (list_at(minor, to_insert)._group.back() == group_id)
				return (to_insert);
	return (to_insert);
}

std::list<t_numL>	PmergeMe::popPositionL(std::list<t_numL> org, size_t pos)
{
	std::list<t_numL>	list;
	for (size_t i = 0; i < org.size(); i++)
		if (i != pos)
			list.push_back(list_at(org, i));
	org.clear();
	return (list);
}

std::list<t_numL>	PmergeMe::pushPositionL(std::list<t_numL> org, t_numL to_push, size_t pos)
{
	std::list<t_numL>	tmp;
	if (pos >= org.size())
	{
		org.push_back(to_push);
		return (org);
	}
	for (size_t i = 0; i < org.size(); i++)
	{
		if (i != pos)
			tmp.push_back(list_at(org, i));
		else
		{
			tmp.push_back(to_push);
			tmp.push_back(list_at(org, i));
		}
	}
	return (tmp);
}

void	PmergeMe::mergeInsertionL(std::list<t_numL> sort)
{
	if (sort.size() <= 1)
		return ;

	std::list<t_numL>	major, minor;
	size_t	gr = 0;
	_group_size++;

	// Separate into pairs
	for (size_t v = 0; v < sort.size(); v++)
	{
		if (v + 1 >= sort.size())
			minor.push_back(list_at(sort, v));
		else
		{
			if (list_at(sort, v).value > list_at(sort, v + 1).value)
			{
				_compL++;
				list_at(sort, v)._group.push_back(gr);
				major.push_back(list_at(sort, v));
				if (v + 1 < sort.size())
				{
					list_at(sort, v + 1)._group.push_back(gr);
					minor.push_back(list_at(sort, v + 1));
				}
				v++;
				gr++;
			}
			else if (list_at(sort, v).value < list_at(sort, v + 1).value)
			{
				_compL++;
				list_at(sort, v)._group.push_back(gr);
				if (v + 1 < sort.size())
				{
					list_at(sort, v + 1)._group.push_back(gr);
					major.push_back(list_at(sort, v + 1));
				}
				minor.push_back(list_at(sort, v));
				gr++;
				v++;
			}
		}
	}
	// Keep separating the major stack until only have 1 element ->
	mergeInsertionL(major);
	_group_size--;

	//* Insertion ->
	//--> Look for minor number's pair in major stack
	size_t	to_insert = 0;
	if (major.size() == 1)
		to_insert = pairtoInsertL(major, minor);
	else
		to_insert = pairtoInsertL(_list, minor);

	sort.clear();
	// Remember to remove the inserted element in minor stack!
	minor = popPositionL(minor, to_insert);
	if (major.size() == 1)
		major.push_front(list_at(minor, to_insert));
	else
		_list.push_front(list_at(minor, to_insert));
	_list = sort;
	major.clear();

	// Insert the restant elements in minor list ->
	if (minor.size())
	{
		//--> Group the restant elements in groups, each one with size of respective Jacobstall serie x2
		std::list<std::list<t_numL> >	groups;

		size_t	e = 0;
		_actualJBL = 0;
		while (e < minor.size())
		{
			std::list<t_numL>	temp;
			for (size_t j = 0; j < list_at(_jacobstalL, _actualJBL); j++)
			{
				if (e >= minor.size())
					break ;
				temp.push_back(list_at(minor, e));
				e++;
			}
			groups.push_back(temp);
			//Get next Jacobstal number
			_actualJBL = nextJacobstalLDouble(++_actualJBL);
		}
		//--> In groups (n1, n2, etc..), insert first the larger index
		/*	Group 1 & 2-> Insert first [1], later [0]
		*	Group 3 -> Insert first [5], [4], [3] .. etc (if insuficient numbers, start by the larger index)
		*	- Insert them in `sort` list using binary search.
		*/
		for (size_t i = 0; i < groups.size(); i++)
		{
			std::list<t_numL>	temp = list_at(groups, i);
			size_t	j = temp.size() - 1;
			while (j < temp.size())
			{
				to_insert = binarySearchL(_list, list_at(temp, j).value);
				_list = pushPositionL(_list, list_at(temp, j), to_insert);
				if (j == 0)
					break ;
				j--;
			}
		}
	}

	//Asegurate all numbers have the same group_size
	for (size_t i = 0; i < _list.size(); i++)
		while (list_at(_list, i)._group.size() > _group_size)
			list_at(_list, i)._group.pop_back();
}

#pragma endregion

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

bool	PmergeMe::checkifSortedV(std::vector<t_numV> vec)
{
	for (size_t t = 0; t < vec.size(); t++)
		for (size_t v = t + 1; v < vec.size(); v++)
			if (vec[t].value > vec[v].value)
				return (0);
	return (1);
}

size_t	PmergeMe::nextJacobstalVDouble(size_t actual)
{
	if (_jacobstalV.size() == 0)
	{
		_jacobstalV.push_back(2);
		_jacobstalV.push_back(2);
		_jacobstalV.push_back(6);
	}
	if (actual >= _jacobstalV.size())
	{
		size_t	n = _jacobstalV.size();
		size_t	next = _jacobstalV[n - 1] + 2 * _jacobstalV[n - 2];
		next *= 2;
		_jacobstalV.push_back(next);
	}
	return (actual);
}

size_t	PmergeMe::binarySearchV(std::vector<t_numV> vec, size_t num)
{
	size_t	left = 0;
	size_t	right = vec.size();
	size_t	mid = (left + right) / 2;

	// Num is the smaller one ->
	if (num < vec[0].value)
	{
		_compV++;
		return (0);
	}
	// Num is the bigger one ->
	if (num > vec.back().value)
	{
		_compV++;
		return (vec.size());
	}
	while (left < right)
	{
		mid = (left + right) / 2;
		// In Middle (case 0 [1] 2 ...)
		if (!(mid + 1 > vec.size()))
		{
			if (num > vec[mid].value && num < vec[mid + 1].value)
			{
				_compV++;
				return (mid + 1);
			}
		}
		// In Middle (case ... 3 [4] 5)
		if (!(mid - 1 < 0))
		{
			if (num > vec[mid - 1].value && num < vec[mid].value)
			{
				_compV++;
				return (mid);
			}
		}
		if (num > vec[mid].value)
		{
			_compV++;
			left = mid;
		}
		if (num < vec[mid].value)
		{
			_compV++;
			right = mid;
		}
	}
	return (mid);
}

size_t	PmergeMe::pairtoInsertV(std::vector<t_numV> major, std::vector<t_numV> minor)
{
	size_t to_insert = 0;
	if (major.empty() || minor.empty())
		return (0);
	size_t	group_id = 0;
	if (major.size())
		group_id = major[0]._group.back();
	for (to_insert = 0; to_insert < minor.size(); to_insert++)
		if (!minor[to_insert]._group.empty())
			if (minor[to_insert]._group.back() == group_id)
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
	if (pos >= org.size())
	{
		org.push_back(to_push);
		return (org);
	}
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
	_group_size++;

	// Separate into pairs
	for (size_t v = 0; v < sort.size(); v++)
	{
		if (v + 1 >= sort.size())
			minor.push_back(sort[v]);
		else
		{
			if (sort[v].value > sort[v + 1].value)
			{
				_compV++;
				sort[v]._group.push_back(gr);
				major.push_back(sort[v]);
				if (v + 1 < sort.size())
				{
					sort[v + 1]._group.push_back(gr);
					minor.push_back(sort[v + 1]);
				}
				v++;
				gr++;
			}
			else if (sort[v].value < sort[v + 1].value)
			{
				_compV++;
				sort[v]._group.push_back(gr);
				if (v + 1 < sort.size())
				{
					sort[v + 1]._group.push_back(gr);
					major.push_back(sort[v + 1]);
				}
				minor.push_back(sort[v]);
				gr++;
				v++;
			}
		}
	}
	// Keep separating the major stack until only have 1 element ->
	mergeInsertionV(major);
	_group_size--;

	//* Insertion ->
	//--> Look for minor number's pair in major stack
	size_t	to_insert = 0;
	if (major.size() == 1)
		to_insert = pairtoInsertV(major, minor);
	else
		to_insert = pairtoInsertV(_vect, minor);

	sort.clear();
	sort.push_back(minor[to_insert]);
	// Remember to remove the inserted element in minor stack!
	minor = popPositionV(minor, to_insert);
	if (major.size() == 1)
		for (size_t i = 0; i < major.size(); i++)
			sort.push_back(major[i]);
	else
		for (size_t i = 0; i < _vect.size(); i++)
			sort.push_back(_vect[i]);
	_vect = sort;
	major.clear();

	// Insert the restant elements in minor vect ->
	if (minor.size())
	{
		//--> Group the restant elements in groups, each one with size of respective Jacobstall serie x2
		std::vector<std::vector<t_numV> >	groups;

		size_t	e = 0;
		_actualJBV = 0;
		while (e < minor.size())
		{
			std::vector<t_numV>	temp;
			for (size_t j = 0; j < _jacobstalV[_actualJBV]; j++)
			{
				if (e >= minor.size())
					break ;
				temp.push_back(minor[e]);
				e++;
			}
			groups.push_back(temp);
			//Get next Jacobstal number
			_actualJBV = nextJacobstalVDouble(++_actualJBV);
		}
		//--> In groups (n1, n2, etc..), insert first the larger index
		/*	Group 1 & 2-> Insert first [1], later [0]
		*	Group 3 -> Insert first [5], [4], [3] .. etc (if insuficient numbers, start by the larger index)
		*	- Insert them in `sort` list using binary search.
		*/
		for (size_t i = 0; i < groups.size(); i++)
		{
			std::vector<t_numV>	temp = groups[i];
			size_t	j = temp.size() - 1;
			while (j < temp.size())
			{
				to_insert = binarySearchV(_vect, temp[j].value);
				_vect = pushPositionV(_vect, temp[j], to_insert);
				if (j == 0)
					break ;
				j--;
			}
		}
	}

	//Asegurate all numbers have the same group_size
	for (size_t i = 0; i < _vect.size(); i++)
		while (_vect[i]._group.size() > _group_size)
			_vect[i]._group.pop_back();
}
#pragma endregion
