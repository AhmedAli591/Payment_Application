#ifndef TEST_H
#define TEST_H

#include "../CARD/card.h"
#include "../TERMINAL/terminal.h"
#include "../SERVER/server.h"

void getCardExpiryDateTest(void);
void getCardHolderNameTest(void);
void getCardPANTest(void); // end of card file

void getTransactionDateTest(void);
void isCardExpiredTest(void);
void getTransactionAmountTest(void);
void isBelowMaxAmountTest(void);
void setMaxAmountTest(void);
void isValidCardPANTest(void); //end of terminal file

void isValidAccountTest(void);
void isBlockedAccountTest(void);
void isAmountAvailableTest(void);
void listSavedTransactionsTest(void);
void recieveTransactionDataTest(void);
void saveTransactionTest(void);

#endif // !TEST_H
