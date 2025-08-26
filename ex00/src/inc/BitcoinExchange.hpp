/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:29:08 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/26 18:43:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <map>
# include <sstream>
# include <string>

# define EXIT_SUCESS	0
# define DATABASE		"data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, int>	_database;
		std::map<std::string, int>	_input_toMap;
		std::map<std::string, std::string>	_errors;

	protected:
		int		arrstrlen(std::string *arr);
		int		ft_atoi(const std::string str);
		bool	dateChecker(std::string date_str);
		long	fileWidth(const char *fileName);
		std::string	*readFile(const char *fileName);
		void	parseInput(const char *fileName);
		void	parseDataBase(void);

	public:
		BitcoinExchange();
		BitcoinExchange(const char *fileName);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);
		//** */
		//btc
};

#endif
