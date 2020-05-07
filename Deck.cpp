//
// Created by King's Virus Maker on 2020/5/7.
//
#include <algorithm> // ::shuffle()
#include <vector>
#include "Deck.h"
#include "Card.h"
#include <random>   // default_random_engine();
#include <chrono>   // chrono::system_clock::now ().time_since_epoch ().count ()
using namespace std;
Deck::Deck(){

    for (int i=1;i<=10;i++){                        // initiate the nightmares
        this->cardorder.push_back(Card(i,5,5,5));
    }
    for (int i=11;i<=12;i++){                       // initiate red door cards
        this->cardorder.push_back(Card(i,1,1,1));
    }
    for (int i=13;i<=15;i++){                       // initiate red key cards
        this->cardorder.push_back(Card(i,1,2,1));
    }
    for (int i=16;i<=19;i++){                       // initiate red Sun cards
        this->cardorder.push_back(Card(i,1,3,1));
    }
    for (int i=20;i<=28;i++){                       // initiate red Moon cards
        this->cardorder.push_back(Card(i,1,4,1));
    }
    for (int i=29;i<=30;i++){                       // initiate blue door cards
        this->cardorder.push_back(Card(i,2,1,1));
    }
    for (int i=31;i<=33;i++){                       // initiate blue key cards
        this->cardorder.push_back(Card(i,2,2,1));
    }
    for (int i=34;i<=37;i++){                       // initiate blue Sun cards
        this->cardorder.push_back(Card(i,2,3,1));
    }
    for (int i=38;i<=45;i++){                       // initiate blue Moon cards
        this->cardorder.push_back(Card(i,2,4,1));
    }
    for (int i=46;i<=47;i++){                       // initiate green door cards
        this->cardorder.push_back(Card(i,3,1,1));
    }
    for (int i=48;i<=50;i++){                       // initiate green key cards
        this->cardorder.push_back(Card(i,3,2,1));
    }
    for (int i=51;i<=54;i++){                       // initiate green Sun cards
        this->cardorder.push_back(Card(i,3,3,1));
    }
    for (int i=55;i<=61;i++){                       // initiate green Moon cards
        this->cardorder.push_back(Card(i,3,4,1));
    }
    for (int i=62;i<=63;i++){                       // initiate yellow door cards
        this->cardorder.push_back(Card(i,4,1,1));
    }
    for (int i=64;i<=66;i++){                       // initiate yellow key cards
        this->cardorder.push_back(Card(i,4,2,1));
    }
    for (int i=67;i<=70;i++){                       // initiate yellow Sun cards
        this->cardorder.push_back(Card(i,4,3,1));
    }
    for (int i=71;i<=76;i++){                       // initiate yellow Moon cards
        this->cardorder.push_back(Card(i,4,4,1));
    }
}
void Deck::shuffle() {
    // set up the random seed by time
    unsigned seed = chrono::system_clock::now ().time_since_epoch ().count ();
    // shuffle the whole draw deck with seed
    ::shuffle(this->cardorder.begin(),this->cardorder.end(),default_random_engine (seed));
}