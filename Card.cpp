#include "Card.h" // for the class of a single card
//This is a function to initiate new cards
Card::Card(int a,int b,int c ,int d) {
    this->cardID=a;         // Number the card by 1-76 in which 1-10=Nightmare
    this->cardColor=b;      // 1=red 2=blue 3=green 4=yellow 5=Nightmare
    this->cardSignal=c;     // 1= door 2=key 3=moon 4=sun 5=Nightmare
    this->status=d;         // 0 means that the card has been played and opened a door. Otherwise, the status is 1
}