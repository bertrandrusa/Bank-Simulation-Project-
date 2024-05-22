//
// Created by Mason on 12/6/2023.
//

#ifndef LAB_NODE_H
#define LAB_NODE_H
#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

#endif // NODE_H
#endif //LAB_NODE_H
