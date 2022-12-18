#include "Test.h"

void isValidCardPANTest(void)
{
	ST_cardData_t cardData;
	EN_terminalError_t Stat = TERMINAL_OK;

	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: isValidCardPAN\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	strcpy_s(cardData.primaryAccountNumber, 20, "6899742277896526"); //right

	Stat = isValidCardPAN(&cardData);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : TERMINAL_OK\n");

	if (Stat == INVALID_CARD)
	{
		printf("Actual Result: INVALID_CARD\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}
	
	printf("Test Case 2:\n");
	strcpy_s(cardData.primaryAccountNumber, 20, "6899742277896528"); //wrong

	Stat = isValidCardPAN(&cardData);
	printf("Input Data: %s \n", cardData.primaryAccountNumber);

	printf("Expected Result : INVALID_CARD\n");

	if (Stat == INVALID_CARD)
	{
		printf("Actual Result: INVALID_CARD\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}
}