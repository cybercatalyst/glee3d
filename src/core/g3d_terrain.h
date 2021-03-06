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

#ifndef G3D_TERRAIN_H
#define G3D_TERRAIN_H

// Own includes
#include "g3d_entity.h"

// Qt includes
#include <QString>
#include <QHash>
#include <QPair>

namespace Glee3D {
    /**
      * @class Terrain
      * @author Jacob Dawid (jacob.dawid@omg-it.works)
      * @date 18.08.2013
      */
    class Terrain :
        public Anchored,
        public Renderable,
        public Texturizable,
        public Serializable {
    public:
        enum Encoding {
            RedComponent,
            GreenComponent,
            BlueComponent
        };

        enum Result {
            Ok,
            FileLoadError,
            InvalidImageSize
        };

        explicit Terrain();
        virtual ~Terrain();

        Result generate(QString fileName,
                        Encoding heightEncoding = RedComponent,
                        Encoding textureEncoding = GreenComponent);
        Result generate(QImage image,
                        Encoding heightEncoding = RedComponent,
                        Encoding textureEncoding = GreenComponent);

        void setTilingOffset(double tilingOffset);
        void setScale(double scale);

        double scale();
        int width();
        int height();

        void render(RenderMode renderMode = Textured);

        QString className();
        QJsonObject serialize();
        bool deserialize(QJsonObject json);

    protected:

    private:
        void allocateMemory();
        void freeMemory();

        double _scale;
        QHash<QPair<int, int>, double> _terrain;
        QHash<QPair<int, int>, int> _tileIDs;
        QHash<QPair<int, int>, Vector3D> _normals;
        double _tilingOffset;
        int _width;
        int _height;

        double *_vertexBuffer;
        double *_textureCoordinatesBuffer;
        double *_normalsBuffer;
    };
} // namespace Glee3D

#endif // G3D_TERRAIN_H
