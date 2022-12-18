#include "Test.h"

void isBlockedAccountTest(void)
{
	EN_serverError_t Stat = SERVER_OK;
	ST_accountsDB_t accountRefrence;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: isBlockedAccount\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	accountRefrence.state = RUNNING;

	Stat = isBlockedAccount(&accountRefrence);
	printf("Input Data: RUNNING \n");

	printf("Expected Result : SERVER_OK\n");

	if (Stat == BLOCKED_ACCOUNT)
	{
		printf("Actual Result: BLOCKED_ACCOUNT\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}

	printf("Test Case 2:\n");
	accountRefrence.state = BLOCKED;

	Stat = isBlockedAccount(&accountRefrence);
	printf("Input Data: BLOCKED \n");

	printf("Expected Result : BLOCKED_ACCOUNT\n");

	if (Stat == BLOCKED_ACCOUNT)
	{
		printf("Actual Result: BLOCKED_ACCOUNT\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}

}