//
// Created by King's Virus Maker on 2020/5/7.
//

#include "Card.h"
//This is a function to initiate new cards
Card::Card(int a,int b,int c ,int d) {
    this->cardID=a;
    this->cardColor=b;
    this->cardSignal=c;
    this->status=d;
}