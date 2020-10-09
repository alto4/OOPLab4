/** ICE4.cpp
 *	
 *	Code the Insert() and Remove() methods as speficed in the comments. Use the 
 *	commented out lines of code in main() to test your work.
 *
 *	@author		YOUR NAMES GOES HERE
 *	@author		Thom MacDonald modified by Dr. Sukhwant Sagar
 *	
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#include <iostream>		
#include <stdexcept>
#include <sstream>
#include "PlayingCard.h"
#include <ctime>

using namespace std;

// Container class
class StandardDeck
{
	private:
		PlayingCard * myCardsArray;  // pointer to a dynamically-allocated c-array 
		int mySize;		// the size of the c-array
		
	public:
		StandardDeck(); // constructor
		void Initialize(); 	// Can be called on construction or any time after

		// Rule of Three destructor, copy constructor, and assignment operator method declarations
		~StandardDeck() { delete [] myCardsArray;} // destructor
		StandardDeck(const StandardDeck &source); // copy constructor
		StandardDeck& operator=(const StandardDeck &source); // assignment operator	

		int Size() const {return mySize;} // mySize accessor
		PlayingCard operator[](int index) const;  // accessor version of []
		PlayingCard& operator[](int index);		  // mutator version of []

		string DebugString() const; // an accessor to show info about the state of the object		

		void Resize(int newSize);	// re-sizing mutator

		void PushBack(PlayingCard newCard); // for adding an element to the back/end
		PlayingCard PopBack();				 // for removing an element from the back/end
		void PushFront(PlayingCard newCard); // for adding an element to the front/start
		PlayingCard PopFront();	  			// for removing an element from the front/start
		
		/** NEW!
		 *	Two new mutators are added to the class. You will need to code them.
		 */	
		void Insert(int index, PlayingCard card);  // for inserting a card at a specific index
		void Remove(int index); // for removing a card at a specific index

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
//	// Check for existing deck that already has memory allocated, and delete it if in existence
//	if(myCardsArray != 0)
//	{
//		delete [] myCardsArray;
//	}	
//	
//	// Allocate memory for new array
//	myCardsArray = new PlayingCard [size]; 
//	mySize = size; 
//	
//	// Loop through each allocated index and fill it up with a randomly generate PlayingCard instance
//	for(int i = 0; i < mySize; i++)
//	{
//		// give the playing card a random suit and rank
//		myCardsArray[i].SetSuit(rand() % (PlayingCard::SUITS)); 
//		myCardsArray[i].SetRank(1 + rand() % (PlayingCard::RANKS)); 
//	}
}

// Copy Constructor definition
StandardDeck::StandardDeck(const StandardDeck &source) 
{
	// Allocate memory for new array
	mySize = source.mySize; // set the size
	myCardsArray = new int [mySize]; 
	
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < mySize; i++)
	{
		myCardsArray[i] = source.myCardsArray[i];
	}
}

StandardDeck& StandardDeck::operator=(const StandardDeck &source)
{
	delete [] myCardsArray; // free up the old memory
	
 	// Allocate memory for new array
 	mySize = source.mySize; // 
	myCardsArray = new int [mySize]; 

	// Copy each element from the source array to each element of the new array
	for(int i = 0; i < mySize; i++)
		myCardsArray[i] = source.myCardsArray[i];
	
	return *this;
}

int main()
{
	cout << "Let's play cards!!!" << endl;
	
	// END-OF-PROGRAM
	cout << endl << endl;
	return 0;
} // end of main()

 
 // Copy Constructor definition
StandardDeck::StandardDeck(const StandardDeck &source) 
{
	// Allocate memory for new array
	mySize = source.mySize; // set the size
	myCardsArray = new int [mySize]; 
	
	// Initialize each element to the corresponding value in the source object
	for(int i = 0; i < mySize; i++)
	{
		myCardsArray[i] = source.myCardsArray[i];
	}
}

StandardDeck& StandardDeck::operator=(const StandardDeck &source)
{
	delete [] myCardsArray; // free up the old memory
	
 	// Allocate memory for new array
 	mySize = source.mySize; // 
	myCardsArray = new int [mySize]; 

	// Copy each element from the source array to each element of the new array
	for(int i = 0; i < mySize; i++)
		myCardsArray[i] = source.myCardsArray[i];
	
	return *this;
}


void PlayingCards::Insert(int index, PlayingCard card)
{
	// if the index is not valid, throw an error
		// index == mySize will be valid because it will grow
		
	// Make the collection bigger by 1
	
	// Move the existing elements to the right of the index forward 1 spot:
	
	// set the index element
	
}

/** PlayingCard::Remove
 *	Used to remove the PlayingCard object at the provided index
 *	@param index: int - where the object will be removed
 *	@throws out_of_range if index is not valid
 */
