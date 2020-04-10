# COMP2113/ENGG1340 Program Technologies Course Project

## 1. Team members:
- Gu Yining (UID:3035638064)
- Wang Xiayu (UID:3035332062)

## 2. Game description:
Orinim - a solo/cooperative card game

### 2.1 Goal of the game:
Player (or with a partner) must work against game to gather eight Door cards before the deck runs out. In this project, we only provide a solo version. 

### 2.2 Deck of the game:
- 8 Door cards - two each of red, blue, green and brown
- 10 Nightmare cards
- 58 Location cards:
- 16 red chambers: 3 Keys, 4 Moons, 9 Suns
- 15 blue chambers: 3 Keys, 4 Moons, 8 Suns
- 14 green chambers: 3 Keys, 4 Moons, 7 Suns
- 13 brown chambers: 3 Keys, 4 Moons, 6 Suns

### 2.3 Piles to separate cards:
- Draw deck
- Labyrinth deck	- to put the cards played by the player
- Limbo pile 		- a temporary pile to put Door and Nightmare cards within one turn
- Discard deck 		- to put the cards discarded and will not be draw in the rest of the game
- Door deck		- to put the unlocked Doors
- Play hand		- player's hand

### 2.4 How to win:
In Onirim, player play cards from the hand of 5 cards in a row to obtain Door cards. ＜/br＞
To win the game, player should decide the best use of each card in the hand and play carefully around the Nightmare cards.＜/br＞
Everytime a Nightmare card is drawed in the deck, player must resolve it immediately. ＜/br＞
Player loses imediately if the cards in draw deck runs out. ＜/br＞

### 2.5 Flow of the game:
#### 2.5.1 Setup stage
1. Shuffle all the cards to form a draw deck.
2. Draw five cards as opening hand. If Doors or Nightmares are drew, set aside to the Limbo pile. Keep drawing until five Location are drew.
3. After having a hand of five Location cards, shuffle the Limbo pile back to the draw deck.

#### 2.5.2 Overview of a turn -- 3 phases
1. Play a card or discard one
2. Fill the hand
3. Shuffle the Limbo Pile

##### Play a card:
Take one Location card from the hand and play it to the Labyrinth deck. ＜/br＞
Except the first card, every Location card played must be of a different symbol, i.e. Sun, Moon and Key, from the previous one card.＜/br＞
A Door is unlocked when the third card of the same color is played. Put the unlocked Door card to the Door deck. A fourth card of the same color will be counted as the first card in a row. ＜/br＞

##### Discard a card: 
Discarding means a card is moved to the discard deck and cannot be used for the rest of the game.＜/br＞
Discarding a Key card will trigger a prophercy. The player must complete the following steps:＜/br＞
1. look at the top five cards from the draw deck
2. discard one of them 
3. put the other cards back in any order the player want
If there are less then five cards in the draw deck, still complete the steps above.＜/br＞

##### Fill the hand: 
After playing or discarding a card, player must fill the hand back to 5 cards.＜/br＞
Draw the card one at a time and resolve them:＜/br＞
a) Location card - just add it to the hand＜/br＞
b) Door card - unlock immediately if discard a Key card of the same color and put the Door card to the Door deck; otherwise put it to the Limbo pile ＜/br＞
c) Nightmare card - four ways to resolve:＜/br＞
	discarding a Key card from the hand＜/br＞
	discarding the whole hand and repeat setup steps＜/br＞
	discarding a unlock Door back to the Limbo pile＜/br＞
	discarding the top five cards in the draw deck＜/br＞
Once the Nightmare card is resolved, it goes to the Discard deck.＜/br＞

##### Shuffle the Limbo pile:
After shuffle the Limbo pile back to the Draw deck, a turn is completed. Player can then start the next turn.
	
### 2.6 End of the game
The game ends when:＜/br＞
a) All 8 Door cards are in the Door deck. The player wins the game!＜/br＞
b) The Draw deck is empty. The player loses the game.＜/br＞

### 2.7 Reference of the game
- Onirim - Setup & How to Play https://www.youtube.com/watch?v=h_CLy5pS4j8
- Onirim | Board Game | BoardGameGeek https://boardgamegeek.com/boardgame/71836/onirim
    
