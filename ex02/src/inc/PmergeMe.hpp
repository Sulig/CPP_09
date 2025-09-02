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

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>

class PmergeMe
{
	private:
		std::vector<int>	_vect;

	protected:
		int		ft_atoi(const std::string str);

	public:
		PmergeMe();
		PmergeMe(const char *arg);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);
		//** */
		void	pmergeMe(const char *arg);
};
#endif
