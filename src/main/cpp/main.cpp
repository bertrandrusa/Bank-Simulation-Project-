/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2023
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the main target.
 * @version 1.0.0
 * @date    09/02/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */

#include "csc232.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, Main Target!" << std::endl;

#if EXECUTE_PREAMBLE
    return csc232::Preamble(argc, argv);
#else
    return EXIT_SUCCESS;
#endif
}

int csc232::Preamble(int argc, char* argv[])
{
	// An input file to process
	std::string input_file;

	// Check to see if the user has supplied a specific input file for consumption
	if (argc > 1)
	{
		// It is expected as the first argument
		input_file = argv[1];
	}
	else
	{
		// Default input file
		input_file = "main_data.txt";
	}

	// Open the file for reading
	std::ifstream data_file{ input_file, std::ios::in };

	if (!data_file)
	{
		std::cout << "Could not open \"" << input_file << "\"" << std::endl;
		return EXIT_FAILURE;
	}
	else
	{
		std::cout << "Successfully opened \"" << input_file << "\"";

		std::cout << "... will now close this file" << std::endl;
		if (data_file.is_open())
		{
			data_file.close();
		}
	}

	return EXIT_SUCCESS;
}
