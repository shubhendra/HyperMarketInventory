#include<iostream>
#include "ListBase.h"

#ifndef __SORTEDDOUBLELINKEDLIST_H__
#define __SORTERDOUBLELINKEDLIST_H__
template<typename T>
class SortedLinkedList : public ListBase<T>{
protected:
	struct ListNode {
		T* item;
		ListNode* next;
		ListNode* prev;
	};
	ListNode* _head;
	ListNode* traverseTo(int index)
	{
		if ( (index < 0) || (index >= getLength()) )
        return NULL;
		ListNode* curr=_head;
		int i;
		for (i=0;i<index;i++)
		{
			curr=curr->next;
		}
		return curr;
	}
	int findindex(T* item)
	{
		int tempIndex=0;
		ListNode *curr;
		curr=_head;
		while((curr!=NULL)&&(*(curr->item)<=*item))
		{
			curr=curr->next;
			++tempIndex;
		}
		return tempIndex;
	}
public:
	SortedLinkedList() : ListBase(){_head=NULL;}

	/*bool addItem(int index,const T& newItem)
	{
		ListNode* newNode;
		newNode= new ListNode;
		newNode->item=newItem;
		newNode->prev=NULL;
		newNode->next=NULL;
		if (index>=_size)
		{
			return false;
		}
		else
		{
			ListNode* temp;
			temp=traverseTo(index);
			if ((newNode->item>=temp->prev->item)&&(newNode->item<=temp->item))
			{
				newNode->next=temp;
				newNode->prev=temp->prev;
				temp->prev->next=newNode;
				temp->prev=newNode;
				temp=newNode;
				++_size;
				return true;
			}
			else
			{
				cout<<"The data cannot be added to this position because it does not comply to the data sequence."<<endl;
				return false;
			}
		}
	}*/
	bool addItem(T* newItem)
	{
		ListNode* newNode;
		newNode= new ListNode;
		newNode->item=newItem;
		newNode->prev=NULL;
		newNode->next=NULL;
		/*if (_size==0)
		{
			_head=newNode;
			_head->next=NULL;
			_head->prev=NULL;
			++_size;
			return true;
		}
		else
		{
			int _toAdd;
			ListNode* temp;
			_toAdd=index(newItem);			
			if(_toAdd!=_size)
			{
				temp=traverseTo(_toAdd);
				newNode->next=temp;
				newNode->prev=temp->prev;
				if(temp->prev!=NULL)
				{
					temp->prev->next=newNode;
				}
				++_size;
			}
			else
			{
				temp=traverseTo(_toAdd-1);
				temp->next=newNode;
				newNode->prev=temp;
				++_size;
			}
			return true;

		}*/
		 int newLength = getLength() + 1;
		int index=findindex(newItem);
		 if ( (index < 0) || (index >= newLength) )
        return false;
    else {  
        ListNode *newPtr = new ListNode;
        newPtr->item = newItem;
        newPtr->next = NULL;
		newPtr->prev = NULL;
        _size = newLength;
        
        if (index == 0){
            ListNode *curr = _head;
			newPtr->next = curr;			//Step 1
			newPtr->prev = NULL;

			//curr->prev->next = newPtr;	//Step 2 this is not necessary because head has no prev node
			if(curr != NULL)				//Check tosee if this is first node added
				curr->prev = newPtr;
            _head = newPtr;


        } else {  
            ListNode *curr = traverseTo( index-1 );
            newPtr->next = curr->next;			//Step 1
            newPtr->prev = curr;

			if(curr->next != NULL)				//If curr is the last node, curr->next will be NULL
				curr->next->prev = newPtr;		//Step 2
			curr->next = newPtr;
        }
    }
    return true;
	}
	bool removeItem(int index)
	{
		 ListNode *cur;

    if ( (index < 0) || (index >= getLength()) )
        return false;
    else {  
        if ( index == 0 ) {  
            cur = _head;  
            _head = _head->next;
			if(cur->next != NULL)
				cur->next->prev = cur->prev; //Step 1
        } else {
            cur = traverseTo( index );

			cur->prev->next = cur->next; //Step 1 

			if(cur->next != NULL)		//Check to see if the next node is null
				cur->next->prev = cur->prev;
        }
        delete cur;						//Step 2
        cur = NULL;
		--_size;

    }
    return true;
	}

	T* retrieveItem(int index)
	{
		if((index>=_size)||(index<0))
		{
			return NULL;
		}
		else
		{
			ListNode* curr;
			curr=traverseTo(index);
			return (curr->item);
		}
		
	}
	~SortedLinkedList()
	{
		ListNode* curr=_head;
		ListNode* toBeDeleted;
		while (curr!=NULL)
		{
			toBeDeleted=curr;
			curr=curr->next;
			delete toBeDeleted->item;
			delete toBeDeleted;
		}
	}
};
#endif