/*
 * LTE Game Engine
 * Copyright (C) 2006-2008 SiberianSTAR <haxormail@gmail.com>
 * http://www.ltestudios.com
 *  
 * The LTE Game Engine is based on Irrlicht 1.0
 * Irrlicht Engine is Copyright (C) 2002-2006 Nikolaus Gebhardt
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */
 
#ifndef __FAST_A_TO_F_H_INCLUDED__
#define __FAST_A_TO_F_H_INCLUDED__

#include <stdlib.h>
#include <math.h>

namespace engine
{
namespace core
{

const float fast_atof_table[] = {
	0.f,
	0.1f,
	0.01f,
	0.001f,
	0.0001f,
	0.00001f,
	0.000001f,
	0.0000001f,
	0.00000001f,
	0.000000001f,
	0.0000000001f,
	0.00000000001f,
	0.000000000001f,
	0.0000000000001f,
	0.00000000000001f,
	0.000000000000001f
};

//! Provides a fast function for converting a string into a float,
//! about 6 times faster than atof in win32.
inline char* fast_atof_move(char* c, float& out)
{
	bool inv = false;
	char *t;
	float f;

	if (*c=='-')
	{
		c++;
		inv = true;
	}

	f = (float)strtol(c, &t, 10);

	c = t;

	if (*c == '.')
	{
		c++;

		float pl = (float)strtol(c, &t, 10);
		pl *= fast_atof_table[t-c];

		f += pl;

		c = t;

		if (*c == 'e')
		{
			++c;
			float exp = (float)strtol(c, &t, 10);
			f *= (float)pow(10.0f, exp);
			c = t;
		}
	}

	if (inv)
		f *= -1.0f;

	out = f;
	return c;
}

//! Provides a fast function for converting a string into a float,
//! about 6 times faster than atof in win32.
inline const char* fast_atof_move_const(const char* c, float& out)
{
	bool inv = false;
	char *t;
	float f;

	if (*c=='-')
	{
		c++;
		inv = true;
	}

	f = (float)strtol(c, &t, 10);

	c = t;

	if (*c == '.')
	{
		c++;

		float pl = (float)strtol(c, &t, 10);
		pl *= fast_atof_table[t-c];

		f += pl;

		c = t;

		if (*c == 'e')
		{
			++c;
			f32 exp = (f32)strtol(c, &t, 10);
			f *= (f32)powf(10.0f, exp);
			c = t;
		}
	}

	if (inv)
		f *= -1.0f;

	out = f;
	return c;
}


inline float fast_atof(const char* c)
{
	float ret;
	fast_atof_move_const(c, ret);
	return ret;
}

} // end namespace core
} // end namespace irr

#endif

