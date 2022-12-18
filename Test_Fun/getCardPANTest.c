#include "Test.h"
void getCardPANTest(void)
{
	ST_cardData_t cardData;
	EN_cardError_t Stat = CARD_OK;
	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: getCardPAN\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	strcpy_s(cardData.primaryAccountNumber, 20, "254686231598745"); // 15 char

	Stat = getCardPAN(&cardData);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : WRONG_PAN\n");

	if (Stat == WRONG_PAN)
	{
		printf("Actual Result: WRONG_PAN\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}

	printf("Test Case 2:\n");
	strcpy_s(cardData.primaryAccountNumber, 25, "254896531547952345541"); // 21 char 

	Stat = getCardPAN(&cardData);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : WRONG_PAN\n");

	if (Stat == WRONG_PAN)
	{
		printf("Actual Result: WRONG_PAN\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}

	printf("Test Case 3:\n");
	strcpy_s(cardData.primaryAccountNumber, 20, "2541236548963215"); // 16 char

	Stat = getCardPAN(&cardData);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : CARD_OK\n");

	if (Stat == WRONG_PAN)
	{
		printf("Actual Result: WRONG_PAN\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}

	printf("Test Case 4:\n");
	strcpy_s(cardData.primaryAccountNumber, 20, "2541369852365412365"); // 19 char

	Stat = getCardPAN(&cardData);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : CARD_OK\n");

	if (Stat == WRONG_PAN)
	{
		printf("Actual Result: WRONG_PAN\n");
	}
	else
	{
		printf("Actual Result: CARD_OK\n");
	}
}