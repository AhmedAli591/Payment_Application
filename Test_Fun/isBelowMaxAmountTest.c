#include "Test.h"

void isBelowMaxAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t Stat = TERMINAL_OK;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: isBelowMaxAmount\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	termData.maxTransAmount = 0; // zero state

	termData.transAmount = 50;
	Stat = isBelowMaxAmount(&termData);
	printf("Input Data: %f \n", termData.maxTransAmount);

	printf("Expected Result : EXCEED_MAX_AMOUNT\n");

	if (Stat == EXCEED_MAX_AMOUNT)
	{
		printf("Actual Result: EXCEED_MAX_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 2:\n");
	termData.maxTransAmount = 10000; // High state

	termData.transAmount = 50;
	Stat = isBelowMaxAmount(&termData);
	printf("Input Data: %f \n", termData.maxTransAmount);

	printf("Expected Result : TERMINAL_OK\n");

	if (Stat == EXCEED_MAX_AMOUNT)
	{
		printf("Actual Result: EXCEED_MAX_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

}