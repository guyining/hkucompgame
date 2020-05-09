#include <iostream>
#include "Deck.h"   // for the class of decks
#include "Card.h"   // for the class of a single card
#include <fstream>  // ofstream, fstream for game data saving
using namespace std;

// Save the game data to store.txt
// data including doors deck, labyrinth, hand deck, draw deck
void savegame(vector<Card> doors,vector<Card> laby,vector<Card> hand,Deck deck) {
    ofstream out;
    out.open("store.txt",ios::trunc);
    if (out.is_open()) {
        out <<doors.size()<<' '<<laby.size()<<' '<<hand.size()<< ' '<< deck.cardorder.size() << endl;
        for (int i = 0; i < doors.size(); i++) {
            out << doors[i].cardID << ' ';
        }
        out << endl;
        for (int i = 0; i < laby.size(); i++) {
            out << laby[i].cardID << ' ';
        }
        out << endl;
        for (int i = 0; i < hand.size(); i++) {
            out << hand[i].cardID << ' ';
        }
        out << endl;
        for (int i = 0; i < deck.cardorder.size(); i++) {
            out << deck.cardorder[i].cardID << ' ';
        }
        cout << "Game successfully saved" << endl;
        out.close();
    }
}
// Output to console if player loses and delete store.txt
void gg(){
    cout << "You lose :("<<endl;
    remove("store.txt");
    exit(0);
}

// Output to console if player wins and delete store.txt
void win(){
    cout << "You win :)"<<endl;
    remove("store.txt");
    exit(0);
}

// Check whether the card played/discarded is legal
bool islegal(vector<Card> laby,vector<Card> hand,int a){
    if (a>4||a<0) return false;
    if (laby.empty()) return true;
    if (laby.back().cardSignal!=hand[a].cardSignal){
        return true;
    }else return false;
}

