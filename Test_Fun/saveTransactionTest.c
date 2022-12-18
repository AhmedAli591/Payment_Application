#include "Test.h"

void saveTransactionTest(void)
{
	EN_serverError_t Stat = SERVER_OK;
	ST_transaction_t transData;

	

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: saveTransaction\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");

	Stat = saveTransaction(&transData);
	
	printf("Input Data: Saved \n");
	printf("Expected Result : SERVER_OK\n");

	if (Stat == SAVING_FAILED)
	{
		printf("Actual Result: SAVING_FAILED\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}
	
	printf("Test Case 2:\n");	

	Stat = saveTransaction(&transData);

	printf("Input Data: Not saved \n");

	printf("Expected Result : SAVING_FAILED\n");

	if (Stat == SAVING_FAILED)
	{
		printf("Actual Result: SAVING_FAILED\n");
	}
	else
	{
		printf("Actual Result: SERVER_OK\n");
	}
	
}