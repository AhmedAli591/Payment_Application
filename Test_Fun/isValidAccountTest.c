#include "Test.h"

void isValidAccountTest(void)
{
	EN_serverError_t Stat = SERVER_OK;
	ST_cardData_t cardData;
	ST_accountsDB_t accountRefrence;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: isValidAccount\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	strcpy_s(cardData.primaryAccountNumber, 20, "8989374615436852");

	Stat = isValidAccount(&cardData,&accountRefrence);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : ACCOUNT_NOT_FOUND\n");

	if (Stat == ACCOUNT_NOT_FOUND)
	{
		printf("Actual Result: ACCOUNT_NOT_FOUND\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}

	printf("Test Case 2:\n");
	strcpy_s(cardData.primaryAccountNumber, 20, "8989374615436851");

	Stat = isValidAccount(&cardData,&accountRefrence);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : SERVER_OK\n");

	if (Stat == ACCOUNT_NOT_FOUND)
	{
		printf("Actual Result: ACCOUNT_NOT_FOUND\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}

}