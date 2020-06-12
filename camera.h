#pragma once

#include "util.h"

namespace Zengine{
class Camera{
public:
  Camera();
  Point getPos();
  void setPos(Point p);

  Point screenToWorld(Point p);
  Point worldToScreen(Point p);

  Rect worldToScreen(Rect rect);
  void zoomIn(float d);
  void zoomOut(float d);

  float getZoom() { return zoom; }

  static Camera* getMain();
  static void setMain(Camera* camera);
protected:
  Point pos;

  float zoom;

  static Camera* mainCamera;
};
};