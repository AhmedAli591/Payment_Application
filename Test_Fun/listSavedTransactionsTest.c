#include "Test.h"

void listSavedTransactionsTest(void)
{

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: listSavedTransactions\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");

	printf("Input Data: \n");

	printf("#########################\n");
	printf("Transaction Sequence Number:\t0\n");
	printf("Transaction Date:\t20/12/2020\n");
	printf("Transaction Amount:\t2000.0\n");
	printf("Transaction State:\tAPPROVED\n");
	printf("Terminal Max Amount:\t5000.0\n");
	printf("Cardholder Name:\tAhmed Ali Abd Al kaream\n");
	printf("PAN:\t\t\t8989374615436851\n");
	printf("Card Expiration Date:\t05/22\n");
	printf("#########################\n");

	printf("Expected Result :\n");

	printf("#########################\n");
	printf("Transaction Sequence Number:\t0\n");
	printf("Transaction Date:\t20/12/2020\n");
	printf("Transaction Amount:\t2000.0\n");
	printf("Transaction State:\tAPPROVED\n");
	printf("Terminal Max Amount:\t5000.0\n");
	printf("Cardholder Name:\tAhmed Ali Abd Al kaream\n");
	printf("PAN:\t\t\t8989374615436851\n");
	printf("Card Expiration Date:\t05/22\n");
	printf("#########################\n");

	printf("Actual Result: \n");
	listSavedTransactions();

}