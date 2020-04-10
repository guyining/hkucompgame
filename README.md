# COMP2113/ENGG1340 Program Technologies Course Project

 Team members:
Gu Yining (UID:3035638064)
Wang Xiayu (UID:3035332062)

Game description:
Orinim - a solo/cooperative card game

Goal of the game:
Player (or with a partner) must work against game to gather eight Door cards before the deck runs out. In this project, we only provide a solo version. 

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
	Door deck
	Play hand

How to win:
In Onirim, player play cards from the hand of 5 cards in a row to obtain Door cards. 
To win the game, player should decide the best use of each card in the hand and play carefully around the Nightmare cards.
Everytime a Nightmare card is drawed in the deck, player must resolve it immediately.
Player loses imediately if the cards in draw deck runs out.

Flow of the game:
Setup stage
	Shuffle all the cards to form a draw deck.
	Draw five cards as opening hand. If Doors or Nightmares are drew, set aside to the Limbo pile. Keep drawing until five Location are drew.
	After having a hand of five Location cards, shuffle the Limbo pile back to the draw deck.

Overview of a turn -- 3 phases
	1) Play a card or discard one
	2) Fill the hand
	3) Shuffle the Limbo Pile

Play a card:
	Take one Location card from the hand and play it to the Labyrinth deck.
	Except the first card, every Location card played must be of a different symbol, i.e. Sun, Moon and Key, from the previous one card.
	A Door is unlocked when the third card of the same color is played. Put the unlocked Door card to the Door deck. A fourth card of the same color will be counted as the first card in a row. 

Discard a card: 
	Discarding means a card is moved to the discard deck and cannot be used for the rest of the game.
	Discarding a Key card will trigger a prophercy. The player must complete the following steps:
      1) look at the top five cards from the draw deck
      2) discard one of them 
      3) put the other cards back in any order the player want
    If there are less then five cards in the draw deck, still complete the steps above.

Fill the hand: 
	After playing or discarding a card, player must fill the hand back to 5 cards.
	Draw the card one at a time and resolve them:
		a) Location card - just add it to the hand
		b) Door card - unlock immediately if discard a Key card of the same color and put the Door card to the Door deck; otherwise put it to the Limbo pile 
		c) Nightmare card - four ways to resolve:
			discarding a Key card from the hand
			discarding the whole hand and repeat setup steps
			discarding a unlock Door back to the Limbo pile
			discarding the top five cards in the draw deck
		Once the Nightmare card is resolved, it goes to the Discard deck.

Shuffle the Limbo pile:
	After shuffle the Limbo pile back to the Draw deck, a turn is completed. Player can then start the next turn.
	
End of the game
	The game ends when:
	a) All 8 Door cards are in the Door deck. The player wins the game!
	b) The Draw deck is empty. The player loses the game.
	
    
