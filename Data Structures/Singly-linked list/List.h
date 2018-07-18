#include <iostream>
#include <optional>

#ifndef _List_H_
#define _List_H_
//-------------------------------------------------------------------------------------------------
template <typename Type>
class List
{
private:
	struct Node
	{
		Type element = {};
		Node* next = nullptr;
	};
	size_t count;
	Node* head;
	Node* tail;
public:
	List();
	List(const List & lst);
	List(List && lst);
	List & operator = (const List & lst);
	List & operator = (List && lst);
	~List();

	template <typename Type>
	friend std::ostream & operator << (std::ostream & os, const List & lst);

	void push_front(const Type & tp);
	void push_back(const Type & tp);
	void push_pos(const Type & tp, const size_t & pos);

	void pop_front();
	void pop_back();
	void pop_pos(const size_t & pos);
	
	bool empty() const;
	const std::optional<Type> & front() const;
	const std::optional<Type> & back() const;

	void show() const;
};
//-------------------------------------------------------------------------------------------------
template <typename Type>
List<Type>::List() : count(0), head(nullptr), tail(nullptr)
{

}
//-------------------------------------------------------------------------------------------------
template <typename Type>
List<Type>::List(const List & lst) : count(lst.count), head(nullptr), tail(nullptr)
{
	for (const Node* n_ptr = lst.head; n_ptr != nullptr; n_ptr = n_ptr->next)
	{
		Node* n_ptr_new = new Node;
		n_ptr_new->element = n_ptr->element;
		if (head == nullptr && tail == nullptr)
		{
			head = n_ptr_new;
			tail = head;
		}
		else
		{
			tail->next = n_ptr_new;
			tail = n_ptr_new;
		}
	}
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
List<Type>::List(List && lst) : count(lst.count), head(lst.head), tail(lst.tail)
{
	lst.count = 0;
	lst.head = nullptr;
	lst.tail = nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
List<Type> & List<Type>::operator = (const List & lst)
{
	if (this == &lst)
	{
		return *this;
	}
	
	List tmp(lst);
	std::swap(count, tmp.count);
	std::swap(head, tmp.head);
	std::swap(tail, tmp.tail);
	return *this;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
List<Type> & List<Type>::operator = (List && lst)
{
	if (this == &lst)
	{
		return *this;
	}

	std::swap(count, lst.count);
	std::swap(head, lst.head);
	std::swap(tail, lst.tail);
	return *this;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
List<Type>::~List()
{
	while (head)
	{
		Node* n_ptr = head;
		head = head->next;
		delete n_ptr;
	}
	count = 0;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void List<Type>::push_front(const Type & tp)
{
	Node* n_ptr_new = new Node;
	n_ptr_new->element = tp;
	if (head == nullptr && tail == nullptr)
	{
		head = n_ptr_new;
		tail = head;
		n_ptr_new = nullptr;
	}
	else
	{
		n_ptr_new->next = head;
		head = n_ptr_new;
	}
	++count;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void List<Type>::push_back(const Type & tp)
{
	Node* n_ptr_new = new Node;
	n_ptr_new->element = tp;
	if (head == nullptr && tail == nullptr)
	{
		head = n_ptr_new;
		tail = head;
		n_ptr_new = nullptr;
	}
	else
	{
		tail->next = n_ptr_new;
		tail = n_ptr_new;
	}
	++count;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void List<Type>::push_pos(const Type & tp, const size_t & pos)
{
	if (empty())
	{
		push_front(tp);
		return;
	}
	
	Node* n_ptr_new = new Node;
	n_ptr_new->element = tp;

	for (size_t i = 0; i < pos; ++i)
	{
		head = head->next;
	}

	//Node* n_ptr_old = head;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void List<Type>::pop_front()
{
	if (empty())
	{
		throw std::out_of_range("Can't pop from empty list");
	}
	
	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node* n_ptr = head;
	head = head->next;
	--count;
	delete n_ptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void List<Type>::pop_back()
{
	if (empty())
	{
		throw std::out_of_range("Can't pop from empty list");
	}

	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node* n_ptr = head;
	while (n_ptr->next != tail)
	{
		n_ptr = n_ptr->next;
	}
	--count;
	delete tail;

	tail = n_ptr;
	tail->next = nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void List<Type>::pop_pos(const size_t & pos)
{
	if (empty())
	{
		throw std::out_of_range("Can't pop from empty list");
	}

	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
bool List<Type>::empty() const
{
	return head == nullptr;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
const std::optional<Type> & List<Type>::front() const
{
	if (empty())
	{
		return std::nullopt;
	}
	return head->element;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
const std::optional<Type> & List<Type>::back() const
{
	if (empty())
	{
		return std::nullopt;
	}
	return tail->element;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
std::ostream & operator << (std::ostream & os, const List<Type> & lst)
{
	
	return os;
}
//-------------------------------------------------------------------------------------------------
template <typename Type>
void List<Type>::show() const
{
	if (empty())
	{
		std::cout << "Stack is empty! \n";
	}
	else
	{
		for (const Node* ptr = head; ptr != nullptr; ptr = ptr->next)
		{
			std::cout << ptr->element << '\n';
		}
	}
}
//-------------------------------------------------------------------------------------------------
#endif // _List_H_