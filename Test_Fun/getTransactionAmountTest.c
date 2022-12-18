#include "Test.h"
void getTransactionAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t Stat = TERMINAL_OK;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: getTransactionAmount\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	termData.transAmount = 0; // zero state

	Stat = getTransactionAmount(&termData);
	printf("Input Data: %f \n", termData.transAmount);

	printf("Expected Result : INVALID_AMOUNT\n");

	if (Stat == INVALID_AMOUNT)
	{
		printf("Actual Result: INVALID_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 2:\n");
	termData.transAmount = -5.0; // negative state

	Stat = getTransactionAmount(&termData);
	printf("Input Data: %f \n", termData.transAmount);

	printf("Expected Result : INVALID_AMOUNT\n");

	if (Stat == INVALID_AMOUNT)
	{
		printf("Actual Result: INVALID_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 3:\n");
	termData.transAmount = 5.0; // ok state

	Stat = getTransactionAmount(&termData);
	printf("Input Data: %f \n", termData.transAmount);

	printf("Expected Result : TERMINAL_OK\n");

	if (Stat == INVALID_AMOUNT)
	{
		printf("Actual Result: INVALID_AMOUNT\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}
}