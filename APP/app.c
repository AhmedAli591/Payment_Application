#include "app.h"

void appStart(void)
{
	ST_transaction_t* Server = malloc(sizeof(ST_transaction_t));
	EN_serverError_t Stat_Server = APPROVED;
	
	ST_cardData_t* Card = &Server->cardHolderData;
	EN_cardError_t Stat_Card = CARD_OK;
	
	ST_terminalData_t* Terminal = &Server->terminalData;
	EN_terminalError_t Stat_Terminal = TERMINAL_OK;

	setMaxAmount(Terminal,50000);

	Stat_Card = getCardHolderName(Card);
	while (Stat_Card != CARD_OK)
	{
		printf("WRONG Name!, Please try again!\n");
		Stat_Card = getCardHolderName(Card);
	}

	Stat_Card = getCardExpiryDate(Card);
	while (Stat_Card != CARD_OK)
	{
		printf("WRONG Date!, Please try again! (MM/YY)\n");
		Stat_Card = getCardExpiryDate(Card);
	}

	Stat_Card = getCardPAN(Card);
	while (Stat_Card != CARD_OK)
	{
		printf("WRONG PAN!, Please try again!\n");
		Stat_Card = getCardPAN(Card);
	}

	/****************** END OF CARD DATA ******************/
	
	Stat_Terminal = isValidCardPAN(Card);
	if (Stat_Terminal != TERMINAL_OK)
	{
		printf("#########################\n");
		printf("NOT VALID CARD!\n");
		printf("#########################\n");

		goto END;
	}
	
	Stat_Terminal = getTransactionDate(Terminal);
	while (Stat_Terminal != TERMINAL_OK)
	{
		printf("WRONG Transaction DATE!, Please try again!(DD/MM/YYYY)\n");
		Stat_Terminal = getTransactionDate(Terminal);
	}

	Stat_Terminal = isCardExpired(Card, Terminal);
	if (Stat_Terminal != TERMINAL_OK)
	{
		printf("#########################\n");
		printf("EXPIRED CARD!\n");
		printf("#########################\n");

		goto END;
	}

	Stat_Terminal = getTransactionAmount(Terminal);
	while (Stat_Terminal != TERMINAL_OK)
	{
		printf("WRONG Transaction Amount!, Please try again!\n");
		Stat_Terminal = getTransactionAmount(Terminal);
	}

	Stat_Terminal = isBelowMaxAmount(Terminal);
	if (Stat_Terminal != TERMINAL_OK)
	{
		printf("#########################\n");
		printf("AMOUNT EXCEEDING LIMIT!\n");
		printf("#########################\n");

		goto END;
	}
	
	/****************** END OF TERMINAL DATA ******************/

	Stat_Server = recieveTransactionData(Server);

END:
	free(Server);
}
