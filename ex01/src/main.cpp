/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:31 by sadoming          #+#    #+#             */
/*   Updated: 2025/09/01 18:53:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/RPN.hpp"

int	main(int argc, const char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please introduce only one arg in program execution" << std::endl;
		return (0);
	}

	RPN rpn(argv[1]);
	return (0);
}
