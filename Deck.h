#ifndef ONIRIMPROJECT_DECK_H
#define ONIRIMPROJECT_DECK_H
#include <vector>
#include"Card.h" // for the class of a single card
using namespace std;
class Deck {
public:
    vector<Card> cardorder;     // initiate a Card vector to store the draw deck
    void shuffle();             // shuffle the draw deck
    Deck();                     // initiate the constructor
    Card drawadoor(int);        // draw a door of certain color
    Card drawanormal();         // draw a card which is not a Nightmare or a Door
};


#endif //ONIRIMPROJECT_DECK_H
