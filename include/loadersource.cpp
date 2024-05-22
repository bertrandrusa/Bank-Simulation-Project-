//
// Created by Mason on 12/6/2023.
//
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "loader.h"
using namespace std;

void processFile(const std::string& filename, Node*& arrivals_head, Node*& arrivals_tail, Node*& transtime_head, Node*& transtime_tail) {
    std::ifstream infile;
    infile.open(filename);

    if (infile.is_open()) {
        int x;
        int count = 0;

        while (infile >> x) {
            Node* new_node = new Node(x);

            if (count % 2 == 0) {
                // Arrivals
                if (arrivals_head == nullptr) {
                    arrivals_head = new_node;
                    arrivals_tail = new_node;
                } else {
                    arrivals_tail->next = new_node;
                    arrivals_tail = new_node;
                }
            } else {
                // Transtime
                if (transtime_head == nullptr) {
                    transtime_head = new_node;
                    transtime_tail = new_node;
                } else {
                    transtime_tail->next = new_node;
                    transtime_tail = new_node;
                }
            }

            count++;
        }

        infile.close();
    } else {
        std::perror("ERROR! Unable to open file");
        // or use std::cout << "ERROR! Unable to open file: " << std::strerror(errno) << std::endl;
    }
}


void printNodes(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}