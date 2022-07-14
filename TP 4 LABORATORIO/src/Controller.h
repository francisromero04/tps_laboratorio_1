#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

int controller_loadFromText(char* path, LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger);
int controller_getUltimoId();

#endif /* SRC_CONTROLLER_H_ */
