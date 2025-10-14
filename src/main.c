/*
 *	Copyright (c) 2025, Signaloid.
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "common.h"
#include <unistd.h>
#include <uxhw.h>

/*
 *	Constants.
 */
enum
{
	kOutputVariablesSize = 1,
	kJSONVariableSize = 1
};

int
main(int argc, char *argv[])
{
	int		opt;
	JSONVariable	jsonOutputVariables[kOutputVariablesSize];
	double		commandLineArgDistributionalInput;
	double		calculatedOutput;
	/*
	 *	Simple command-line argument parsing.
	 *
	 *	Common utilities provide functions for parsing default and custom commmand-line arguments.
	 */
	while ((opt = getopt(argc, argv, "k:j")) != -1)
	{
		switch (opt)
		{
			case 'k':
			{
				/*
				 *	Parse a distributional input and write it to a double
				 *	variable. This works for both the basic and distributional sliders.
				 */
				parseDoubleChecked(optarg, &commandLineArgDistributionalInput);

				break;
			}
			case 'j':
				break;
			case '?':
				fprintf(stderr, "Usage: %s [-k value, -j]\n", argv[0]);
				exit(EXIT_FAILURE);
			default:
				abort();
		}
	}

	/*
	 *	Processing the input from the sliders, provided as a command-line argument.
	 *
	 *	Example: Shift a Gaussian distribution using the slider input.
	 */
	calculatedOutput = UxHwDoubleGaussDist(0.0, 1.0) + commandLineArgDistributionalInput;

	/*
	 *	Prepare output for printing.
	 *
	 *	The JSON printer of common utilities generates output that is easy for web applications to parse.
	 */
	jsonOutputVariables[0].values.asDouble = &calculatedOutput;
	strncpy(jsonOutputVariables[0].variableSymbol, "calculatedOutput", kCommonConstantMaxCharsPerJSONVariableSymbol);
	strncpy(jsonOutputVariables[0].variableDescription, "The calculated output", kCommonConstantMaxCharsPerJSONVariableDescription);

	jsonOutputVariables[0].type = kJSONVariableTypeDouble;
	jsonOutputVariables[0].size = kJSONVariableSize;

	/*
	 *	Print as many outputs as the number of inputs provided.
	 */
	printJSONVariables(
		jsonOutputVariables,
		kOutputVariablesSize,
		"All outputs");

	return 0;
}
