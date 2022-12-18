#include "server.h"

ST_accountsDB_t accountsDB_t[255] = {
	{2000.0, RUNNING, "8989374615436851"},
	{10000.0, BLOCKED, "5807007076043875"},
	{10000.0, RUNNING, "3945059474784178"},
	{2000.0, BLOCKED, "8348458056678398"},
	{55000.0, RUNNING, "7050586982223994"},
	{3500.0, BLOCKED, "1215045679186548"},
	{10000.0, RUNNING, "1733468095153756"},
	{253.250, BLOCKED, "9949524039026053"},
	{00000.0, RUNNING, "9504256636344210"},
	{2546.05, BLOCKED, "7238552633836548"}
};

ST_transaction_t transactionDB_t[255] = { 0 };
uint8_t transaction_counter = 0;

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_transState_t Stat = APPROVED;
	EN_serverError_t S_return = SERVER_OK;
	ST_accountsDB_t accountRefrence ;

	S_return = isValidAccount(&transData->cardHolderData, &accountRefrence);
	if (S_return == ACCOUNT_NOT_FOUND) 
	{
		Stat = FRAUD_CARD;
		goto END;
	}
	
	S_return = isAmountAvailable(&transData->terminalData, &accountRefrence);
	if (S_return == LOW_BALANCE) 
	{
		Stat = DECLINED_INSUFFECIENT_FUND;
		goto END;
	}
	
	S_return = isBlockedAccount(&accountRefrence);
	if (S_return == BLOCKED_ACCOUNT)
	{
		Stat = DECLINED_STOLEN_CARD;
		goto END;
	}
	
END:

	transData->transState = Stat;
	
	S_return = saveTransaction(transData);

	if (S_return == SAVING_FAILED)
	{
		Stat = INTERNAL_SERVER_ERROR;
	}
		
	if (Stat == APPROVED)
	{
		accountRefrence.balance = accountRefrence.balance - transData->terminalData.transAmount;
	}

	return Stat;
}

/***********************************************************************************/

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t Stat = SERVER_OK;
	uint8_t account_counter = 0;

	*accountRefrence = accountsDB_t[0];

	while (strcmp (cardData->primaryAccountNumber, accountRefrence->primaryAccountNumber) != 0 && account_counter != 255)
	{
		account_counter++;
		*accountRefrence = accountsDB_t[account_counter];
	}
	if (account_counter == 255)
	{
		Stat = ACCOUNT_NOT_FOUND;
		accountRefrence = NULL;
	}
	
	return Stat;
	
}

/***********************************************************************************/

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t Stat = SERVER_OK;
	
	if (accountRefrence->state == BLOCKED)
	{
		Stat = BLOCKED_ACCOUNT;
	}
	return Stat;
}

/***********************************************************************************/

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t Stat = SERVER_OK;

	if (accountRefrence->balance - termData->transAmount < 0)
	{
		Stat = LOW_BALANCE;
	}
	
	return Stat;
}

/***********************************************************************************/

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	EN_serverError_t Stat = SERVER_OK;

	if (transaction_counter == 255) 
	{
		Stat = SAVING_FAILED; 
		
		#if (TEST == 0)
		printf("#########################\n");
		printf("SAVING FAILD\n");
		printf("#########################\n");
		#endif
	}
	else
	{
		transactionDB_t[transaction_counter].cardHolderData = transData->cardHolderData;
		transactionDB_t[transaction_counter].terminalData = transData->terminalData;
		transactionDB_t[transaction_counter].transactionSequenceNumber = transaction_counter;
		transactionDB_t[transaction_counter].transState = transData->transState;
		
		#if (TEST != 1)
		listSavedTransactions();
		#endif
		
		transaction_counter++;
		
		#if (TEST == 1)
		transaction_counter = 255;
		#endif
	}
	return Stat;
}

/***********************************************************************************/

void listSavedTransactions(void)
{
	#if (TEST == 1)
	transactionDB_t[transaction_counter].transactionSequenceNumber = transaction_counter;
	strcpy_s (transactionDB_t[transaction_counter].terminalData.transactionDate,11,"20/12/2020");
	transactionDB_t[transaction_counter].terminalData.transAmount = 2000.0;
	transactionDB_t[transaction_counter].transState = APPROVED;
	transactionDB_t[transaction_counter].terminalData.maxTransAmount = 5000.0;
	strcpy_s(transactionDB_t[transaction_counter].cardHolderData.cardHolderName, 25, "Ahmed Ali Abd Al kaream");
	strcpy_s(transactionDB_t[transaction_counter].cardHolderData.primaryAccountNumber, 20, "8989374615436851");
	strcpy_s(transactionDB_t[transaction_counter].cardHolderData.cardExpirationDate, 6, "05/22");
	#endif
	
	#if (TEST == 2)
	transactionDB_t[transaction_counter].transactionSequenceNumber = transaction_counter;
	strcpy_s(transactionDB_t[transaction_counter].terminalData.transactionDate, 11, "20/12/2020");
	transactionDB_t[transaction_counter].terminalData.transAmount = 2000.0;
	transactionDB_t[transaction_counter].terminalData.maxTransAmount = 5000.0;
	strcpy_s(transactionDB_t[transaction_counter].cardHolderData.cardHolderName, 25, "Ahmed Ali Abd Al kaream");
	strcpy_s(transactionDB_t[transaction_counter].cardHolderData.primaryAccountNumber, 20, "8989374615436851");
	strcpy_s(transactionDB_t[transaction_counter].cardHolderData.cardExpirationDate, 6, "05/22");
	#endif

	printf("#########################\n");
	printf("Transaction Sequence Number:\t%d\n", transactionDB_t[transaction_counter].transactionSequenceNumber);
	printf("Transaction Date:\t%s\n", transactionDB_t[transaction_counter].terminalData.transactionDate);
	printf("Transaction Amount:\t%.2f\n", transactionDB_t[transaction_counter].terminalData.transAmount);
	enum_convert_State();
	printf("Terminal Max Amount:\t%.2f\n", transactionDB_t[transaction_counter].terminalData.maxTransAmount);
	printf("Cardholder Name:\t%s\n", transactionDB_t[transaction_counter].cardHolderData.cardHolderName);
	printf("PAN:\t\t\t%s\n", transactionDB_t[transaction_counter].cardHolderData.primaryAccountNumber);
	printf("Card Expiration Date:\t%s\n", transactionDB_t[transaction_counter].cardHolderData.cardExpirationDate);
	printf("#########################\n");
}

void enum_convert_State(void)
{
	EN_transState_t Stat = transactionDB_t[transaction_counter].transState;
	switch (Stat)
	{
	case 0 :
		printf("Transaction State:\tAPPROVED\n");
		break;
	case 1 :
		printf("Transaction State:\tDECLINED_INSUFFECIENT_FUND\n");
		break;
	case 2 :
		printf("Transaction State:\tDECLINED_STOLEN_CARD\n");
		break;
	case 3:
		printf("Transaction State:\tFRAUD_CARD\n");
		break;
	case 4 :
		printf("Transaction State:\tINTERNAL_SERVER_ERROR\n");
		break;
	}
}