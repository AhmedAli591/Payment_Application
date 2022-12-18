#include "Test.h"
void isCardExpiredTest(void)
{
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	EN_terminalError_t Stat = TERMINAL_OK;

	strcpy_s(cardData.cardExpirationDate,6, "12/20");
	printf("/*******************************************************/\n");
	printf("Tester Name: Ahmed Ali\n");
	printf("Function Name: isCardExpired\n");
	printf("/*******************************************************/\n");

	printf("Test Case 1:\n");
	strcpy_s(termData.transactionDate, 11, "11/09/2022");

	Stat = isCardExpired(&cardData, &termData);
	printf("Input Data: %s \n", termData.transactionDate);

	printf("Expected Result : EXPIRED_CARD\n");

	if (Stat == EXPIRED_CARD)
	{
		printf("Actual Result: EXPIRED_CARD\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

	printf("Test Case 2:\n");
	strcpy_s(termData.transactionDate, 11, "11/09/2020");

	Stat = isCardExpired(&cardData, &termData);
	printf("Input Data: %s \n", termData.transactionDate);

	printf("Expected Result : TERMINAL_OK\n");

	if (Stat == EXPIRED_CARD)
	{
		printf("Actual Result: EXPIRED_CARD\n");
	}
	else
	{
		printf("Actual Result: TERMINAL_OK\n");
	}

}