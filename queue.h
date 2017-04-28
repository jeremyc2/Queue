/***********************************************************************
* Header:
*    Queue
* Summary:
*    This class contains the notion of a stack: a container
*    that follows First In First Out behavior and
*    expands as more items are put inside.
*
*    This will contain the class definition of:
*        Queue         : A class that holds stuff
* Author
*    Nathan Bench, Jed Billman, Justin Chandler, Jeremy Chandler
************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>
#include <new>

/************************************************
 * QUEUE
 * A class that holds stuff
 ***********************************************/
template <class T>
class Queue
{
public:
   // default constructor : empty and kinda useless
   Queue() : m_top(0), m_capacity(0), m_data(NULL) {}

   // copy constructor : copy it
   Queue(const Queue & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Queue(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Queue()        { if (m_capacity) delete [] m_data; }
   
   // is the container currently empty
   bool empty() const  { return m_top == 0;         }

   // remove all the items from the container
   void clear()        { m_top = 0;                 }

   // how many items can the stack currently contain?
   int capacity() const { return m_capacity;             }
   
   // how many items are currently in the container?
   int size() const    { return m_top;              }

   // increase the capacity
   void increaseCapacity();

   // add an item to the container
   void push(const T & t) throw (const char *);

   // Removes an item from the end of the stack, and reduces size by one
   void pop() throw (const char *);

   // Returns the item currently at the end of the stack
   T & top() const throw (const char *);
   
   // assignment operator '='
   Queue<T> & operator = (const Queue <T> & rhs);
   
   
private:
   T * m_data;          // dynamically allocated array of T
   int m_top;      // how many items are currently in the Queue?
   int m_capacity;      // how many items can I put on the Queue before full?
};


/*******************************************
 * QUEUE :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Queue <T> :: Queue(const Queue <T> & rhs) throw (const char *)
{
   assert(rhs.m_capacity >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.m_capacity == 0)
   {
      m_capacity = m_top = 0;
      m_data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      m_data = new T[rhs.m_capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.m_top >= 0 && rhs.m_top <= rhs.m_capacity);
   m_capacity = rhs.m_capacity;
   m_top = rhs.m_top;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < m_top; i++)
      m_data[i] = rhs.m_data[i];

   // the rest needs to be filled with the default value for T
   for (int i = m_top; i < m_capacity; i++)
      m_data[i] = T();
}

/**********************************************
 * QUEUE : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Queue <T> :: Queue(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (m_capacity == 0)
   {
      this->m_capacity = this->m_top = 0;
      this->m_data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      m_data = new T[capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->m_capacity = capacity;
   this->m_top = 0;

   // initialize the container by calling the default constructor
   for (int i = 0; i < m_capacity; i++)
      m_data[i] = T();
}

/***************************************************
* QUEUE :: INCREASE CAPACITY
* Allocate memory for m_data
**************************************************/
template<class T>
void Queue<T>::increaseCapacity()
{
	int newCap = m_capacity * 2;
   
	if (m_capacity == 0)
		newCap = 1;
   
	T *temp = new T[newCap];
	for (int i = 0; i < m_capacity; ++i)
	{
		temp[i] = m_data[i];
	}
   
	m_capacity = newCap;
	delete[] m_data;
	m_data = temp;
}

/***************************************************
* QUEUE :: PUSH
* Adds an item to the top of the stack
**************************************************/
template<class T>
void Queue<T>::push(const T & t) throw (const char *)
{
   // IF empty increase the capacity
	if (empty() || m_capacity <= m_top)
	{
		increaseCapacity();
	}
	m_data[m_top] = t;
	m_top++;
}

/***************************************************
* QUEUE :: POP
* Removes an item from the end of the stack, and reduces size by one
**************************************************/
template<class T>
inline void Queue<T>::pop() throw(const char *)
{
	if (empty())
		throw "ERROR: Unable to pop from an empty Queue";
	m_top--;
}

/***************************************************
* QUEUE :: TOP
* Returns the item currently at the end of the stack
**************************************************/
template<class T>
inline T & Queue<T>::top() const throw(const char *)
{
	// if empty: throw Unable to reference the element from an empty Queue
	if (empty() || (m_top < 0))
		throw "ERROR: Unable to reference the element from an empty Queue";
	return m_data[m_top - 1];
}

/***************************************************
 * QUEUE :: =
 * Overload assignment operator
 **************************************************/
 template <class T>
Queue<T> & Queue <T> :: operator = (const Queue <T> & rhs)
{
   // don't copy yourself
   if (this != &rhs)
   {
      // clean up m_data
      if (m_data)
         delete [] m_data;
      
      // assign each member variable to right-hand-side
      m_capacity = rhs.m_capacity;
      m_top = rhs.m_top;
      
      // allocate new array
      try
      {
         m_data = new T[m_capacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for Queue";
      }
      // copy over values from rhs
      for (int i = 0; i < rhs.m_top; i++)
      {
         m_data[i] = rhs.m_data[i];
      }
      
      return *this;
   }
}

#endif // QUEUE_H