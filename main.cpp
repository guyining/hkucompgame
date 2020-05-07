#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;
// Deck
void gameplay(Deck deck,vector<Card> hand,vector<Card> laby, vector<Card> doors){
    vector<Card> limbo;
    if (deck.cardorder.empty()) {gg};
    else {
            cout<<"enter a num to play a card:";
            int a;
            cin>> a;//判断a是否合法
            laby.push_back(hand[a]);
            //1先判断开门
            if (laby.isOpen()){
                deck.drawadoor();
                //门状态改
            }
            Card getcard= deck.cardorder.front();
            if ((getcard.cardID<=10) ){
                //kill Nightmare
            }
            else if(getcard.cardSignal == 1){
                //check key
                int match=0;
                for (int i = 1; i <= 5; i++){
                    if(hand[i].cardColor==getcard.cardColor){
                        match = i;
                        break;
                    }
                }
                if (match != 0){
                    //
                }
                limbo.push_back(getcard);
            }
            else
                hand[a] = getcard;

            deck.cardorder.erase(deck.cardorder.begin());
        while (!limbo.empty()){
            deck.cardorder.push_back(limbo.back);
            limbo.pop_back();
        }
        deck.shuffle();
        gameplay(deck,hand,laby,doors);
    }

}


int main() {
    // create a deck of 78 cards
    Deck mydeck = Deck();
    // shuffle the deck as the draw deck
    mydeck.shuffle();
    //initiate the hand deck
    vector<Card> hand;
    for (int i=1;i<=5;i++){
        int tag=1;
        // skip the from mydeck if it is nightmare or doors
        while(!((mydeck.cardorder[tag].cardID>=11)&&(mydeck.cardorder[tag].cardSignal!=1))){
            tag++;
        }
        // draw the card to hand if it is legal and delete this card from mydeck
        hand.push_back(mydeck.cardorder[tag]);
        mydeck.cardorder.erase(mydeck.cardorder.begin()+tag);
    }
    // after the player has a hand of five cards, shuffle mydeck again
    mydeck.shuffle();

    // create laby for the labyrinth deck to store the cards which have been played
    vector<Card> laby;
    // create doors for door deck to store the doors which are open
    vector<Card> doors;
    gameplay(mydeck,hand,laby,doors);
    //cout<<mydeck.cardorder[1].cardID;
    return 0;
}
