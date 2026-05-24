/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:26:05 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 20:36:42 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Scalar.hpp"

Scalar::Scalar(){}
Scalar::Scalar(Scalar const& src){ (void)src;}
Scalar::~Scalar(){}
Scalar& Scalar::operator=(Scalar const& src){(void)src; return(*this);}

