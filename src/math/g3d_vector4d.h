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

#ifndef G3D_VECTOR4D_H
#define G3D_VECTOR4D_H

// Own includes
#include "io/g3d_serializable.h"

// C++ includes
#include <math.h>

namespace Glee3D {

/**
  * @class Vector4D
  * @author Jacob Dawid (jacob.dawid@omg-it.works)
  * @date 02.12.2012
  */
class Vector4D : public Serializable {
public:
    Vector4D();
    Vector4D(double x, double y, double z, double w);

    double length() const;
    Vector4D& normalize();
    Vector4D& operator= (const Vector4D& other);
    Vector4D operator* (double scalar) const;
    Vector4D operator+ (const Vector4D& other) const;
    Vector4D& operator+= (const Vector4D& other);
    Vector4D operator- (const Vector4D& other) const;
    Vector4D operator- () const ;
    Vector4D& operator-= (const Vector4D& other);

    QString className();
    QJsonObject serialize();
    bool deserialize(QJsonObject jsonObject);

    double _x;
    double _y;
    double _z;
    double _w;
};

} // namespace Glee3D

#endif // G3D_VECTOR4D_H
