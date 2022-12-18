 #include "Test.h"
void getCardExpiryDateTest(void)
{
	ST_cardData_t cardData;
	EN_cardError_t Stat = CARD_OK;
	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	strcpy_s(cardData.cardExpirationDate, 6, "12.22"); // No '/'

	Stat = getCardExpiryDate(&cardData);
	printf("Input Data: %s \n", cardData.cardExpirationDate);

	printf("Expected Result : WRONG_EXP_DATE\n");

	if (Stat == WRONG_EXP_DATE)
	{
		printf("Actual Result: WRONG_EXP_DATE\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}

	printf("Test Case 2:\n");
	strcpy_s(cardData.cardExpirationDate, 6, "1222"); // 4 char 

	Stat = getCardExpiryDate(&cardData);
	printf("Input Data: %s \n", cardData.cardExpirationDate);

	printf("Expected Result : WRONG_EXP_DATE\n");

	if (Stat == WRONG_EXP_DATE)
	{
		printf("Actual Result: WRONG_EXP_DATE\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}

	printf("Test Case 3:\n");
	strcpy_s(cardData.cardExpirationDate, 6, "13/22"); // Month > 12

	Stat = getCardExpiryDate(&cardData);
	printf("Input Data: %s \n", cardData.cardExpirationDate);

	printf("Expected Result : WRONG_EXP_DATE\n");

	if (Stat == WRONG_EXP_DATE)
	{
		printf("Actual Result: WRONG_EXP_DATE\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}

	printf("Test Case 4:\n");
	strcpy_s(cardData.cardExpirationDate, 6, "12/22"); // Month = 12

	Stat = getCardExpiryDate(&cardData);
	printf("Input Data: %s \n", cardData.cardExpirationDate);

	printf("Expected Result : CARD_OK\n");

	if (Stat == WRONG_EXP_DATE)
	{
		printf("Actual Result: WRONG_EXP_DATE\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}

	printf("Test Case 5:\n");
	strcpy_s(cardData.cardExpirationDate, 6, "10/22"); //Month < 12

	Stat = getCardExpiryDate(&cardData);
	printf("Input Data: %s \n", cardData.cardExpirationDate);

	printf("Expected Result : CARD_OK\n");

	if (Stat == WRONG_EXP_DATE)
	{
		printf("Actual Result: WRONG_EXP_DATE\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}
}