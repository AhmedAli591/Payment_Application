#include "Test.h"
void getCardHolderNameTest(void)
{
	ST_cardData_t cardData;
	EN_cardError_t Stat = CARD_OK;
	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: getCardHolderName\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	strcpy_s (cardData.cardHolderName, 24, "Ahmed Ali"); // 9 char
	
	Stat = getCardHolderName(&cardData);
	printf("Input Data: %s \n", cardData.cardHolderName);
	
	printf("Expected Result : WRONG_NAME\n");

	if (Stat == WRONG_NAME)
	{
		printf("Actual Result: WRONG_NAME\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}	
	
	printf("Test Case 2:\n");
	strcpy_s (cardData.cardHolderName, 30, "Ahmed Ali Abd Al-Kaream Ali"); // 26 char 
	
	Stat = getCardHolderName(&cardData);
	printf("Input Data: %s \n", cardData.cardHolderName);
	
	printf("Expected Result : WRONG_NAME\n");

	if (Stat == WRONG_NAME)
	{
		printf("Actual Result: WRONG_NAME\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}	
	
	printf("Test Case 3:\n");
	strcpy_s (cardData.cardHolderName, 24, "Ahmed Ali Abd Al-Kaream"); // 23 char - OK
	
	Stat = getCardHolderName(&cardData);
	printf("Input Data: %s \n", cardData.cardHolderName);
	
	printf("Expected Result : CARD_OK\n");

	if (Stat == WRONG_NAME)
	{
		printf("Actual Result: WRONG_NAME\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}	
}