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

# include <iostream>
# include <cstdlib>
# include <sstream>
# include <string>
# include <vector>

class PmergeMe
{
	private:
		int		_compV;
		//Vector -->
		typedef struct	s_numV
		{
			size_t	value;
			std::vector<size_t>	_group;
		}				t_numV;
		std::vector<t_numV>	_vect;
		std::vector<t_numV>	_orgV;

		// -->

	protected:
		int		ft_atoi(const std::string str);
		//** */
		void	printVector(std::vector<t_numV> vec, int all);
		size_t	binarySearchV(std::vector<t_numV> vec, size_t num);
		size_t	pairtoInsert(std::vector<t_numV> major, std::vector<t_numV> minor);
		void	mergeInsertionV(std::vector<t_numV> sort);
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
