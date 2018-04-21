#include <iostream>
#include <algorithm>
#include <cassert>
template <typename T>
class queue_t
{
private:
	struct node_t {
		node_t * next;
		T value;
	};
private:
	node_t * head;
	node_t * tail;
public:
	queue_t();
	queue_t(queue_t<T> const & other);
	~queue_t();
	void push(T value);
	T pop();
	node_t * head_() {return head;}
	node_t * tail_() {return tail;}
	queue_t & operator=(queue_t & other);
};
template <typename T>
queue_t<T>::queue_t()
{
	head=nullptr;
	tail=nullptr;
}
template <typename T>
queue_t<T>::queue_t(queue_t<T> const & other)
{
	node_t* node = other.head_();
        while(node != nullptr){
		push(node->value);
		node = node->next;
	}	
}
template <typename T>
queue_t<T>::~queue_t()
{
	while(head != nullptr){
            node_t* node = head;
            head = head->next;
            delete node;
        }
}
template <typename T>
void queue_t<T>::push(T value)
{
	if(head==nullptr)
	{
		head=new node_t;
		head->value=value;
		head->next=nullptr;
		tail=head;
	}
	else {
		tail->next=new node_t;
		tail=tail->next;
		tail->value=value;
		tail->next=nullptr;
	}
}
template <typename T>
T queue_t<T>::pop()
{
	if(head==nullptr)
	{
	throw std::logic_error("can't delete");	
	}
   	T a = head->value;
        node_t* node = head;
        head = head->next;
	if(head == nullptr){tail = nullptr;}
        delete node;
        return a;
}
template <typename T>
queue_t<T>&queue_t<T>::operator=(queue_t & other)
{
	if(other.head_() != nullptr){
		this->~queue_t();
        }
        node_t* node = other.head_();
        while(node != nullptr){
		push(node->value);
		node = node->next;
	}
        return *this;	
}
