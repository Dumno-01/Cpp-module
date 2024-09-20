/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:43:27 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/02 08:45:30 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
class Array {
public:
	Array(): _array(new T()), _arraySize(0) {};
	Array(unsigned int n): _arraySize(n) {
		this->_array = new T[n];
	};

	~Array() {
		delete[] _array;
	}

	Array(Array const & src): _arraySize(src.size()) {
		this->_array = new T[src.size()];
		for (unsigned int i = 0 ; i < this->_arraySize; i++) {
			this->_array[i] = src._array[i];
		}
	};

	Array & operator=(Array const & src) {
		if (this != &src) {
			this->_arraySize = src.size();
			delete _array;
			this->_array = new T[_arraySize];
			for (unsigned int i = 0 ; i < this->_arraySize; i++) {
				this->_array[i] = src._array[i];
			}
		}
		return *this;
	}

	T & operator[](unsigned int index) const {
		if (index >= _arraySize) {
			throw std::out_of_range("Index is out of range");
		}

		return _array[index];
	}

	unsigned int size() const {
		return this->_arraySize;
	}

private:
	unsigned int	_arraySize;
	T*				_array;
};

template <typename T>
std::ostream & operator<<(std::ostream & out, const Array<T> & arr) {
	for (unsigned int i = 0; i < arr.size(); i++) {
		out << arr[i] << " ";
	}
	return out;
}