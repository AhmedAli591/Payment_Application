#include "Test.h"

void getTransactionDateTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t Stat = TERMINAL_OK;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: getTransactionDate\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	strcpy_s(termData.transactionDate, 11, "11/11-2020");

	Stat = getTransactionDate(&termData);
	printf("Input Data: %s \n", termData.transactionDate);

	printf("Expected Result : WRONG_DATE\n");

	if (Stat == WRONG_DATE)
	{
		printf("Actual Result: WRONG_DATE\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 2:\n");
	strcpy_s(termData.transactionDate, 11, "11-11/2020");

	Stat = getTransactionDate(&termData);
	printf("Input Data: %s \n", termData.transactionDate);

	printf("Expected Result : WRONG_DATE\n");

	if (Stat == WRONG_DATE)
	{
		printf("Actual Result: WRONG_DATE\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 3:\n");
	strcpy_s(termData.transactionDate, 11, "11/11/20"); //YYYY

	Stat = getTransactionDate(&termData);
	printf("Input Data: %s \n", termData.transactionDate);

	printf("Expected Result : WRONG_DATE\n");

	if (Stat == WRONG_DATE)
	{
		printf("Actual Result: WRONG_DATE\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 4:\n");
	strcpy_s(termData.transactionDate, 12, "11-11/20200");

	Stat = getTransactionDate(&termData);
	printf("Input Data: %s \n", termData.transactionDate);

	printf("Expected Result : WRONG_DATE\n");

	if (Stat == WRONG_DATE)
	{
		printf("Actual Result: WRONG_DATE\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 5:\n");
	strcpy_s(termData.transactionDate, 11, "11/11/2020");

	Stat = getTransactionDate(&termData);
	printf("Input Data: %s \n", termData.transactionDate);

	printf("Expected Result : TERMINAL_OK\n");

	if (Stat == WRONG_DATE)
	{
		printf("Actual Result: WRONG_DATE\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}
}