/*
 * LaQueue
 *
 *
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *
 * (c) copyright 2018, James Shockey - all rights reserved
 *
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"
using namespace std;



/*
 * Class Priority Queue
 */

/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
    node* newNode = new node(item, priority);

    //if empty or newnode takes priority over front
    if (front == nullptr || priority > front->priority)
    {
        newNode->link = front;
        front = newNode;
        return;
    }

    //searches for placement 
    node* current = front;
    while (current->link != nullptr &&
           current->link->priority >= priority)
    {
        current = current->link;
    }

    newNode->link = current->link;
    current->link = newNode;
}


/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	if (front == NULL)
	{
		return 0; ///
	}
	else
	{
	    return front->data;
	}

}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
    if (front == nullptr)
        return;

    node* temp = front;
    front = front->link;
    delete temp;
}


/*
 * Print Priority Queue
 */
void PQueue::display()
{

	if (front != nullptr)
	{

		string ret = "";
		node* ptr = front;
		while (ptr->link != nullptr) {
	    std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
			ptr = ptr->link;
		}
	    std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;

		cout << ret;

	
	}
	else {
		cout << endl;
	}

	/* Use the following out command for the data */

}
