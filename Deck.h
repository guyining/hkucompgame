//
// Created by King's Virus Maker on 2020/5/7.
//

#ifndef ONIRIMPROJECT_DECK_H
#define ONIRIMPROJECT_DECK_H
#include <vector>
#include"Card.h"
using namespace std;
class Deck {
public:
    vector<Card> cardorder;     // initiate a Card vector to store the draw deck
    void shuffle();             // shuffle the draw deck
    Deck();                     // initiate the constructor

};


#endif //ONIRIMPROJECT_DECK_H
