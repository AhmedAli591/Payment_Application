#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)	// Get the name on the card
{
	EN_cardError_t Stat = CARD_OK;		// For return 
	
	if (cardData->cardHolderName == NULL) // Check for NULL
	{
		Stat = WRONG_NAME;
	}

	#if (TEST == 0)			// For test case
	printf("Please Enter the Card Holder Name\n");
	gets_s(cardData->cardHolderName, 25);
	#endif		// end if

	char len = strlen(cardData->cardHolderName);		// Get the lenth of the char

	if ((len > 24) || (len < 20)) // Check the lenth
	{
		Stat = WRONG_NAME;
	}
	
	return Stat;
}

/*********************************************************************************/

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)	// Get the date on the card
{
	EN_cardError_t Stat = CARD_OK;		// For the return

	if (cardData->cardExpirationDate == NULL) { Stat = WRONG_EXP_DATE; }	// Check for NULL

	#if (TEST == 0)		// For test case
	printf("Please Enter the Card Expiry Date\n");
	gets_s(cardData->cardExpirationDate, 6);
	#endif	// end if

	char len = strlen(cardData->cardExpirationDate); // Get the lenth

	if (cardData->cardExpirationDate[2] != '/') { Stat = WRONG_EXP_DATE; }	//check for the format MM/YY
	else if (cardData->cardExpirationDate[0] > '1') { Stat = WRONG_EXP_DATE; }	//check for the month < 19
	else if (cardData->cardExpirationDate[0] == '1' && cardData->cardExpirationDate[1] > '2') { Stat = WRONG_EXP_DATE; } //check for month < 12
	else if ((len < 5) || (len > 5)) { Stat = WRONG_EXP_DATE; } //check for the lenth

	return Stat;
}

/*********************************************************************************/

EN_cardError_t getCardPAN(ST_cardData_t* cardData) // get card PAN
{
	EN_cardError_t Stat = CARD_OK;		// for return
	
	if (cardData->primaryAccountNumber == NULL) //check for NULL
	{
		Stat = WRONG_PAN;
	}

	#if (TEST == 0)	//for test case
	printf("Please Enter the Card PAN\n");
	gets_s(cardData->primaryAccountNumber, 20);
	#endif		//end if

	char len = strlen(cardData->primaryAccountNumber);		//get the lenth

	if ((len > 19) || (len < 16)) //check the lenth
	{
		Stat = WRONG_PAN ;
	}
	
	return Stat;
}

