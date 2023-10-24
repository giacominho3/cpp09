#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Sintassi del programma errata, istruzioni per un corretto utilizzo:" << std::endl;
		std::cerr << "1) Creare un file .txt" << std::endl;
		std::cerr << "2) Riempire il file come richiesto da subject" << std::endl;
		std::cerr << "3) Eseguire il programma con ./btc <nomefile>.txt" << std::endl;
		return (1);
	}
	try 
	{
		BitcoinExchange btc = BitcoinExchange();
		btc.readFile(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: ";
		std::cerr << e.what() << std::endl;
	}
}