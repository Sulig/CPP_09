/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:29:30 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/28 19:29:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/BitcoinExchange.hpp"

/* Constructor & destructor */
BitcoinExchange::BitcoinExchange() { parseDataBase(); }
BitcoinExchange::BitcoinExchange(const char *fileName)
{
	parseDataBase();
	btc(fileName);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database), _input_toMap(other._input_toMap) {}
BitcoinExchange::~BitcoinExchange() {	_database.clear();	}
/* ----- */

/* Operator overloads */
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		_database = other._database;
	return (*this);
}
/* ----- */

/* Utils	*/
int	BitcoinExchange::arrstrlen(std::string *arr)
{
	int	size = 0;
	if (arr)
		while (!arr[size].empty())
			size++;
	return (size);
}
//** */
long	BitcoinExchange::fileWidth(const char *fileName)
{
	std::ifstream	file;
	long			lines;

	lines = 0;
	file.open(fileName, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "File " << fileName << " not found" << std::endl;
		exit(0);
	}
	while (!file.eof())
	{
		std::string	line;
		std::getline(file, line);
		if (lines == 0 && line.empty())
			break ;
		lines++;
	}
	file.close();
	return (lines);
}
//** */
bool	BitcoinExchange::dateChecker(std::string date_str)
{
	int		year, month, day;
	char	sep1, sep2;
	std::istringstream ss(date_str);

	if (!(ss >> year >> sep1 >> month >> sep2 >> day) || sep1 != '-' || sep2 != '-')
	{
		std::cerr << "Error: invalid format in => " << date_str << std::endl;
		return false;
	}
	if (day < 1 || day > 31 || month < 1 || month > 12)
		return (false);
	switch (month)
	{
		case 2:
			if (year % 4 == 0 && year % 100 != 0)
			{
				if (day > 29)
					return false;
				return true;
			}
			if (day > 28)
				return false;
			break ;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31)
				return false;
			break ;
		case 4: case 6: case 9: case 11:
			if (day > 30)
				return false;
			break ;
		default:
			return false;
	}
	return (true);
}
//** */
std::string	*BitcoinExchange::readFile(const char *fileName)
{
	std::ifstream	file;
	long			lines;

	lines = fileWidth(fileName);
	if (lines == 0)
	{
		std::cout << "File is empty." << std::endl;
		exit(EXIT_SUCESS);
	}
	//** */
	file.open(fileName, std::ios::in);
	// Create a string array to store the file content
	std::string *fileContent = new std::string[lines + 1];
	lines = 0;
	while (!file.eof())
	{
		std::string	line;
		std::getline(file, line);
		fileContent[lines++] = line;
	}
	fileContent[lines] = "";
	file.close();
	//** */
	return (fileContent);
}
//** */
void	BitcoinExchange::parseDataBase()
{
	std::string	*fileContent = readFile(DATABASE);

	for (int i = 1; i < arrstrlen(fileContent); i++)
	{
		std::stringstream _line(fileContent[i]);
		std::string	date, value;
		if (std::getline(_line, date, ',') && std::getline(_line, value))
		{
			if (dateChecker(date) == false)
				exit(EXIT_FAILURE);
			_database[date] = std::strtod(value.c_str(), NULL);
		}
	}
	delete [] fileContent;
}
/* ----- */

/*	BTC	*/
void	BitcoinExchange::btc(const char *fileName)
{
	if (_database.empty())
		parseDataBase();

	std::string	*fileContent = readFile(fileName);

	for (int i = 1; i < arrstrlen(fileContent); i++)
	{
		std::stringstream _line(fileContent[i]);
		std::string	date, value;
		if (std::getline(_line, date, '|') && std::getline(_line, value))
		{
			if (dateChecker(date))
			{
				if (std::strtod(value.c_str(), NULL) < 0)
					std::cout << "Error: not a positive number" << std::endl;
				else if (std::strtod(value.c_str(), NULL) > INT_MAX)
					std::cout << "Error: too large number" << std::endl;
				else
				{
					std::map<std::string, double>::iterator	it = _database.lower_bound(date);
					if (it != _database.end() && it->first == date)
					{
						double	result	= it->second * std::strtod(value.c_str(), NULL);
						std::cout << date << "=> " << it->second << " = " << result << std::endl;
					}
					else
					{
						if (it == _database.begin())
							std::cout << "Error: Date is lower than the first date in Database!" << std::endl;
						else
						{
							--it;
							double	result	= it->second * std::strtod(value.c_str(), NULL);
							std::cout << date << "=> " << it->second << " = " << result << std::endl;
						}
					}
				}
			}
			else
				std::cout << "Error: bad date => " << _line.str() << std::endl;
		}
		else
			std::cout << "Error: bad input => " << _line.str() << std::endl;
	}
	delete [] fileContent;
}
/* ----- */

