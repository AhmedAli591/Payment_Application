#include "Test.h"

void setMaxAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t Stat = TERMINAL_OK;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: setMaxAmount\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");

	Stat = setMaxAmount(&termData,0);	//zero state
	printf("Input Data: %f \n", termData.maxTransAmount);

	printf("Expected Result : INVALID_MAX_AMOUNT\n");

	if (Stat == INVALID_MAX_AMOUNT)
	{
		printf("Actual Result: INVALID_MAX_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 2:\n");

	Stat = setMaxAmount(&termData,-50);	// negative state
	printf("Input Data: %f \n", termData.maxTransAmount);

	printf("Expected Result : INVALID_MAX_AMOUNT\n");

	if (Stat == INVALID_MAX_AMOUNT)
	{
		printf("Actual Result: INVALID_MAX_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 3:\n");

	Stat = setMaxAmount(&termData, 50);	// positeve state
	printf("Input Data: %f \n", termData.maxTransAmount);

	printf("Expected Result : TERMINAL_OK\n");

	if (Stat == INVALID_MAX_AMOUNT)
	{
		printf("Actual Result: INVALID_MAX_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

}