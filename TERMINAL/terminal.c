#include "terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)	// Transaction Date
{
	EN_terminalError_t Stat = TERMINAL_OK;		//For return

	if (termData->transactionDate == NULL) { Stat = WRONG_DATE; } //Check for NULL

	#if (TEST == 0)	//for test case
	printf("Please Enter the Transaction Date: \n");
	gets_s(termData->transactionDate, 11); //     dd/mm/yyyy
	#endif	//end if
	
	char len = strlen(termData->transactionDate); // get the lenth
	
	
	if (len < 10 || len > 10) { Stat = WRONG_DATE; }	//check the lenth
	else if (termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/' ) { Stat = WRONG_DATE; } //check format DD/MM/YYYY
	else if (termData->transactionDate[0] == '3' && termData->transactionDate[1] > '1') { Stat = WRONG_DATE; }	// check day less than 31
	else if (termData->transactionDate[0] > '3') { Stat = WRONG_DATE; }	//check day less than 39
	else if (termData->transactionDate[3] == '1' && termData->transactionDate[4] > '2') { Stat = WRONG_DATE; }	//check month less than 12
	else if (termData->transactionDate[3] > '1') { Stat = WRONG_DATE; } // check month less than 19

	return Stat;
}

/*********************************************************************************/

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) //compar date on card
{
	EN_terminalError_t Stat = TERMINAL_OK;	//for return
	int8_t Test_val[4] = { 0 };	//variable to stor result

	// MM/YY compare with DD/MM/YYYY
	Test_val[2] = cardData->cardExpirationDate[3] - termData->transactionDate[8];	//Y1 -> Y3
	Test_val[0] = cardData->cardExpirationDate[0] - termData->transactionDate[3];	//M1
	Test_val[1] = cardData->cardExpirationDate[1] - termData->transactionDate[4];	//M2
	Test_val[3] = cardData->cardExpirationDate[4] - termData->transactionDate[9];	//Y2 -> Y4
	
	if (Test_val[2] < 0) { Stat = EXPIRED_CARD; }	//save time
	else if (Test_val[3] < 0) { Stat = EXPIRED_CARD; }
	else if (Test_val[0] < 0 && Test_val[3] == 0) { Stat = EXPIRED_CARD; }
	else if (Test_val[1] < 0 && Test_val[0] == 0) { Stat = EXPIRED_CARD; } 
	
	return Stat;
}

/*********************************************************************************/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)	//Amount 
{
	EN_terminalError_t Stat = TERMINAL_OK;	//for return
	
	#if (TEST == 0)	//for test case
	printf("Please Enter the Transaction Amount: \n");
	scanf_s("%f", &termData->transAmount);
	#endif	//end if

	if (termData->transAmount <= 0) { Stat = INVALID_AMOUNT; }	//check for less of equal 0

	return Stat;
}

/*********************************************************************************/

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)	//if it lass than MAX
{
	EN_terminalError_t Stat = TERMINAL_OK;	//for return
	
	if (termData->maxTransAmount - termData->transAmount < 0) { Stat = EXCEED_MAX_AMOUNT; } //if it negative it below
	
	return Stat;
}

/*********************************************************************************/

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)	//give the MAX
{
	EN_terminalError_t Stat = TERMINAL_OK;	//for return
	
	termData->maxTransAmount = maxAmount;
	
	if (maxAmount <= 0) { Stat = INVALID_MAX_AMOUNT; }	//check for less of equal 0

	return Stat;
}

/*********************************************************************************/

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{
	EN_terminalError_t Stat = TERMINAL_OK;
	uint8_t sum = 0;
	uint8_t temp = 0;
	uint8_t	Luhn = 0;
	uint8_t loop_counter = 0;

	for (loop_counter = 0; loop_counter < 16; loop_counter++)
	{
		temp = cardData->primaryAccountNumber[loop_counter];
		ascii_t(&temp);

		if (loop_counter % 2 == 0)
		{
		temp = temp * 2;
		sum = sum + (temp / 10) + (temp % 10);
		}
		else
		{
			sum = sum + temp;
		}
	}
	Luhn = (10 - (sum % 10)) % 10;
	
	temp = cardData->primaryAccountNumber[16];
	ascii_t(&temp);

	if (Luhn != temp) { Stat = INVALID_CARD; }

	return Stat;
}
void ascii_t(uint8_t* temp)
{
	switch (*temp)
	{
	case 48:
		*temp = 0;
		break;
	case 49:
		*temp = 1;
		break;
	case 50:
		*temp = 2;
		break;
	case 51:
		*temp = 3;
		break;
	case 52:
		*temp = 4;
		break;
	case 53:
		*temp = 5;
		break;
	case 54:
		*temp = 6;
		break;
	case 55:
		*temp = 7;
		break;
	case 56:
		*temp = 8;
		break;
	case 57:
		*temp = 9;
		break;
	}
}
