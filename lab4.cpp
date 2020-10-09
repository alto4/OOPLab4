/** Lab4.cpp
 *
 *	@author		Scott Alton & Jugal Patel
 *	
 *	@see		'PlayingCard.h'
*/

#include <iostream>		
#include <stdexcept>
#include <sstream>
#include "PlayingCard.h"
#include <ctime>

using namespace std;

// Declaration of the StandardDeck class
class StandardDeck {
	
	private:
		// Pointer to store first memory location for array of cards
		PlayingCard * myCardsArray;  
		int numOfCards;	
		
		static const int SIZE = 52;
		
	public:
		// Default constructor
		StandardDeck();
		
		virtual void Initialize();

		// Rule of Three destructor, copy constructor, and assignment operator method declarations
		~StandardDeck() { delete [] myCardsArray;} // destructor
		StandardDeck(const StandardDeck &source); // copy constructor
		StandardDeck& operator=(const StandardDeck &source); // assignment operator	
		
		// Accessors
		PlayingCard GetDeck() const;
		void SetDeck(const PlayingCard& newDeck);
		void SetSize(int size) { numOfCards = size; };
				
		// CardsRemaining method declaration
		int CardsRemaining() { return numOfCards; };
		
		// DebugString method declaration
		string DebugString() const;
		
		// DrawNextCard method 
		PlayingCard DrawNextCard();
		
		// DrawRandomCard method
		PlayingCard DrawRandomCard();
};

// Default constructor
StandardDeck::StandardDeck()
{
	myCardsArray = 0;
	// Initialize a new deck of specified size
	Initialize();
}

// Initialize method - sets or resets entire deck 
void StandardDeck::Initialize() 
{
	// Check for existing deck that already has memory allocated, and delete it if in existence
	if(myCardsArray != 0)
	{
		delete [] myCardsArray;
	}	
	
	// Allocate memory for new array
	myCardsArray = new PlayingCard [SIZE]; 
	numOfCards = SIZE; 
	
	// Declare an index for populating card deck array
	int cardIndex = 0;

	// Loop through each allocated index and fill it up with a PlayingCard instance for each rank within each respective suit
	for(int i = 0; i < PlayingCard::SUITS; i++)
	{
		for(int j = 1; j < PlayingCard::RANKS + 1; j++)
		{
			// DEBUG CODE
			//cout << "card index: " << cardIndex << endl;
			//cout << "suit: " << PlayingCard::CARD_SUIT[i] << endl;
			//cout << "rank: " << PlayingCard::CARD_RANK[j] << endl;
			
			// Set each element
			myCardsArray[cardIndex].SetSuit(PlayingCard::CARD_SUIT[i]); 
			myCardsArray[cardIndex].SetRank(PlayingCard::CARD_RANK[j]);	
			cardIndex++;
		} 
	}
		// DEBUG CODE
		//cout << "My cards array is " << to_string(sizeof(myCardsArray));
		//for(int i = 0; i < sizeof(myCardsArray); i++){
			//cout << myCardsArray[i].GetSuit() << endl;
			//cout << myCardsArray[i].GetRank() << endl;
		//}
}

string StandardDeck::DebugString() const 
{
	std::string output;
	
	for(int i = 0; i < StandardDeck::SIZE; i++)
	{	
		output += "\n-----------------------------------";
		output += "\nCard #: " + std::to_string(i + 1);
		output += "\nCard Suit: " + myCardsArray[i].GetSuit();
		output += "\nCard Rank: " + myCardsArray[i].GetRank(); 
	}
	
	cout << output;
	
	return output;
}

// Copy Constructor definition
StandardDeck::StandardDeck(const StandardDeck &source) 
{
	// Allocate memory for new array
	numOfCards = source.numOfCards; // set the size
	myCardsArray = new PlayingCard [numOfCards]; 
	
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < numOfCards; i++)
	{
		myCardsArray[i] = source.myCardsArray[i];
	}
}

StandardDeck& StandardDeck::operator=(const StandardDeck &source)
{
	delete [] myCardsArray; // free up the old memory
	
 	// Allocate memory for new array
 	numOfCards = source.numOfCards; // 
	// DEBUG THIS!!!!!!!!!
	myCardsArray = new PlayingCard [numOfCards]; 

	// Copy each element from the source array to each element of the new array
	for(int i = 0; i < numOfCards; i++)
		myCardsArray[i] = source.myCardsArray[i];
	
	return *this;
}

// MAIN PROGRAM
int main()
{
	cout << "Hello. Let's play cards!" << endl;	
	
	StandardDeck deck;
	cout << "There are " << deck.CardsRemaining() << " cards remaining." << endl;
	deck.DebugString();
	return 0;
} 

