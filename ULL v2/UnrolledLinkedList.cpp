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
	
		for (int i = tail->getHalfNodeSize(); i < tail->numElements ; i++)
		{
			tempNode->add(tail->elements[i]);
		}

		tail->numElements = tail->getHalfNodeSize();
		tempNode->add(val);
		size++;
		tail->next = tempNode;
		tempNode->prev = tail->next;
		tempNode->next = NULL;
		tail = tempNode;

	}
	else
	{
		tail->add(val);
		size++;
	}
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
void UnrolledLinkedList::insertAt(int pos, int val)
{
	if (pos < 0 || pos > size)
		throw "IndexOutOfBoundsException"; // check whether pos is valid or no
	else
	{

		if (head == NULL)
			return;
		else
		{
			int index = 0;
			int posArr = 0;// vi tri pos trong mang
			int count = 0; // tong so element cua node truoc
			/*int countPosNext = 0;*/
			int posNext = 0;
			Node *current = head;
			while (current)
			{
				for (int i = 0; i < current->numElements; i++)
				{
					if (index == pos)
					{
						posArr = pos - count;
						/*std::cout << "posArr = " << posArr << "\n";*/

						if (!current->isFull())
						{
							current->insertAt(posArr, val);
							size++;
							return;
						}
						else if (current->isFull())
						{
							Node *tempNode = new Node(nodeSize);
							numOfNodes++;

							for (int i = current->getHalfNodeSize(); i < nodeSize; i++)
							{
								tempNode->add(current->elements[i]);
								current->elements[i] = NULL;


							}
							current->numElements = current->getHalfNodeSize();

							if (posArr < current->getHalfNodeSize())
							{
								current->insertAt(posArr, val);
								size++;
							}
							else
							{
								if (nodeSize % 2 == 0)
								{
									current->insertAt(posArr, val);
									size++;
								}
								else
								{
									posNext = posArr - current->getHalfNodeSize();
									tempNode->insertAt(posNext, val);
									size++;
								}

							}
							tempNode->next = current->next;
							current->next = tempNode;
							tempNode->prev = current->next;
							tempNode->next->prev = tempNode->next;
							current = tempNode;
							return;


							

						}
					}
					index++;
				}
				count = count + current->numElements;
				current = current->next;
			}
		}
	}
}

void UnrolledLinkedList::deleteAt(int pos)
{
	if (pos < 0 || pos >= size)
		throw "IndexOutOfBoundsException"; // check whether pos is valid or not
										   // TODO
	/*else
	{
		if (head == NULL)
			return;*/
	//	else
	//	{
	//		int index = 0;
	//		int posArr = 0;// vi tri trong mang
	//		int count = 0; // tong so element cua node truoc
	//		int j = 0;// bien dem chuyen phan tu node sau ra node truoc
	//		Node *current = head;

	//		while (current)
	//		{
	//			for (int i = 0; i < current->numElements; i++)
	//			{
	//				if (index == pos)
	//				{
	//					posArr = pos - count;

	//					current->removeAt(posArr);
	//					size--;

	//					while (current->numElements < current->getHalfNodeSize())
	//					{

	//					}
	//					if (current->next->numElements < current->next->getHalfNodeSize())
	//					{

	//					}
	//					if (current->numElements < current->getHalfNodeSize())
	//					{

	//						if (current->next->numElements > current->next->getHalfNodeSize())
	//						{
	//							current->numElements++;
	//							current->elements[2] = current->next->elements[0];
	//							current->elements[current->getHalfNodeSize() - 1] = current->next->elements[0];
	//							current->next->removeAt(0);

	//							current->next->numElements--;


	//						}
	//						else
	//						{
	//							for (int i = current->getHalfNodeSize(); i < nodeSize; i++)
	//							{
	//								current->numElements++;
	//								current->elements[current->getHalfNodeSize() - 1] = current->next->elements[j];

	//								current->next->removeAt(j);
	//								j++;


	//							}
	//							current->next = current->next->next;
	//							current->next->prev = current;
	//							delete current->next;

	//						}
	//					}



	//				}
	//				index++;
	//			}
	//			count = count + current->numElements;
	//			current = current->next;
	//		}
	//		return;
	//	}
	//}
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

	/*Node *current = tail;
	
	while (current)
	{
		for (int i = current->numElements; i > 0 ; i--)
		{
			if (current->elements[i] == val)
			{
				return index;
			}
			index++;
		}

		current = current->prev;
	}
	return -1;*/
	Node *current;
	
	for (current = head; current != NULL; current = current->next)
	{
		for (int i = 0; i < current->numElements; i++)
		{
			index++;
		}
	}
	 // printf("index = %d\n");
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
	return -1;

	//Node *count;
	//for (count = tail; count != NULL; count = count->prev)
	//{
	//	for (int i = 0; i < count->numElements; i++)
	//		index++;
	//}
	//// std::cout << "Index = " << index << "\n";*/
	//for (count = head; count != NULL; count = count->next)
	//{
	//	for (int i = 0; i < count->numElements; i++)
	//	{
	//		index--;
	//		if (count->elements[i] == val)
	//		{
	//			return index;
	//		}
	//	}
	//}
	//return -1;
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
// reverse con bug
// 
void UnrolledLinkedList::reverse() 
{
	// TODO
	Node *current = head;
	Node *pre = NULL, *nex = NULL;


	while (current != NULL)
	{
		current->reverse();
		nex = current->next;
		current->next = pre;
		pre = current;
		current = nex;

		/*next = current->next;
		current->next = prev;
		prev = current;
		current->prev = next;
		current = next;*/
		/*prev = current->prev;
		next = current->next;
		current->next = prev;
		current->prev = next;
		current = next;*/
	}
	head = pre;
	head->prev = NULL;
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