#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;
// Deck
void gg(){
    cout << "You lose:("<<endl;
    exit(0);
}

bool islegal(vector<Card> laby,vector<Card> hand,int a){
    if (a>4||a<0) return false;
    if (laby.empty()) return true;
    if (laby.back().cardSignal!=hand[a].cardSignal){
        return true;
    }else return false;
}
void gameplay(Deck deck,vector<Card> hand,vector<Card> laby, vector<Card> doors){
    vector<Card> limbo;
    cout << "Your door deck: " ;
    int doorSize = doors.size();
    for(int i = 0; i < doorSize;i++){
        switch (doors[i].cardColor) {
            case 1:
                cout << "Red-";
                break;
            case 2:
                cout << "Blue-";
                break;
            case 3:
                cout << "Green-";
                break;
            case 4:
                cout << "Yellow-";
                break;
        }
        cout << "door | ";
    }
    cout << endl;
    cout << "Labyrinth deck: ";
    int labySize = laby.size();
    if(labySize<5) {
        for (int i = 0; i < labySize; i++) {
            switch (laby[i].cardColor) {
                case 1:
                    cout << "Red-";
                    break;
                case 2:
                    cout << "Blue-";
                    break;
                case 3:
                    cout << "Green-";
                    break;
                case 4:
                    cout << "Yellow-";
                    break;
            }
            switch (laby[i].cardSignal) {
                case 1:
                    cout << "Door";
                    break;
                case 2:
                    cout << "Key";
                    break;
                case 3:
                    cout << "Moon";
                    break;
                case 4:
                    cout << "Sun";
                    break;
            }
            cout << " | ";
        }
    }
        else{
            for (int i = labySize - 5; i < labySize; i++) {
                switch (laby[i].cardColor) {
                    case 1:
                        cout << "Red-";
                        break;
                    case 2:
                        cout << "Blue-";
                        break;
                    case 3:
                        cout << "Green-";
                        break;
                    case 4:
                        cout << "Yellow-";
                        break;
                }
                switch (laby[i].cardSignal) {
                    case 1:
                        cout << "Door";
                        break;
                    case 2:
                        cout << "Key";
                        break;
                    case 3:
                        cout << "Moon";
                        break;
                    case 4:
                        cout << "Sun";
                        break;
                }
                cout << " | ";
            }
        }
        cout << endl;
    cout << "Your hand deck: ";
    for (int i = 0; i<5;i++){
        switch(hand[i].cardColor){
            case 1:
                cout << "Red-";
                break;
            case 2:
                cout << "Blue-";
                break;
            case 3:
                cout << "Green-";
                break;
            case 4:
                cout << "Yellow-";
                break;
        }
        switch(hand[i].cardSignal){
            case 1:
                cout << "Door";
                break;
            case 2:
                cout << "Key";
                break;
            case 3:
                cout << "Moon";
                break;
            case 4:
                cout << "Sun";
                break;
        }
        cout << " | ";
    }
    cout << endl;




    if (deck.cardorder.empty()) {gg();}
    else {
            cout << "Enter P for play a card or enter D for discard a card: P/D"<<endl;
            char option;
            cin >> option;
            cout<<"Enter the number of the card: 1-5"<< endl;
            int a;
            cin>> a;//判断a是否合法
            a= a-1;
            if(option=='P') {
                while (!islegal(laby, hand, a)) {
                    cout << "The number is illegal."<< endl;
                    cout << "Enter the number of the card: 1-5" << endl;
                    cin >> a;
                    a = a-1;
                }
                laby.push_back(hand[a]);
                //1先判断开门
                if (laby.size() >= 3) {
                    if ((laby[laby.size()-1].cardColor == laby[laby.size() - 2].cardColor) &&
                        (laby[laby.size() - 2].cardColor == laby[laby.size() - 3].cardColor) &&
                        (laby[laby.size()-1].status  == 1) && (laby[laby.size() - 2].status == 1) &&
                        (laby[laby.size() - 3].status == 1)) {
                        cout << laby[laby.size()-1].cardColor<<endl;
                        if (deck.drawadoor(laby[laby.size()-1].cardColor).status != 10086) {
                            cout << "A Door is opened!"<< endl;
                            doors.push_back(deck.drawadoor(laby[laby.size()-1].cardColor));
                        }
                        //门状态改
                    }
                }
            }
            else{
                while (a>4||a<0) {
                    cout << "The number is illegal."<< endl;
                    cout << "Enter the number of the card: 1-5"<< endl;
                    cin >> a;
                    a = a-1;
                }
                if(hand[a].cardSignal==2){
                    for(int i =0; i<5;i++){
                        if (deck.cardorder[i].cardID <=10){
                            deck.cardorder.erase(deck.cardorder.begin()+i);
                        };
                    }
                }
            }
            //

            Card getcard= deck.cardorder.front();
            if ((getcard.cardID<=10) ){
                //kill Nightmare
                /*make a choice!
                 * 1. a key
                 * 2. door card in door deck
                 * 3. discard all hand deck
                 * 4. draw 5 cards, put doors and nightmare to the limbo pile and discard the rest
                 */
                cout << "Nightmare occurs!" << endl;
                cout << "Input:"<< endl;
                cout << "1 for discarding a key in hand;" << endl;
                cout << "2 for discarding a door card in door deck; "<< endl;
                cout << "3 for discarding all hand deck;"<< endl;
                cout << "4 for drawing five from deck and discarding Suns, Moons, and Keys only." << endl;
                do {
                    int input;
                    cin >> input;
                    if(input == 1){
                        for(int i = 0; i<5;i++){
                            if(hand[i].cardSignal ==2) {
                                hand.erase(hand.begin() + i);
                                Card ans=deck.drawanormal();
                                if(ans.status!=10086){
                                    hand[i]= ans;
                                    break;
                                }
                                else {gg();}

                            }
                        }
                    }
                    if(input == 2){
                        if(!doors.empty()) {
                            deck.cardorder.push_back(doors[0]);
                            doors.erase(doors.begin());
                            deck.shuffle();
                            break;
                        }
                    }
                    if(input == 3){
                        hand.clear();
                        for(int i = 0; i < 5; i++){
                            hand.push_back(deck.drawanormal());
                        }
                        break;
                    }
                    if(input == 4){
                        int size = deck.cardorder.size();
                        if(size > 5){
                            for(int i = 0; i < 5; i++){
                                if(((deck.cardorder[0].cardID>=11)&&(deck.cardorder[0].cardSignal!=1))){
                                    deck.cardorder.erase(deck.cardorder.begin());
                                }
                                else {
                                    deck.cardorder.push_back(deck.cardorder[0]);
                                    deck.cardorder.erase(deck.cardorder.begin());
                                }
                            }
                            break;
                        }
                    }
                cout << "Please input correct number!" << endl;
                }while(true);
            }
            else if(getcard.cardSignal == 1){
                //check key
                int match=0;
                for (int i = 1; i <= 5; i++){
                    if(hand[i].cardColor==getcard.cardColor&&i!=a){
                        match = i;
                        break;
                    }
                }
                if (match != 0){
                    hand[match]=deck.drawanormal();
                    hand[a]=deck.drawanormal();
                }else{
                    hand[a]=deck.drawanormal();
                }
            }
            else
                hand[a] = getcard;

            deck.cardorder.erase(deck.cardorder.begin());

        deck.shuffle();


        gameplay(deck,hand,laby,doors);
    }

}


int main() {
    cout <<"Welcome to Onirim Wordld!"<< endl;
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
