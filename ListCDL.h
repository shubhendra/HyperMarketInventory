#ifndef LISTCDL_H
#define LISTCDL_H
#include "ListBase.h"
#include <string>
template<typename T>
class ListCDL : public ListBase<T> {
    private:
        struct ListNode {
            T *item;         
            ListNode *next;
			ListNode *prev;
        };
        ListNode* _tail;

       ListNode*    traverseTo( int index ) 
{
   if ( (index < 0) || (index >= getLength()) )
      return NULL;
   else
   {  
      ListNode *cur = _tail->next;

      for ( int skip = 0; skip < index; skip++ )
         cur = cur->next;

      return cur;
   }
}


    public:
        

        

       
ListCDL()
	: ListBase( ){_tail=NULL;}

~ListCDL()
{
   while (!isEmpty())
      removeItem(0);
}



bool addItem( T* newItem ) 
{
   /*int newLength = getLength() + 1;
   int index=0;
  if ( (index < 0) || (index >= newLength) )
     return false;
   else {  
      ListNode *newPtr = new ListNode;
      newPtr->item = newItem;
      newPtr->next = NULL;
	  newPtr->prev=NULL;
      _size = newLength;

      if (index == 0){         
         //If this is the only item, set tail to point to this
		  if (_tail!=NULL)
		 {
				newPtr->next = _tail->next;			 _tail->next->prev=newPtr;
		 
		 }
         		 newPtr->prev=_tail;
				 if(getLength() == 1)
					_tail = newPtr;
				 _tail->next = newPtr;
     
		} 
      //If we are inserting into the last element
      else if (index == getLength()-1) {
         cout << "Inserting " << newItem << " right at the end.." << endl;
         newPtr->next = _tail->next;
		 newPtr->prev=_tail;
		 _tail->next->prev=newPtr;
		// cout<<_tail->item;
		// cout<<_tail->prev->item;
		// cout<<_tail->next->item;
         _tail->next = newPtr;
         _tail = newPtr;
      }
      else {  
         ListNode *curr = traverseTo( index);
         newPtr->next = curr;
		 newPtr->prev=curr->prev;
		 curr->prev->next=newPtr;
         curr->prev = newPtr;
      }
   }
   return true;*/
	ListNode* newNode;
		newNode= new ListNode;
		newNode->item=newItem;
		newNode->prev=NULL;
		newNode->next=NULL;
		if (_size==0)
		{
			_tail=newNode;
			_tail->next=_tail;
			_tail->prev=_tail;
			++_size;
			return true;
		}
		else
		{
			newNode->next=_tail->next;
			_tail->next->prev=newNode;
			newNode->prev=_tail;
			_tail->next=newNode;
			_tail=newNode;
			++_size;
			return true;
		}
}

bool removeItem( int index ) 
{
   ListNode *cur;
   if ( (index < 0) || (index >= getLength()) )
      return false;
   else {  
      
      // If there is no elements left, simply set cur to point to tail
      // and set tail to NULL
      if ( getLength() == 1)
      {
         cur = _tail;
         _tail = NULL;
      }
      else if ( index == 0 ) {  
         cur = _tail->next;  
		 _tail->next = cur->next;
		 cur->next->prev=_tail;
         
      } 
      else {
         if((index+1) == getLength())
         {
          //  cout << "Removing the last element.." << endl;
			_tail->next->prev=_tail->prev;
			 _tail->prev->next=_tail->next;
			 cur=_tail;
			 _tail = _tail->prev;


         }
		 cur = traverseTo( index );
		 cur->next->prev=cur->prev;
		 cur->prev->next=cur->next;
         

         //Check if we are at the last element
         
      }
	 // delete cur->item;
      delete cur;
      cur = NULL;
	  --_size;

   }
   return true;
}

T* retrieveItem( int index ) 
{
   if ( (index < 0) || (index >= getLength()) )
      return NULL;
   else
   {  
      ListNode *cur = traverseTo( index );

      return cur->item;
   }
//   return true;
}


}; 
#endif