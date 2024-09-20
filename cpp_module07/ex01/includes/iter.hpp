/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:43:27 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/02 08:43:44 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>

template <typename T>
void iter(T* array, size_t len, void f(const T& item)) {
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}