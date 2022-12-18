#include "Test.h"

void recieveTransactionDataTest(void)
{
	ST_transaction_t transData;
	EN_transState_t Stat = APPROVED;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: recieveTransactionData\n");
	printf("/*******************************************************/\n");
	
	printf("Test Case 1:\n");

	strcpy_s(transData.cardHolderData.primaryAccountNumber, 20, "8989374615436852"); // not exist

	printf("Input Data: %s \n", transData.cardHolderData.primaryAccountNumber);

	printf("Expected Result : FRAUD_CARD\n");
	
	Stat = recieveTransactionData(&transData);
	
	if (Stat == FRAUD_CARD)
	{
		printf("Actual Result: FRAUD_CARD\n");
	}
	else
	{
		printf("Actual Result: APPROVED\n");
	}


	printf("Test Case 2:\n");

	strcpy_s(transData.cardHolderData.primaryAccountNumber, 20, "9504256636344210"); //exist
	transData.terminalData.transAmount = 50000.0; // high balance

	printf("Input Data: %.2f \n", transData.terminalData.transAmount);

	printf("Expected Result : DECLINED_INSUFFECIENT_FUND\n");

	Stat = recieveTransactionData(&transData);

	if (Stat == DECLINED_INSUFFECIENT_FUND)
	{
		printf("Actual Result: DECLINED_INSUFFECIENT_FUND\n");
	}
	else
	{
		printf("Actual Result: APPROVED\n");
	}

	printf("Test Case 3:\n");

	strcpy_s(transData.cardHolderData.primaryAccountNumber, 20, "5807007076043875"); //exist
	transData.terminalData.transAmount = 50;; // low balance, But BLOCK

	printf("Input Data: DECLINED_STOLEN_CARD \n");

	printf("Expected Result : DECLINED_STOLEN_CARD\n");

	Stat = recieveTransactionData(&transData);
	if (Stat == DECLINED_STOLEN_CARD)
	{
		printf("Actual Result: DECLINED_STOLEN_CARD\n");
	}
	else
	{
		printf("Actual Result: APPROVED\n");
	}

	printf("Test Case 4:\n");

	strcpy_s(transData.cardHolderData.primaryAccountNumber, 20, "1733468095153756"); //exist
	transData.terminalData.transAmount = 100; // low balance

	printf("Input Data: OK \n");

	printf("Expected Result : APPROVED\n");

	Stat = recieveTransactionData(&transData);

	if (Stat == APPROVED)
	{
		printf("Actual Result: APPROVED\n");
	}
	else
	{
		printf("Actual Result: ERROR\n");
	}

}