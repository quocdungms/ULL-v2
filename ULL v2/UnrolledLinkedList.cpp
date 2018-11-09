#include"UnrolledLinkedList.h"

void UnrolledLinkedList::add(int val) 
{
	// TODO
	if (head == NULL) 
	{
		Node *tempNode = new Node(nodeSize);
		numOfNodes++;
		head = tail = tempNode;
		head->add(val);
		size++;
	}
	else if ( tail -> isFull() )
	{
		Node *tempNode = new Node(nodeSize);
		numOfNodes++;
		int j = 0;

		for (int i = tail->getHalfNodeSize(); i < tail->numElements ; i++)
		{
			tempNode->add(tail->elements[i]);
		}

		tail->numElements = tail->getHalfNodeSize();
		tempNode->add(val);
		size++;
		tail->next = tempNode;
		tempNode->prev = tail;
		tail = tempNode;

	}
	else
	{
		tail->add(val);
		size++;
	}
}

bool UnrolledLinkedList::contains(int val)
{
	// TODO
	if (head == NULL)
	{
		return false;
	}
		
	Node *current = head;
	while (current)
	{

		for (int i = 0; i < current->numElements; i++)
		{
			if (current->elements[i] == val)
			{
				return true;
			}

		}
		current = current->next;
	}
	return false;
}

int UnrolledLinkedList::firstIndexOf(int val) 
{
	// TODO
	if (head == NULL)
	{
		return -1;
	}

	Node *current = head;
	int index = 0;
	while (current) 
	{
		for ( int i = 0; i < current->numElements; i++)
		{
			if (current->elements[i] == val) 
			{
				return index;
			}
			index++;
		}

		current = current->next;
	}
	return -1;

}

int UnrolledLinkedList::lastIndexOf(int val) 
{
	// TODO
	if (head == NULL)
	{
		return -1;
	}
	int index = 0;
	/*Node *current;
	
	for (current = head; current != NULL; current = current->next)
	{
		for (int i = 0; i < current->numElements; i++)
		{
			index++;
		}
	}
	printf("index = %d\n");
	while (current = head)
	{
		for (int i = 0; i < current->numElements; i++)
		{
			index--;
			if (current->elements[i] == val)
			{
				return index;
			}
		}
		current = current->next;
	}
	return -1;*/

	Node *count;
	for (count = head; count != NULL; count = count->next)
	{
		for (int i = 0; i < count->numElements; i++)
			index++;

	}
	/*std::cout << "Index = " << index << "\n";*/
	for (count = head; count != NULL; count = count->next)
	{
		for (int i = 0; i < count->numElements; i++)
		{
			index--;
			if (count->elements[i] == val)
			{
				return index;
			}
		}
	}
	return -1;
}

int UnrolledLinkedList::getAt(int pos) 
{
	if (pos < 0 || pos >= size) 
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not

	else
	{

		if (head == NULL)
		{
			return -1;
		}

		int index = 0;
		Node *current = head;
		while (current)
		{
			for (int i = 0; i < current->numElements; i++)
			{
				if (index == pos)
					return current->elements[i];
				index++;
			}
			current = current->next;
		}
		return -1;
	}
	/*else 
	{
		Node* pTemp = head;

		int posTemp = pos + 1;
		while (posTemp - pTemp->numElements > 0) 
		{
			posTemp = posTemp - pTemp->numElements;
			pTemp = pTemp->next;
		}

		int index = posTemp - 1;
		return pTemp->elements[index];
	}*/
	/*else
	{
		if (head == NULL)
		{
			return -1;
		}
		int index = 0;
		Node *current = head;
		while (current)
		{
			for (int i = 0; current->numElements; i++)
			{
				if (index == pos)
				{
					return current->elements[i];
					
				}
				index++;
			}
			current = current->next;
		}
	}*/

}

void UnrolledLinkedList::setAt(int pos, int val) 
{
	if (pos < 0 || pos >= size)
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not
	// TODO

	else
	{
		int index = 0;
		Node *current = head;/*new Node(nodeSize);*/
							 /*current = head;*/
		while (current)
		{

			for (int i = 0; i < current->numElements; i++)
			{
				
				if (index == pos)
				{
					current->elements[i] = val;
				}
				index++;
			}
			current = current->next;
		}
	}


}


void UnrolledLinkedList::insertAt(int pos, int val) {
	if (pos < 0 || pos > size)
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not	
	// TODO

}

void UnrolledLinkedList::deleteAt(int pos)
{
	if (pos < 0 || pos >= size) 
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not
	// TODO

}



// reverse con bug
void UnrolledLinkedList::reverse() 
{
	// TODO

	if (head == NULL)
		return;
	Node *current = head;
	Node *pre = NULL, *nex = NULL;


	while (current != NULL)
	{
		// store next
		nex = current->next;
		//
		// Reverse current node's pointer 
		current->next = pre;

		// Move pointers one position ahead. 
		pre = current;
		current = nex;
	}
	head = pre;
	
	
}

int* UnrolledLinkedList::toArray() 
{
	// TODO
	if (head == NULL)
		return NULL;
	int *arr = new int[size];
	int j = 0;
	Node *current = head;
	while (current) 
	{
		int i = 0;
		for (i; i < current->numElements; i++) 
		{
			arr[j++] = current->elements[i];
		}
		current = current->next;
	}
	return arr;
}