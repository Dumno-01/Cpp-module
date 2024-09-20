/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:10:51 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/05 08:19:06 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : _n(0) {}

Span::~Span() {}

Span::Span(unsigned int N) : _n(N) {}

Span::Span(const Span &src) : _n(src._n), _numbers(src._numbers) {}

Span &Span::operator=(const Span &src) {
	this->_n = src._n;
	this->_numbers = src._numbers;
	return *this;
}

void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_n) {
		throw std::out_of_range("Span: addNumber: span is full");
	}
	this->_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (this->_numbers.size() < 2) {
		throw std::out_of_range("Span: shortestSpan: not enough numbers");
	}
	std::vector<int> temp = this->_numbers;
	std::sort(temp.begin(), temp.end());
	unsigned int min = std::abs(temp[0] - temp[1]);
	for (unsigned int i = 1; i < temp.size() - 1 ; i++) {
		if (std::abs(temp[i] - temp[i + 1]) < min) {
			min = std::abs(temp[i] - temp[i + 1]);
		}
	}
	return min;
}

int Span::longestSpan() const {
	if (this->_numbers.size() < 2) {
		throw std::out_of_range("Span: longestSpan: not enough numbers");
	}
	int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	return max - min;
}