// Single turn of the game process
void gameplay(Deck deck,vector<Card> hand,vector<Card> laby, vector<Card> doors){
    // Output to console of current decks
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



    // Player losses if the draw deck is empty.
    if (deck.cardorder.empty()) {gg();}
    else {
            // Player make choice to play/discard a card/abort the game
            cout << "Enter A to abort the current game. ";
            cout << "Enter P for play a card or enter D for discard a card: A/P/D"<<endl;
            char option;        //Player's choice
            cin >> option;
            int a;              //The number of card in hand deck to play or discard

            // If Player chooses not to abort the game, ask for the hand he wants to play or discard
            if (option!='A') {
               cout << "Enter the number of the card: 1-5" << endl;
               cin >> a;
               a = a - 1;
           }
            if(option=='A'){gg();}else {
                // When player chose to play a card
                if (option == 'P') {
                    // Check if the card is legal to play. If not, ask for it again.
                    while (!islegal(laby, hand, a)) {
                        cout << "The number is illegal." << endl;
                        cout << "Enter the number of the card: 1-5" << endl;
                        cin >> a;
                        a = a - 1;
                    }
                    // Put the card played to the labyrinth deck
                    laby.push_back(hand[a]);
                    // Check if the card played can open a door
                    if (laby.size() >= 3) {
                        if ((laby[laby.size() - 1].cardColor == laby[laby.size() - 2].cardColor) &&
                            (laby[laby.size() - 2].cardColor == laby[laby.size() - 3].cardColor) &&
                            (laby[laby.size() - 1].status == 1) && (laby[laby.size() - 2].status == 1) &&
                            (laby[laby.size() - 3].status == 1)) {
                            if (deck.drawadoor(laby[laby.size() - 1].cardColor).status != 10086) {
                                cout << "A Door is opened!" << endl;
                                doors.push_back(deck.drawadoor(laby[laby.size() - 1].cardColor));
                            }
                        }
                    }
                }
                // When a player chooses to discard a card in hand
                else{
                    // Check if the card is legal to discard. If not, ask for it again.
                    while (a > 4 || a < 0) {
                        cout << "The number is illegal." << endl;
                        cout << "Enter the number of the card: 1-5" << endl;
                        cin >> a;
                        a = a - 1;
                    }
                    // If the card is a key card, discard one Nightmare within the first five cards from draw deck if any
                    if (hand[a].cardSignal == 2) {
                        for (int i = 0; i < 5; i++) {
                            if (deck.cardorder[i].cardID <= 10) {
                                deck.cardorder.erase(deck.cardorder.begin() + i);
                            };
                        }
                    }
                }
            }

            // Automatically draw a card to replace the one played or discard
            Card getcard= deck.cardorder.front();
            // If it is a Nightmare, solve it now
            if ((getcard.cardID<=10) ){
                //kill Nightmare
                /*make a choice
                 * 1. discard a key in hand
                 * 2. discard a door card in door deck
                 * 3. discard all hand deck
                 * 4. draw 5 cards, put doors and nightmare to the limbo pile and discard the rest
                 */
                deck.cardorder.erase(deck.cardorder.begin());
                cout << "Nightmare occurs!" << endl;
                cout << "Input:"<< endl;
                cout << "1 for discarding a key in hand;" << endl;
                cout << "2 for discarding a door card in door deck; "<< endl;
                cout << "3 for discarding all hand deck;"<< endl;
                cout << "4 for drawing five from deck and discarding Suns, Moons, and Keys only." << endl;
                do {
                    // Read player input
                    int input;
                    cin >> input;
                    if(input == 1){
                        for(int i = 0; i<5;i++){
                            if(hand[i].cardSignal ==2) {
                                hand.erase(hand.begin() + i);
                                Card ans=deck.drawanormal();
                                if(ans.status!=10086) {
                                    hand[i] = ans;
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
                // Ask the player to input again if the choice is not available
                cout << "Please input correct number!" << endl;
                }while(true);
            }

            // If the card is a
            else if(getcard.cardSignal == 1){
                cout<<"You had draw a door,";
                // Check if there is a key in hand Deck
                int match=-1;
                for (int i = 0; i < 5; i++){
                    if(hand[i].cardColor==getcard.cardColor&&i!=a){
                        match = i;
                        break;
                    }
                }
                // If there is a key of same color, open the door and draw a normal card
                if (match != -1){
                    cout<<"and match a key in your hand,the Door is Open"<<endl;
                    doors.push_back(deck.drawadoor(getcard.cardColor));
                    hand[match]=deck.drawanormal();
                    hand[a]=deck.drawanormal();
                }
                // If there is no key of same color, put the door back, shuffle and draw a normal card
                else{
                    cout<<"and not match a key in your hand,you draw another card"<<endl;
                    hand[a]=deck.drawanormal();
                }

            }

            // If it is a Moon, Sun, or Key card, replace the played/discarded card
            else {
                hand[a] = getcard;
                deck.cardorder.erase(deck.cardorder.begin());
            }


        //deck.shuffle();
        // Check if the player has won the game
        if(doors.size()==8){
            win();
        }
        // Save the game automatically and have the gameplay function recursed
        savegame(doors,laby,hand,deck);
        gameplay(deck,hand,laby,doors);
    }

}


int main() {
    cout <<"Welcome to Onirim World!"<< endl;
    // create a deck of 78 cards
    Deck mydeck = Deck();
    // create a deck to store temporary card if any
    Deck tempdeck;
    tempdeck.cardorder.clear();
    // create laby for the labyrinth deck to store the cards which have been played
    vector<Card> laby;
    // create doors for door deck to store the doors which are open
    vector<Card> doors;
    // initiate the hand deck
    vector<Card> hand;

    // check if there exist a file of previous game data
    fstream in("store.txt",ios::in);
    // if there is a unsettled game, continue the game automatically
    if (in){
        int a,b,c,d;
        // initiate a, b, c, d for the sizes of doors, labyrinth, hand, and draw decks
        in>>a>>b>>c>>d;
        for (int i=0;i<a;i++){
            int num;
            in>>num;
            doors.push_back(mydeck.cardorder[num-1]);
        }
        for (int i=0;i<b;i++){
            int num;
            in>>num;
            laby.push_back(mydeck.cardorder[num-1]);
        }
        for (int i=0;i<c;i++){
            int num;
            in>>num;
            hand.push_back(mydeck.cardorder[num-1]);
        }
        for (int i=0;i<d;i++){
            int num;
            in>>num;
            tempdeck.cardorder.push_back(mydeck.cardorder[num-1]);
        }
    mydeck=tempdeck;
    }
    // If there is no existing game
    else {
        // shuffle the deck as the draw deck
        mydeck.shuffle();
        for (int i = 1; i <= 5; i++) {
            int tag = 1;
            // skip the card from mydeck if it is nightmare or doors
            while (!((mydeck.cardorder[tag].cardID >= 11) && (mydeck.cardorder[tag].cardSignal != 1))) {
                tag++;
            }
            // draw the card to hand if it is a Moon, Sun or a key and delete this card from mydeck
            hand.push_back(mydeck.cardorder[tag]);
            mydeck.cardorder.erase(mydeck.cardorder.begin() + tag);
        }
        // after the player has a hand of five cards, shuffle mydeck again to avoid cluster of nightmares and doors in the front
        mydeck.shuffle();
    }
    // start playing once the decks are ready
    gameplay(mydeck,hand,laby,doors);
    return 0;
}
