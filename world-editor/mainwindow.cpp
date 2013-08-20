///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    This file is part of glee3d.                                           //
//    Copyright (C) 2012 Jacob Dawid, jacob.dawid@googlemail.com             //
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

#include "g3d_bloomeffect.h"
#include "mainwindow.h"
#include "g3d_cube.h"
#include <math.h>
#include "g3d_framebuffer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    _display = new Glee3D::Display(this);
    _display->activeCamera()->setPosition(Glee3D::RealVector3D(0.0, 10.0, -10.0));
    _display->activeCamera()->setLookAt(Glee3D::RealVector3D(0.0, 0.0, 0.0));

    _scene = new Scene(_display);
    _display->setScene(_scene);

    //Glee3D::BloomEffect *bloomEffect = new Glee3D::BloomEffect();
    //_display->appendEffect(bloomEffect);

    setCentralWidget(_display);

    resize(1024, 768);
    //showFullScreen();
    connect(_display, SIGNAL(framesPerSecond(int)), this, SLOT(showFramesPerSecond(int)));
}

MainWindow::~MainWindow() {
}

void MainWindow::showFramesPerSecond(int fps) {
    setWindowTitle(QString("Glee3D World Editor, %1 fps").arg(fps));
}
