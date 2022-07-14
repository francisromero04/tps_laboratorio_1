#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger);

#endif /* SRC_PARSER_H_ */
