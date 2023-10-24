#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("./data.csv");
	std::string line;

	if (!file.is_open())
		throw FileOpeningException();
	std::getline(file, line);
	while (std::getline(file, line))
		this->add(line);
	file.close();
}

BitcoinExchange::~BitcoinExchange()
{
	;
}

void BitcoinExchange::add(std::string line)
{
	int i;
	std::string date;
	float value;

	i = line.find(',');
	if (i == -1)
		throw BadInputException();
	date = line.substr(0, i);
	i++;
	value = std::atof(line.substr(i, line.length()).c_str());
	this->_dToVal.insert(std::pair<std::string, float>(date, value));
}

void BitcoinExchange::readFile(std::string pathname)
{
	std::ifstream file2(pathname.c_str());
	std::string line2;

	if (!file2.is_open())
		throw FileOpeningException();
	std::getline(file2, line2);
	while (std::getline(file2, line2))
	{
		try 
		{
			this->parseLine(line2);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: ";
			std::cerr << e.what() << std::endl;
		}
	}
	file2.close();
}

void BitcoinExchange::parseLine(std::string line)
{
	int i;
	std::string key;
	float value;
	float to_find;
	std::string newLine;

	for (size_t j = 0; j < line.length(); j++)
	{
		if (line[j] != ' ')
			newLine += line[j];
	}
	i = newLine.find('|');
	if (i == -1)
		throw BadInputException();
	key = newLine.substr(0, i);
	i++;
	value = std::atof(newLine.substr(i, newLine.length()).c_str());
	if (value > 1000)
		throw TooLargeException();

	if (key[5] > '1' || key[5] < '0')
		throw BadInputException();
	if (key[6] > '9' || key[6] < '0')
		throw BadInputException();
	if (key[5] == '1' && key[6] > '2')
		throw BadInputException();
	try
	{
		to_find = this->_dToVal.at(key);
		float res = value * to_find;
		if (res < 0)
			throw NonPositiveException();
		std::cout << key << " => " << value << " = " << res << std::endl; 
	}
	catch (const std::out_of_range& e)
	{
        std::cerr << "Chiave non trovata all'interno del database: " << e.what() << std::endl;
	}
}

const char *BitcoinExchange::NonPositiveException::what(void) const throw()
{
    return("not a positive number");
} 

const char *BitcoinExchange::BadInputException::what(void) const throw()
{
    return("bad input");
} 

const char *BitcoinExchange::TooLargeException::what(void) const throw()
{
    return("too large a number");
}

const char *BitcoinExchange::FileOpeningException::what(void) const throw()
{
    return("could not open file");
} 