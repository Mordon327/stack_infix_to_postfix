//Made By: Shane Soderstrom
//Date: 7/12/2017
//Class: CS 2420-602
//Teacher: Prof. Rudolf


/**
* Modify this file to add method bodies inline with the class defintion as you would
* in C# or Java.  You will need to add more header files to make your implementation work.
* Remember that this stack must use generic types.
* Also document your code, in Javadoc style, and generate it with doxygen so you can see what it looks like.
*/

#ifndef STACK_H
#define STACK_H
#include <cstdlib>   // Provides NULL and size_t
using namespace std; // Provides string
#include <iostream> // Provides cout and cin
#include <vector>
using std::size_t;
template<typename T> //lets the class decide what the value type is

class stack
{
private:
	vector<T> first;
	int vectorSize;
public:

	/**
	* Default Constructor
	* Return an empty stack
	*/
	stack() 
	{
		first;
		vectorSize = 0;
	}

	/**

	*/
	void operator =(const stack& source)
	{
		if (source.isEmpty())
		{
			return;
		}
		else if (first == source)
		{
			return;
		}
		else
		{
			vectorSize = source.size();
			for (int i = 0; i < vectorSize; i++)
			{
				first.push_back(source[i]);
			}
		}
	};

	/**
	* Copy Constructor
	*/
	stack(const stack& source)
	{
		if (this == &source)
		{
			return;
		}
		if (source.isEmpty())
		{
			return;
		}
		else
		{
			if (isEmpty() == false)
			{
				first.clear();
				vectorSize = 0;
			}

			vectorSize = source.size();
			for (int i = 0; i < vectorSize; i++)
			{
				first.push_back(source.first[i]);
			}
		}
	};

	/**
	* Destructor
	*/
	~stack()
	{
		while (vectorSize != 0)
		{
			first.pop_back();
			vectorSize--;
		}
	};

	/**
	add an item to the front of the vector
	*/
	void push(const T& entry)
	{
			first.push_back(entry);
			vectorSize++;
	}

	/**
	remove the first item from the vector
	*/
	T pop()
	{
		if (first.size() == 0)
		{
			T i = 0;
			vectorSize = 0;
			return i;
		}
		else
		{
			vectorSize--;
			T i = first.back();
			first.pop_back();
			return i;
		}
	}

	/**
	return the size of the vector
	*/
	size_t size() const
	{
		return first.size();
	}

	/**
	Test to see if the vector is empty and return a true or false.
	*/
	bool isEmpty() const
	{
		if (first.size() == 0)
			return true;
		else
			return false;
	}

	//returns the data at the top of the list
	T top() const
	{
		if (first.size() == 0)
		{
			T var = 0;
			return var;
		}
		else
		{
			T var = first.back();
			return var;
		}
	}
};

//helper functions

/*
* take an infix string and convert to postfix
* Assume it is valid infix
*/
string i2p(string& infix)
{
	return string("");
}

/*
* Evaluate a postfix expression and rturn a result
* as a double.
* Assume it is valid postfix.
*/
double eval(string& postfix)
{
	return 0.0;
}

#endif
