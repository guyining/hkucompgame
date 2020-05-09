# COMP2113/ENGG1340 Program Technologies Course Project

## 1. Team members
- Wang Xiayu (UID:3035332062)
## 2. Game description
Onirim - a solo Board Game
### 2.1 Goal of the game
Player (or with a partner) must work against game to gather eight Door cards before the deck runs out. In this project, we only provide a solo version. 
### 2.2 How to win
In Onirim, player play cards from the hand of 5 cards in a row to obtain Door cards.</br>
To win the game, player should decide the best use of each card in the hand and play carefully around the Nightmare cards.</br>
Everytime a Nightmare card is drawed in the deck, player must resolve it immediately. </br>
Player loses imediately if the cards in draw deck runs out.</br>
### 2.3 Deck of the game
- 8 Door cards - two each of red, blue, green and brown
- 10 Nightmare cards
- 58 Location cards:
- 16 red chambers: 3 Keys, 4 Moons, 9 Suns
- 15 blue chambers: 3 Keys, 4 Moons, 8 Suns
- 14 green chambers: 3 Keys, 4 Moons, 7 Suns
- 13 brown chambers: 3 Keys, 4 Moons, 6 Suns
### 2.4 Piles to separate cards
- Draw deck
- Labyrinth deck	- to put the cards played by the player
- Limbo pile 		- a temporary pile to put Door and Nightmare cards within one turn
- Discard deck 		- to put the cards discarded and will not be draw in the rest of the game
- Door deck		- to put the unlocked Doors
- Play hand		- player's hand
### 2.5 Flow of the game
#### 2.5.1 Setup stage
1. Shuffle all the cards to form a draw deck.
2. Draw five cards as opening hand. If Doors or Nightmares are drew, set aside to the Limbo pile. Keep drawing until five Location are drew.
3. After having a hand of five Location cards, shuffle the Limbo pile back to the draw deck.
#### 2.5.2 Overview of a turn -- 3 phases
1. Play a card or discard one
2. Fill the hand
3. Shuffle the Limbo Pile
#### **Play a card:**
Take one Location card from the hand and play it to the Labyrinth deck.</br>
Except the first card, every Location card played must be of a different symbol, i.e. Sun, Moon and Key, from the previous one card.</br>
A Door is unlocked when the third card of the same color is played. Put the unlocked Door card to the Door deck. A fourth card of the same color will be counted as the first card in a row. </br>
#### **Discard a card:** 
Discarding means a card is moved to the discard deck and cannot be used for the rest of the game.</br>
Discarding a Key card will trigger a prophercy. The player must complete the following steps:</br>
1. look at the top five cards from the draw deck
2. discard one of them 
3. put the other cards back in any order the player want
If there are less then five cards in the draw deck, still complete the steps above.</br>
#### **Fill the hand:**
After playing or discarding a card, player must fill the hand back to 5 cards.</br>
Draw the card one at a time and resolve them:</br>
1. Location card - just add it to the hand</br>
2. Door card - unlock immediately if discard a Key card of the same color and put the Door card to the Door deck; otherwise put it to the Limbo pile </br>
3. Nightmare card - four ways to resolve:
   - discarding a Key card from the hand</br>
   - discarding the whole hand and repeat setup steps</br>
   - discarding a unlock Door back to the Limbo pile</br>
   - discarding the top five cards in the draw deck</br>
Once the Nightmare card is resolved, it goes to the Discard deck.</br>

#### **Shuffle the Limbo pile:**
After shuffle the Limbo pile back to the Draw deck, a turn is completed. Player can then start the next turn.
	
### 2.6 End of the game
The game ends when:</br>
1. All 8 Door cards are in the Door deck. The player wins the game!</br>
2. The Draw deck is empty. The player loses the game.</br>

### 2.7 Reference of the game
- Onirim - Setup & How to Play https://www.youtube.com/watch?v=h_CLy5pS4j8
- Onirim | Board Game | BoardGameGeek https://boardgamegeek.com/boardgame/71836/onirim

## 3. Function
### 3.1 Generation of random game sets or events
When the game starts, the a deck of 76 cards is created in an fixed order. </br>
Before the hand is dealt to the player, the deck needs to be shuffled. </br>
This requires a generation of random sets.</br>
Every game play will require at least one time of shuffle for the draw deck.</br>
### 3.2 Data structures for storing game status
Every card has four characteristics:</br>
- cardID: Card number 1-76
- cardColor: 1 for red, 2 for blue, 3 for green 4 for yellow, 5 for Nightmare, 0 for empty card 
- cardSignal: 1 for door, 2 for key, 3 for moon, 4 for sun, 5 for nightmare, 0 for empty card
- status: 0 for cards which has been played and opened a door, 10086 for the empty card
A card has this set of data to be stored together as a class variable</br>
A Deck is a set of several cards while playing.</br>
- Door deck is to store the unlocked Doors
- Draw deck is to store the cards which have not been drew
- Hand deck is to store the cards in hand
- Labyrinth deck is to store the cards played
### 3.3 Dynamic memory management
When a card is discarded, it will never be used again in this game play.</br>
Therefore, memory to store this card is no longer needed.</br>
Data for this card will be erased in during the game play.</br>
This applies to: </br>
- 1) player chooses to discard a card
- 2) a Nightmare is solved
Card data require dynamic memory management also when the card needs to go to other decks.</br>
### 3.4 File input/output (e.g., for loading/saving game status)
Everytime when player makes a choice to play or discard a card, contents all four decks stated above (door deck, draw deck, hand deck and labyrinth deck) will be outputted to a txt file for saving.</br>
While the player has exit but the game is still in progress, deck contents will be outputted to the same file.</br>
Player can continue next time by inputting the txt contents to the program.</br>
The txt file will be delete once a game is finished no matter winning or losing.</br>
The txt file will be delete if player wishes to abort the game.</br>
### 3.5 Program codes in multiple files
The complexity of the game requires multiple files for the program.</br>
Cards data and deck data are complicated to store or call if all of them are in only one cpp file.</br>
For example, multiple arrays will be needed for cards ID, color, symbol(signal), status.</br>
For clearification, a class is designed in another file to store the card easier.</br>
Another class for deck is also created in another separate file for the structure of decks.</br>

## 4. Compilation and execution instructions
### 4.1 Compilation 
g++ -pedantic-errors -std=c++11 Card.cpp Deck.cpp main.cpp -o main
### 4.2 Execution
./main
