/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:31 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/03 20:08:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/PmergeMe.hpp"

int	main(int argc, const char** argv)
{
	if (argc < 2)
	{
		std::cout << "Put more arguments!" << std::endl;
		return (0);
	}

	PmergeMe merge(argv, argc);
	return (0);
}
