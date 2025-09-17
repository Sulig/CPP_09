/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:18 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/02 17:20:02 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <sys/time.h>
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <string>

# include <iterator>
# include <list>
# include <vector>

# define SHOW_COUNTER	1
# define SHOW_SORT		1

typedef struct	s_numV
{
	size_t	value;
	std::vector<size_t>	_group;
}				t_numV;

typedef struct	s_numL
{
	size_t	value;
	std::list<size_t>	_group;
}				t_numL;

class PmergeMe
{
	private:
		size_t	_group_size;

		//Vector -->
		int		_compV;

		std::vector<t_numV>	_orgV;
		std::vector<t_numV>	_vect;
		std::vector<size_t>	_jacobstalV;
		size_t				_actualJBV;

		//List -->
		int		_compL;

		std::list<t_numL>	_orgL;
		std::list<t_numL>	_list;
		std::list<size_t>	_jacobstalL;
		size_t				_actualJBL;

	protected:
		int		ft_atoi(const std::string str);

		//** */
		void	printVector(std::vector<t_numV> vec, int all);
		bool	checkifSortedV(std::vector<t_numV> vec);
		std::vector<t_numV>	popPositionV(std::vector<t_numV> org, size_t pos);
		std::vector<t_numV>	pushPositionV(std::vector<t_numV> org, t_numV to_push, size_t pos);
		size_t	nextJacobstalVDouble(size_t actual);
		size_t	binarySearchV(std::vector<t_numV> vec, size_t num);
		size_t	pairtoInsertV(std::vector<t_numV> major, std::vector<t_numV> minor);
		void	mergeInsertionV(std::vector<t_numV> sort);
		//** */

		//** */
		void	printList(std::list<t_numL> vec, int all);
		bool	checkifSortedL(std::list<t_numL> vec);
		std::list<t_numL>	popPositionL(std::list<t_numL> org, size_t pos);
		std::list<t_numL>	pushPositionL(std::list<t_numL> org, t_numL to_push, size_t pos);
		size_t	nextJacobstalLDouble(size_t actual);
		size_t	binarySearchL(std::list<t_numL> vec, size_t num);
		size_t	pairtoInsertL(std::list<t_numL> major, std::list<t_numL> minor);
		void	mergeInsertionL(std::list<t_numL> sort);

		template <typename T>
		typename std::list<T>::reference	list_at(std::list<T>& lst, size_t idx)
		{
			typename std::list<T>::iterator it = lst.begin();
			for (size_t i = 0; i < lst.size(); i++)
			{
				if (i == idx)
					return (*it);
				else
					it++;
			}
			return (*it);
		}
		//** */

	public:
		PmergeMe();
		PmergeMe(const char **arg, int argc);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);
		//** */

		void	checkArg(const char **arg, int argc);
		void	pmergeMe(const char **arg, int argc);
};
#endif
