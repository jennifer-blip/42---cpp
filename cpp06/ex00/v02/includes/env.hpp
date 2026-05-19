/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:32:44 by jodde             #+#    #+#             */
/*   Updated: 2026/05/19 20:33:04 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_env
{
	enum type {
		CHAR,
		INT,
		DOUBLE,
		FLOAT,
		SPECIAL,
		INVALID
	};
	type	value;
	bool	MINFF;
	bool	MINF;
	bool	PINF;
	bool	PINFF;
	bool	NAN;
	bool	NANF;
}env;