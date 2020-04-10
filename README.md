# COMP2113/ENGG1340 Program Technologies Course Project

## 1. Team members
- Gu Yining (UID:3035638064)
- Wang Xiayu (UID:3035332062)
## 2. Game description:
### 2.1 Goal of the game
Player (or with a partner) must work against game to gather eight Door cards before the deck runs out. In this project, we only provide a solo version. 
### 2.2 Deck of the game
- 8 Door cards - two each of red, blue, green and brown
- 10 Nightmare cards
- 58 Location cards:
- 16 red chambers: 3 Keys, 4 Moons, 9 Suns
- 15 blue chambers: 3 Keys, 4 Moons, 8 Suns
- 14 green chambers: 3 Keys, 4 Moons, 7 Suns
- 13 brown chambers: 3 Keys, 4 Moons, 6 Suns
### 2.3 Piles to separate cards
- Draw deck
- Labyrinth deck	- to put the cards played by the player
- Limbo pile 		- a temporary pile to put Door and Nightmare cards within one turn
- Discard deck 		- to put the cards discarded and will not be draw in the rest of the game
- Door deck		- to put the unlocked Doors
- Play hand		- player's hand
### 2.4 How to win
In Onirim, player play cards from the hand of 5 cards in a row to obtain Door cards.</br>
To win the game, player should decide the best use of each card in the hand and play carefully around the Nightmare cards.</br>
Everytime a Nightmare card is drawed in the deck, player must resolve it immediately. </br>
Player loses imediately if the cards in draw deck runs out.</br>
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
If there are less then five cards in the draw deck, still complete the steps above.＜/br＞
#### **Fill the hand:**
After playing or discarding a card, player must fill the hand back to 5 cards.</br>
Draw the card one at a time and resolve them:</br>
1. Location card - just add it to the hand</br>
2. Door card - unlock immediately if discard a Key card of the same color and put the Door card to the Door deck; otherwise put it to the Limbo pile </br>
3. Nightmare card - four ways to resolve:</br>
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
[Start the Game]</br>
- getCardStart()	//Draw five cards as opening hand randomly.
- checkLimbo()   	//Check if Doors or Nightmares are drew. If yes, set aside to the Limbo pile.
- gameStart()   	//When both the players have five valid cards. Shuffle the Limbo pile back to the draw deck.
### 3.2 Data structures for storing game status
[Play the Game]</br>
- GetCard()   		//Draw card from the deck. 
</br>
- playaCard()   	//Player play a card on the Labyrinth deck
- validPlayCard()   	//Check if each location card have a different symbol
</br>
- discardaCard()   	//Player choose a card the discard
- ifDiscardKey()   	//If the player discard a key, trigger a prophercy.
- lookTopFiveCard()   	//Look top five card. If the resisting card less than five, get to look all of them.
- changeOrder()   	//Player can change the order of the top five card.
</br>
- nightmare()  		//Player do something to face the nightmare. 
- afterNightmare()   	//Check if the player survived after the nightmare. 
[Win the Game]</br>
- openDoor()   		//When three continue card have the same color, door will open. 
- sortedDoor()   	//Sort the number of door that are opened by each player.
- eightDoor()  		//Check if a player get eight door card. Win the game. 
### 3.3 Dynamic memory management
- deck()  	 	//memory the card left in the deck
- playercard() 		//memory the card in player1's hand
- Playerdoor()   	//memory the door opened by player
### 3.4 File input/output (e.g., for loading/saving game status)
- Profile.txt		//Store the profile 
- SaveProfile() 	//Discard the previous version and save the current playing status for later access in Profile.txt
- ReadProfile()		//Read the previous status from Profile.txt saved and continue playing 
### 3.5 Program codes in multiple files
- startgame.h		//For functions of [Start the Game]
- playgame.h		//For functions of [Play the Game]
- wingame.h		//For functions of [Win the Game]


