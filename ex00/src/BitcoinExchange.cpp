/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:29:30 by sadoming          #+#    #+#             */
/*   Updated: 2025/08/18 20:02:05 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/BitcoinExchange.hpp"

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
BitcoinExchange::BitcoinExchange()
{

}
BitcoinExchange::BitcoinExchange(std::string fileName)
{
	//parse input

	//parse DB
	//btc
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database), _input_toMap(other._input_toMap) {}
BitcoinExchange::~BitcoinExchange() { }
/* ----- */

/* Operator overloads */
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_database = other._database;
		_input_toMap = other._input_toMap;
	}
	return (*this);
}
/* ----- */

/* Utils	*/
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
		exit(1);
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
void	BitcoinExchange::parseInput(const char *fileName)
{
	std::ifstream	file;
	long			lines;

	lines = fileWidth(fileName);
	if (lines == 0)
	{
		std::cout << "File is empty." << std::endl;
		exit(0);
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
	// TODO parsing
}
//** */
void	BitcoinExchange::parseDataBase()
{
	// TODO ->
	//*- search DB in structure dir.
	/*
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
	*/
}
/* ----- */

/*	BTC	*/
/* ----- */

