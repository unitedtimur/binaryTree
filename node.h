#ifndef _NODE_H
#define _NODE_H

template<typename T> class node
{
	friend class tree<T>;
public:
	explicit node(const T & data = NULL);
	void get_data() const noexcept;
private:
	T data;
	node<T> * left,
		    * right;
};

template<typename T>
inline node<T>::node(const T & data) : 
	data(data),
	left((node*)nullptr),
	right((node*)nullptr)
	{}

template<typename T>
inline void node<T>::get_data() const noexcept
{
	return data;
}

#endif _NODE_H