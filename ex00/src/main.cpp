/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:04:01 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/18 20:04:04 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/BitcoinExchange.hpp"

int main(int argc, const char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please introduce only one file in program execution" << std::endl;
		return (0);
	}

	BitcoinExchange btc(argv[1]);
	return 0;
}
