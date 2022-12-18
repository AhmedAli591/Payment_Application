#include "Test.h"

void isAmountAvailableTest(void)
{
	EN_serverError_t Stat = SERVER_OK;
	ST_accountsDB_t accountRefrence;
	ST_terminalData_t termData;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: isAmountAvailable\n");
	printf("/*******************************************************/\n");
	accountRefrence.balance = 50; //const

	printf("Test Case 1:\n");
	termData.transAmount = 100;	//more

	Stat = isAmountAvailable(&termData, &accountRefrence);
	printf("Input Data: %.2f \n", termData.transAmount);

	printf("Expected Result : LOW_BALANCE\n");

	if (Stat == LOW_BALANCE)
	{
		printf("Actual Result: LOW_BALANCE\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}

	printf("Test Case 2:\n");
	termData.transAmount = 40;	//less

	Stat = isAmountAvailable(&termData, &accountRefrence);
	printf("Input Data: %.2f \n", termData.transAmount);

	printf("Expected Result : SERVER_OK\n");

	if (Stat == LOW_BALANCE)
	{
		printf("Actual Result: LOW_BALANCE\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}

	printf("Test Case 3:\n");
	termData.transAmount = 50;	//equal

	Stat = isAmountAvailable(&termData, &accountRefrence);
	printf("Input Data: %.2f \n", termData.transAmount);

	printf("Expected Result : SERVER_OK\n");

	if (Stat == LOW_BALANCE)
	{
		printf("Actual Result: LOW_BALANCE\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}

}