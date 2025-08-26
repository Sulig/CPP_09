/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:29:30 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/26 20:12:54 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/BitcoinExchange.hpp"
#include <iostream>

	/*	TODO ->
	*-	Read input
	*-		- if incorrect (bad file or illegible) -> stop program
	*-		- if correct -> parse to _input_toMap
	*-	Read Database
	*-		- if encountered	-> parse to _database
	*-		- if 404			-> Cout error and exit program
	*-	Read _input_toMap and perform corresponent action:
	*	*-	Comprove if line is correct
	*	*-	 That includes take care of:
	*			- wrong date
	*			- wrong number
	*			- empty line
	*	*-	If correct ->
	*		-	get date and search it in database
	*			** get the lower date next to the corresponent date.
	*			** or return no-exist date (if date more low than database first date)
	*		-	perform btc exchange and print.
	*	*-	Repeat until EOF.
	*/

/* Constructor & destructor */
BitcoinExchange::BitcoinExchange() { parseDataBase(); }
BitcoinExchange::BitcoinExchange(const char *fileName)
{
	parseInput(fileName);
	parseDataBase();
	//btc
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database), _input_toMap(other._input_toMap) {}
BitcoinExchange::~BitcoinExchange()
{
	_database.clear();
	_input_toMap.clear();
	_errors.clear();
}
/* ----- */

/* Operator overloads */
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_database = other._database;
		_input_toMap = other._input_toMap;
		_errors = other._errors;
	}
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
int	BitcoinExchange::ft_atoi(const std::string str)
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
//** */
long	BitcoinExchange::fileWidth(const char *fileName)
{
	std::ifstream	file;
	long			lines;

	lines = 0;
	file.open(fileName, std::ios::in);
	if (!file.is_open())
	{
		std::cout << fileName << std::endl;
		std::cout << "File not found." << std::endl;
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
			if (year % 4 == 0 && year % 100)
				if (day > 29)
					return false;
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
void	BitcoinExchange::parseInput(const char *fileName)
{
	std::string	*fileContent = readFile(fileName);

	for (int i = 1; i < arrstrlen(fileContent); i++)
	{
		std::stringstream _line(fileContent[i]);
		std::string	date, value;
		if (std::getline(_line, date, '|') && std::getline(_line, value))
			_input_toMap[date] = ft_atoi(value);
		else
		{
			_input_toMap["Error " + date] = 0;
			_errors[date] = "Error: bad input => ";
		}
	}
	delete [] fileContent;
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
			_database[date] = ft_atoi(value);
		}
	}
	delete [] fileContent;
}
/* ----- */

/*	BTC	*/
/* ----- */

