/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:29:08 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/18 19:51:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <ctime>
# include <map>
# include <string>

class BitcoinExchange
{
	private:
		std::map<time_t, int>	_database;
		std::map<time_t, int>	_input_toMap;

	protected:
		long	fileWidth(const char *fileName);
		void	parseInput(const char *fileName);
		void	parseDataBase(void);

	public:
		BitcoinExchange();
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);
		//** */
		//btc
};

#endif
