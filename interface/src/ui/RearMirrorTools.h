//
//  RearMirrorTools.h
//  interface/src/ui
//
//  Created by Stojce Slavkovski on 10/23/2013.
//  Copyright 2013 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef hifi_RearMirrorTools_h
#define hifi_RearMirrorTools_h

#include "InterfaceConfig.h"

#include <QGLWidget>
#include <QSettings>

enum ZoomLevel {
    HEAD,
    BODY
};

class RearMirrorTools : public QObject {
    Q_OBJECT
public:
    RearMirrorTools(QGLWidget* parent, QRect& bounds, QSettings* settings);
    void render(bool fullScreen);
    bool mousePressEvent(int x, int y);
    ZoomLevel getZoomLevel() { return _zoomLevel; }
    void saveSettings(QSettings* settings);

signals:
    void closeView();
    void shrinkView();
    void resetView();
    void restoreView();
    
private:
    QGLWidget* _parent;
    QRect _bounds;
    GLuint _closeTextureId;
    GLuint _resetTextureId;
    GLuint _zoomBodyTextureId;
    GLuint _zoomHeadTextureId;
    ZoomLevel _zoomLevel;
    
    QRect _closeIconRect;
    QRect _resetIconRect;
    QRect _shrinkIconRect;
    QRect _headZoomIconRect;
    QRect _bodyZoomIconRect;
    
    bool _windowed;
    bool _fullScreen;
    
    void displayIcon(QRect bounds, QRect iconBounds, GLuint textureId, bool selected = false);
};

#endif // hifi_RearMirrorTools_h