void PlayingCards::Remove(int index)
{
	// if the index is not valid, throw an error
		 // index == mySize is NOT valid because there is no element there
		
	
	// Move the existing elements to the right of the index back by 1 spot:
	
	// Make the container smaller by 1
	
}



/** 
 *	DO NOT MODIFY the code below this line
 */

// constructor
PlayingCards::PlayingCards(int size)
{
	// Set the pointer to zero
	myArray = 0;
	// Call the initialization method
	Initialize(size);
}

// to initialize or re-initialize the object
void PlayingCards::Initialize(int size)
{
	// if the pointer is not 0, memory has been allocated
	if(myArray != 0)
		// delete the existing memory
		delete [] myArray;
		
	// Allocate a new array dynamically on construction
	myArray = new PlayingCard [size]; // may throw bad_alloc exception
	mySize = size; // set the size
	
	// Loop for each element
	for(int i = 0; i < mySize; i++)
	{
		// give the playing card a random suit and rank
		myArray[i].SetSuit(rand() % (PlayingCard::SUITS)); 
		myArray[i].SetRank(1 + rand() % (PlayingCard::RANKS)); 
	}
	
}

// copy constructor
PlayingCards::PlayingCards(const PlayingCards &source)
{
	// Allocate a new array dynamically on construction
	mySize = source.mySize; // set the size
	myArray = new PlayingCard [mySize]; // may throw bad_alloc exception
	// Initialize each element to the corresponding playing card in the source object
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
}

// assignment operator
PlayingCards& PlayingCards::operator=(const PlayingCards &source)
{
	delete [] myArray; // free up the old memory
	// Allocate a new array dynamically on construction
	mySize = source.mySize; // set the size
	myArray = new PlayingCard [mySize]; // may throw bad_alloc exception
	// Initialize each element to the corresponding playing card in the source object
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
	
	return *this;
} 

// an accessor to show info about the state of the object	
string PlayingCards::DebugString() const
{
	stringstream debug;
	debug << "\n==================== DEBUG ====================" << endl
		  << "myArray: " << myArray << endl
		  << "mySize:  " << mySize << endl;
	for(int i = 0; i < mySize; i++)
	{
		debug << "[" << i << "]: " << (string) myArray[i] << endl;
	}

	debug << "\n===============================================" << endl;
	return debug.str();
}

// operator [] accessor for an element of myArray
PlayingCard PlayingCards::operator[](int index) const
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	// return the playing card stored at element index BY VALUE
	return myArray[index]; 
}	
// operator [] mutator for an element of myArray
PlayingCard& PlayingCards::operator[](int index) 
{
	// if the parameter index is invalid, throw an exception
	if(index < 0 || index >= mySize)
		throw out_of_range("Index must be between 0 and " + to_string(mySize - 1) + ".");
	// return a REFERENCE to the playing card at index
	return myArray[index]; 
}

// re-sizing mutator
void PlayingCards::Resize(int newSize)
{
	PlayingCard * newArray = new PlayingCard[newSize]; // throws bad_alloc on failure
	int elementsToCopy = (mySize < newSize)? mySize : newSize; // whichever is smaller
	
	// Copy each each existing playing card to the new array
	for(int i = 0; i < elementsToCopy; i++)
		newArray[i] = myArray[i];

	// Set the new size
	mySize = newSize;
	
	// Delete the old array
	delete [] myArray;
	
	// Set the myArray pointer to the new array
	myArray = newArray;
}

// for adding an element to the back/end
void PlayingCards::PushBack(PlayingCard newCard)
{
	// Make the container larger by 1
	Resize(mySize + 1);
	// Add the new value to the end
	myArray[mySize - 1] = newCard;
}

// for adding an element to the front/start
void PlayingCards::PushFront(PlayingCard newCard)
{
	// Make the container larger by 1
	Resize(mySize + 1);
	
	// Shift all the existing element value backward 1 spot:
	for(int moveTo = mySize - 1; moveTo > 0; moveTo--)
	{
		myArray[moveTo] = myArray[moveTo - 1];
	}
	
	// Add the new value to the front
	myArray[0] = newCard;
}

// for removing an element from the back/end
PlayingCard PlayingCards::PopBack()
{
	// If the container is empty, throw an error
	if(mySize <= 0)
		throw out_of_range("Cannot .PopBack() an empty container. ");
	// preserve the last value
	PlayingCard card = myArray[mySize - 1];
	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return card;
}

// for removing an element from the start/front
PlayingCard PlayingCards::PopFront()
{
	// If the container is empty, throw an error
	if(mySize <= 0)
		throw out_of_range("Cannot .PopFront() an empty container. ");
	// preserve the first value
	PlayingCard card = myArray[0];
	
	// Shift all the existing element value forward by 1 spot:
	for(int moveTo = 0; moveTo < mySize - 1; moveTo++)
	{
		myArray[moveTo] = myArray[moveTo + 1];
	}
	
	// Make the container smaller by 1
	Resize(mySize - 1);
	// return the former last value
	return card;
}

