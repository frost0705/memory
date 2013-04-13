#include <iostream>
using namespace std;
/**
@class list

@param element contain int and pointer to next element
@param head head of list
*/
class list
{
private:
	struct element
	{
		int a;
		element* next;
	};

	element head;

public:
	///constructor
	list(int a)
	{
		
		head.a = a;
		head.next = NULL;
	};
	///add elelment in n position
	int add_element_n(int a, int n)
	{
		if (n < 1)
		{
			return 0;
		}
		element b;
		b.a = a;
		if (n == 1)
		{
			b.next = &head;
			head = b;
			return 1;
		}
		else
		{
			element *b = new element;
			b->a = a;
			element *temp = &head;

			for (int i = 1; ((temp->next != NULL)&&(i < n)); temp = temp->next){}
		
			if (temp->next != NULL)
			{
				return 0;
			}
		
			b->next = (temp->next);
			temp->next = b;
		
			return 1;
		}
	};
	///add element to end of list
	int add_element_to_end(int a)
	{
		element *b = new element;
		b->a = a;
		element *temp = &head;

		for (; (temp->next != NULL); temp = temp->next){}
		
		
		b->next = (temp->next);
		temp->next = b;
		
		return 1;
	};
	///add elelment in n position
	int delete_element_n(int n)
	{
		if (n < 1)
		{
			return 0;
		}
		else
		{
			
			element *temp = &head;
			element *temp2;

			for (; (temp->next != NULL); temp = temp->next){}

			temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			return 1;
		}
	};

};
/**
@class stack

@param *s array
@param n position of cursor
@param size size of stack
*/
class stack
{
private:
	int *s, n, size;

public:
	///constuctor
	stack(int stack_size)
	{
		size = stack_size;
		s = new int[stack_size];
		n = 0;
	};
	///destructor
	~stack()
	{
		delete s;
		n = 0;
		size = 0;
	};
	///Put element in stack. overload - return 0
	int put(int a)
	{
		if (n != (size-1))
		{
			s[n] = a;
			n++;
			return 1;
		}
		else
		{
			return 0;
		}
	};
	///read from stack. empty - return -2147483648
	int read()
	{
		if (n >= 0)
		{
			n--;
			return s[n];
		}
		else
		{
			return -2147483648;
		}

	};
};
/**
@class stack

@param *s array
@param size size of stack
@param left - first in round
@param right - last in round
*/
class round
{
private:

	int *s, size, left, right;

public:
	///constructor
	round(int a)
	{
		size = a;
		s = new int[size];
		left = 0;
		right = 0;
	};
	///destructor
	~round()
	{
		delete s;
		left = 0;
		right = 0;
		size = 0;
	};
	///add element. overload - return 0
	int add(int a)
	{
		s[right] = a;
		right++;
		if (right == size)
		{
			right = 0;
		}
		if (right == left)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	};
	///get element. empty - return -2147483648
	int read()
	{
		if (right == left)
		{
			return -2147483648;
		}
		else
		{
			int answer = s[left] ;
			left++;
			if (left == size);
			{
				left = 0;
			}
			
			return answer;
		}
	};

};



void main()
{
	
}

