// ... (include statements)


#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include "node.h"
#include "loadersource.cpp"
void printNodes(Node* head);
void processFile(const std::string& filename, Node*& arrivals_head, Node*& arrivals_tail, Node*& transtime_head, Node*& transtime_tail);

#endif // FILE_PROCESSOR_H




