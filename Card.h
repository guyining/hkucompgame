//
// Created by King's Virus Maker on 2020/5/7.
//

#ifndef ONIRIMPROJECT_CARD_H
#define ONIRIMPROJECT_CARD_H


class Card {
    public:
    int cardID;//Number the card by 1-76 in which 1-10=Nightmare
    int cardColor;// 1=red 2=blue 3=green 4=yellow 5=Nightmare
    int cardSignal;//1= door 2=key 3=moon 4=sun 5=Nightmare
    int status=1;//0 means that the card has been played and opened a door. Otherwise, the status is 1
    Card(int,int,int,int);


};


#endif //ONIRIMPROJECT_CARD_H
