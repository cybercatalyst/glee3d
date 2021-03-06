///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    This file is part of glee3d.                                           //
//    Copyright (C) 2012-2015 Jacob Dawid, jacob.dawid@omg-it.works          //
//                                                                           //
//    glee3d is free software: you can redistribute it and/or modify         //
//    it under the terms of the GNU General Public License as published by   //
//    the Free Software Foundation, either version 3 of the License, or      //
//    (at your option) any later version.                                    //
//                                                                           //
//    glee3d is distributed in the hope that it will be useful,              //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of         //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          //
//    GNU General Public License for more details.                           //
//                                                                           //
//    You should have received a copy of the GNU General Public License      //
//    along with glee3d.  If not, see <http://www.gnu.org/licenses/>.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef G3D_FRAMEBUFFER_H
#define G3D_FRAMEBUFFER_H

// Own includes
#include "g3d_rgbacolor.h"
#include "g3d_logging.h"

// Qt includes
#include <QGLWidget>

namespace Glee3D {
/**
  * @class FrameBuffer
  * @author Jacob Dawid (jacob.dawid@omg-it.works)
  * @date 02.12.2012
  * Makes it easier to handle framebuffers by hiding a lot of OpenGL's
  * details in a single object. The term "target" describes a render target.
  * OpenGL can have a single render target at a time. All operations act on the
  * current render target.
  *
  * Framebuffers are memory targets that OpenGL can render to and which are
  * linked to a texture. This makes it possible to draw contents offscreen and
  * then use these contents as a texture again to draw them on another target.
  */
class FrameBuffer : public Logging {
public:
    /** @enum FrameBufferProperties */
    enum FrameBufferProperties {
        DepthBuffer         = 1 << 0,
        FloatingPointFormat = 1 << 1,
        LinearFiltering     = 1 << 2
    };

    /**
      * Creates a new frame buffer object.
      * @param width Width of the framebuffer object.
      * @param height Height of the framebuffer object.
      * @param properties Framebuffer properties.
      */
    FrameBuffer(int width,
                int height,
                int properties = FloatingPointFormat | LinearFiltering);

    /**
      * Acquires that framebuffer object as a drawing target. All
      * consecutive drawing calls to OpenGL will be directed to the
      * non-visible memory buffer until release() is called.
      * @see release()
      */
    void target();

    /** Releases that framebuffer object, defaulting to the OpenGL
      * visible memory.
      * @see acquire()
      */
    void release();

    /** Binds the framebuffer contents as a texture. */
    void bindTexture();

    /** Blits the contents of the framebuffer to the current target. */
    void copy();

    /** Clears the framebuffer object. */
    void clear();

    /** Sets the clear color. */
    void setClearColor(RgbaColor color);

    /** @returns the clear color. */
    RgbaColor clearColor();

    /** @returns the width of the framebuffer. */
    GLsizei width();

    /** @returns the height of the framebuffer. */
    GLsizei height();

    /** @returns properties of this framebuffer. */
    int properties();

private:
    int _properties;
    GLsizei _width;
    GLsizei _height;

    RgbaColor _clearColor;

    GLuint _texture;
    GLuint _depthBuffer;
    GLuint _frameBufferObject;
};

} // namespace Glee3D

#endif // G3D_FRAMEBUFFER_H
