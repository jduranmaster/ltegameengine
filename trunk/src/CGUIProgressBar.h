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
 
      #ifndef CGUIProgressBar_H
      #define CGUIProgressBar_H
      #include "IGUIProgressBar.h"
      #include "IGUISkin.h"
      #include "IGUIEnvironment.h"
      #include "IVideoDriver.h"
namespace engine {
namespace gui {
class CGUIProgressBar : public IGUIProgressBar {
public:
CGUIProgressBar(bool horizontal, bool border, bool background, IGUIEnvironment* environment, IGUIElement* parent, s32 id, core::rect<s32> rectangle);
~CGUIProgressBar();
virtual void draw();
virtual void setMax(s32 m = 100);
virtual void setPos(s32 p = 0);
virtual void setColorBack(video::SColor color = video::SColor(1, 0, 0, 0));
virtual void setColorFront(video::SColor color = video::SColor(255, 0, 0, 255));
virtual void setColorText(video::SColor color = video::SColor(255, 255, 255, 255));
virtual void setFontText(IGUIFont* font = 0);
private:
bool dHorizontal;
bool dBorder;
bool dBackground;
s32 pMax;
s32 pPos;
video::SColor cBack;
video::SColor cFront;
video::SColor cText;
IGUIFont* oFont;
};
}
}
      #endif
