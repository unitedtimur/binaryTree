/*
*
* by UnitedTimur (c) 2019
*
*/

#ifndef _TREE_H
#define _TREE_H

template<typename T> class tree;

#include "node.h"

#define forever for(;;) 

#include <iostream>
#include <fstream>

template<typename T> class tree
{
public:
	explicit tree();
	~tree();

	void add_node(const T & data) const noexcept;
	void add_node(const std::string & file_name) noexcept;
	bool delete_node(const T & data) noexcept;
	void delete_tree(node<T> * obj) noexcept;
	void print_tree_LRD(node<T> * obj = (node<T>*)nullptr) const noexcept;
	void print_tree_RLD(node<T> * obj = (node<T>*)nullptr) const noexcept;
	void print_tree_BRD(node<T> * obj = (node<T>*)nullptr) const noexcept;
	node<T> * find_data(const T & data) const noexcept;
	node<T> * find_max() const noexcept;
	node<T> * find_min() const noexcept;
	size_t height(const node<T> * obj = (node<T>*)nullptr) const noexcept;

private:
	node<T> * root;
};

template<typename T>
inline tree<T>::tree() : root(new node<T>) {}

template<typename T>
inline tree<T>::~tree()
{
	delete_tree(root);
}

template<typename T>
inline void tree<T>::add_node(const T & data) const noexcept
{
	node<T> * obj = root;

	forever
	{
		if (data > obj->data)
		{
			if (obj->right != nullptr)
			{
				obj = obj->right;
			}
			else
			{
				obj->right = new node<T>(data);
				break;
			}

		}
		else
		{
			if (obj->left != nullptr)
			{
				obj = obj->left;
			}
			else
			{
				obj->left = new node<T>(data);
				break;
			}
		}
	}
}

template<typename T>
inline void tree<T>::add_node(const std::string & file_name) noexcept
{
	std::fstream file(file_name, ios_base::in);

	if (file.is_open())
	{
		T tmp = NULL;

		while (!file.eof())
		{
			file >> tmp;

			add_node(tmp);
		}

		file.close();
	}
}

template<typename T>
inline bool tree<T>::delete_node(const T & data) noexcept
{
	node<T> * obj = root;

	forever
	{
		if (data > obj->data)
		{
			if (obj->right)
			{
				if (obj->right->data == data)
				{
					node<T> * rptr = obj->right->right;
					node<T> * ptr = obj->right->left;

					delete obj->right;

					if (ptr)
					{
						obj->right = ptr;
						for (; ptr->right; ptr = ptr->right);
						ptr->right = rptr;
					}
					else
					{
						obj->right = rptr;
					}
					break;
				}
				else
				{
					obj = obj->right;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (obj->left)
			{
				if (obj->left->data == data)
				{
					node<T> * lptr = obj->left->left;
					node<T> * ptr = obj->left->right;

					delete obj->left;

					if (ptr)
					{
						obj->left = ptr;
						for (; ptr->left; ptr = ptr->left);
						ptr->left = lptr;
					}
					else
					{
						obj->left = lptr;
					}
					break;
				}
				else
				{
					obj = obj->left;
				}
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

template<typename T>
inline void tree<T>::delete_tree(node<T> * obj) noexcept
{
	if (obj->left)
	{
		delete_tree(obj->left);
	}

	if (obj->right)
	{
		delete_tree(obj->right);
	}

	delete obj;
}

template<typename T>
inline void tree<T>::print_tree_LRD(node<T> * obj) const noexcept
{
	if (obj == nullptr)
	{
		obj = root;
	}

	if(obj->left) 
	{
		print_tree_LRD(obj->left);
	}

	if (obj->right)
	{
		print_tree_LRD(obj->right);
	}
	
	std::cout << obj->data << " ";
}

template<typename T>
inline void tree<T>::print_tree_RLD(node<T> * obj) const noexcept
{
	if (obj == nullptr)
	{
		obj = root;
	}

	std::cout << obj->data << " ";

	if (obj->left)
	{
		print_tree_RLD(obj->left);
	}

	if (obj->right)
	{
		print_tree_RLD(obj->right);
	}
}

template<typename T>
inline void tree<T>::print_tree_BRD(node<T> * obj) const noexcept
{
	if (obj == nullptr)
	{
		obj = root;
	}

	if (obj->left)
	{
		print_tree_BRD(obj->left);
	}

	std::cout << obj->data << " ";

	if (obj->right)
	{
		print_tree_BRD(obj->right);
	}
}

template<typename T>
inline node<T>* tree<T>::find_data(const T & data) const noexcept
{
	node<T> * obj = root;

	forever
	{
		if (obj->data == data)
		{
			return obj;
		}

		if (data > obj->data)
		{
			obj = obj->right;

			if (obj)
			{
				if (obj->data == data)
				{
					return obj;
				}
			}
			else
			{
				return nullptr;
			}
		}
		else
		{
			obj = obj->left;

			if (obj)
			{
				if (obj->data == data)
				{
					return obj;
				}
				else
				{
					return nullptr;
				}
			}
		}
	}
}

template<typename T>
inline node<T>* tree<T>::find_max() const noexcept
{
	node<T> * obj = root;

	if (obj == nullptr)
	{
		return nullptr;
	}

	while (obj->right != nullptr)
	{
		obj = obj->right;
	}

	std::cout << "//max " << obj->data << std::endl;

	return obj;
}

template<typename T>
inline node<T>* tree<T>::find_min() const noexcept
{
	node<T> * obj = root;

	if (obj == nullptr)
	{
		return nullptr;
	}

	while (obj->left != nullptr)
	{
		obj = obj->left;
	}

	std::cout << "//min " << obj->data << std::endl;

	return obj;
}

template<typename T>
inline size_t tree<T>::height(const node<T> * obj) const noexcept
{
	if (obj == nullptr)
	{
		obj = root;
	}

	long long height_left, 
		      height_right;

	if (obj->left != nullptr)
	{
		height_left = height(obj->left);
	}
	else
	{
		height_left = -1;
	}

	if (obj->right != nullptr)
	{
		height_right = height(obj->right);
	}
	else
	{
		height_right = -1;
	}

	return (height_left > height_right ? height_left : height_right) + 1;
}

#endif _TREE_H

