#include <iostream>
#include <string>
#include <optional>
#include <cassert>

#ifndef _STACK_H_
#define _STACK_H_
//-------------------------------------------------------------------------------------------------
template <typename Type>
class Stack
{
private:
	struct Node
	{
		Type Element;
		Node* next = nullptr;
	};
	size_t count;
	Node* tail;
public:
	Stack();
	Stack(const Stack & stk);
	Stack(Stack && stk);
	Stack & operator = (const Stack & stk);
	Stack & operator = (Stack && stk);
	~Stack();
	
	template <typename Type>
	friend std::ostream & operator << (std::ostream & os, const Stack & stk);

	void push(Type val);
	void pop();
	bool empty() const;
	void show() const;
	std::optional<Type> top() const;
	size_t size() const;
};
//-------------------------------------------------------------------------------------------------
template <typename Type>
Stack<Type>::Stack() : count(0), tail(nullptr)
{

}
//-------------------------------------------------------------------------------------------------
template <typename Type>
Stack<Type>::Stack(const Stack & stk) : count(stk.count), tail(nullptr)
{
	Node **pnext = &tail;
	for (const Node* n_ptr = stk.tail; n_ptr != nullptr; n_ptr = n_ptr->next)
	{
		Node* n_ptr_new = new Node(*n_ptr);
		*pnext = n_ptr_new;
		pnext = &n_ptr_new->next;
	}
	*pnext = nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
Stack<Type>::Stack(Stack && stk) : count(stk.count), tail(stk.tail)
{
	stk.count = 0;
	stk.tail = nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
Stack<Type> & Stack<Type>::operator = (const Stack & stk)
{
	if (this == &stk)
	{
		return *this;
	}

	Stack copy(stk);
	std::swap(tail, copy.tail);
	std::swap(count, copy.count);

	return *this;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
Stack<Type> & Stack<Type>::operator = (Stack && stk)
{
	if (this == &stk)
	{
		return *this;
	}

	std::swap(tail, stk.tail);
	std::swap(count, stk.count);

	return *this;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
Stack<Type>::~Stack()
{
	while (tail)
	{
		Node* n_ptr = tail;
		tail = tail->next;
		delete n_ptr;
	}
	count = 0;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void Stack<Type>::push(Type val)
{
	Node* n_ptr = new Node;
	n_ptr->Element = val;
	count++;
	n_ptr->next = tail;
	tail = n_ptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void Stack<Type>::pop()
{
	Node* n_ptr = tail;
	tail = tail->next;
	count--;
	delete n_ptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void Stack<Type>::show() const
{
	if (empty())
	{
		std::cout << "Stack is empty! \n";
	}
	else
	{
		for (const Node* ptr = tail; ptr != nullptr; ptr = ptr->next)
		{
			std::cout << ptr->Element << '\n';
		}
	}
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
std::optional<Type> Stack<Type>::top() const
{
	if (!empty())
	{
		return tail->Element;
	}
	return std::nullopt;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
size_t Stack<Type>::size() const
{
	return count;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
bool Stack<Type>::empty() const
{
	return tail == nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
std::ostream & operator << (std::ostream & os, const Stack<Type> & stk)
{
	stk.show();
	return os;
}
//-------------------------------------------------------------------------------------------------
#endif // STACK_H_