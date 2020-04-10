# COMP2113/ENGG1340 Program Technologies Course Project

 Team members:
 Gu Yining (UID:3035638064)
 Wang Xiayu (UID:3035332062)

Game description:
Orinim - a solo/cooperative card game

Goal of the game:
Player (or with a partner) must work against game to gather eight Door cards before the deck runs out. 

Deck of the game:
	8 Door cards - two each of red, blue, green and brown
	10 Nightmare cards
	58 Location cards:
	16 red chambers: 3 Keys, 4 Moons, 9 Suns
	15 blue chambers: 3 Keys, 4 Moons, 8 Suns
	14 green chambers: 3 Keys, 4 Moons, 7 Suns
	13 brown chambers: 3 Keys, 4 Moons, 6 Suns

Piles of cards:
	Draw deck
	Labyrinth deck
	Limbo pile
	Discard deck

How to win:
In Onirim, player play cards from the hand of 5 cards in a row to obtain Door cards. 
Player can obtain Door cards by:
	playing three Location cards of the same color in a row
	discarding one Key cards of the same color when a Door card is drew from the deck

To win the game, player should decide the best use of each card in the hand and play carefully around the Nightmare cards.
Everytime a Nightmare card is drawed in the deck, player must resolve it immediately.
Player can resolve the Nightmare card by:
	discarding a key card from the hand
	discarding the whole hand
	discarding a Door back to the deck
	discarding the top five cards in the deck
Player loses imediately if the cards in draw deck runs out.

Flow of the game:
Setup stage:
	Shuffle all the cards to form a draw deck.
	Draw five cards as opening hand. If Doors or Nightmares are drew, set aside to the Limbo pile. Keep drawing until five Location are drew:
	After having a hand of five Location cards, shuffle the Limbo pile back to the draw deck.

Overview of a turn - 3 phases:
	1) Play a card or discard one
	2) Fill the hand
	3) Shuffle the Limbo Pile

Play a card:
	Take one Location card from the hand and play it to the Labyrinth deck.
	Except the first card, every Location card played must be of a different symbol, i.e. Sun, Moon and Key, from the previous one card.
	A Door is unlocked when the third card of the same color is played. A fourth card of the same color will be counted as the first card in a row.

Discard a card: 
        discarding means a card is moved to the discard deck and cannot be used for the rest of the game.
	discarding a Key card will trigger a prophercy. The player must complete the following steps:
      		1) look at the top five cards from the draw deck
      		2) discard one of them 
     	 	3) put the other cards back in any order the player want
    		If there are less then five cards in the draw deck, still complete the steps above.

Function:
[Start the Game]
getCardStart()  //Draw five cards as opening hand randomly.
Limbo()   //Check if Doors or Nightmares are drew. If yes, set aside to the Limbo pile.
gameStart()   //When both the players have five valid cards. Shuffle the Limbo pile back to the draw deck. 
[Play the Game]
GetCard()   //Draw card from the deck. 

playaCard()   //Player play a card on the Labyrinth deck
validPlayCard()   //Check if each location card have a different symbol

discardaCard()   //Player choose a card the discard
ifDiscardKey()   //If the player discard a key, trigger a prophercy.
	lookTopFiveCard()   //Look top five card. If the resisting card less than five, get to look all of them.
	changeOrder()   //Player can change the order of the top five card.

nightmare()   //Player do something to face the nightmare. 
afterNightmare()   //Check if the player survived after the nightmare. 
[Win the Game]
openDoor()   //When three continue card have the same color, door will open. 
sortedDoor()   //Sort the number of door that are opened by each player.
eightDoor()   //Check if a player get eight door card. Win the game. 
