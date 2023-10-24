#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:

		std::map<std::string, float> _dToVal;

	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
    	BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		void add(std::string line);
		void readFile(std::string pathname);
		void parseLine(std::string line);

		class NonPositiveException: public std::exception
    	{
        	public:
            	virtual const char *what() const throw();
    	};

		class BadInputException: public std::exception
    	{
        	public:
            	virtual const char *what() const throw();
    	};

		class TooLargeException: public std::exception
    	{
        	public:
            	virtual const char *what() const throw();
    	};

		class FileOpeningException: public std::exception
    	{
        	public:
            	virtual const char *what() const throw();
    	};
};

#endif