#include "stdafx.h"

#include "camera.h"

Camera* Camera::mainCamera = NULL;

Camera* Camera::getMain()
{
  return mainCamera;
}

void Camera::setMain(Camera* camera)
{
  mainCamera = camera;
}

Camera::Camera()
{
  zoom = 1;

  pos.x = 0;
  pos.y = 0;
}

Point Camera::getPos()
{
  return pos;
}

void Camera::setPos(Point p)
{
  pos = p;
}

Point Camera::screenToWorld(Point p)
{
  Point ret = p;
  ret.x += pos.x;
  ret.y += pos.y;

  return ret;
}

Point Camera::worldToScreen(Point p)
{
  Point ret = p;
  ret.x -= pos.x;
  ret.y -= pos.y;

  return ret;
}

Rect Camera::worldToScreenRect(Rect rect)
{
  Rect ret;
  ret.w = rect.w*zoom;
  ret.h = rect.h*zoom;
  ret.x = (rect.x - pos.x)*zoom;
  ret.y = (rect.y - pos.y)*zoom;

  return ret;
}

void Camera::zoomIn(float d)
{
  zoom += d;
}

void Camera::zoomOut(float d)
{
  zoom -= d;
}
