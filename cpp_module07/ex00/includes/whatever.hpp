/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffreze <ffreze@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:36:22 by ffreze            #+#    #+#             */
/*   Updated: 2024/09/02 08:36:50 by ffreze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T & x, T & y) {
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T & min(T & x, T & y) {
	return x < y ? x : y;
}

template <typename T>
T & max(T & x, T & y) {
	return x > y ? x : y;
}