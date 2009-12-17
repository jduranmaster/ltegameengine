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
 
#include "CParticleFadeOutAffector.h"
#include "os.h"

namespace engine
{
namespace scene
{

//! constructor
CParticleFadeOutAffector::CParticleFadeOutAffector(
        video::SColor targetColor, u32 fadeOutTime)
	: TargetColor(targetColor)
{
	FadeOutTime = fadeOutTime ? (f32)fadeOutTime : 1.0f;
}


//! Affects an array of particles.
void CParticleFadeOutAffector::affect(u32 now, SParticle* particlearray, u32 count)
{
	f32 d;

	for (u32 i=0; i<count; ++i)
		if (particlearray[i].endTime - now < FadeOutTime)
		{
			d = (particlearray[i].endTime - now) / FadeOutTime;
			particlearray[i].color = particlearray[i].startColor.getInterpolated(
			        TargetColor, d);
		}
}


} // end namespace scene
} // end namespace engine

