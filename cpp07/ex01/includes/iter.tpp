/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:47:22 by jodde             #+#    #+#             */
/*   Updated: 2026/05/25 14:47:38 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void    iter(T* array, size_t const arrayLength, void (*f)(T&, bool arrayEnd))
{
    bool arrayEnd = false;
    if (!array || !f)
        return;
    for (size_t i = 0; i < arrayLength; i++)
    {
        if (i == arrayLength - 1)
            arrayEnd = true;
        f(array[i], arrayEnd);
    }
}

template <typename T>
void    iter( T const* array, size_t const arrayLength, void (*f)(T const&, bool arrayEnd))
{
    bool arrayEnd = false;
    if (!array || !f)
        return;
    for (size_t i = 0; i < arrayLength; i++)
    {
        if (i == arrayLength - 1)
            arrayEnd = true;
        f(array[i], arrayEnd);
    }
}
