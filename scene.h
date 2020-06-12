#pragma once

#include "group.h"
#include "camera.h"

namespace Zengine{
class Scene:public Group{
public:
	Scene();
	~Scene();

	virtual void init(){};
	virtual void pause(){};
	virtual void resume(){}

	virtual Camera* camera() 
	{
		return Camera::getMain();
	}

	virtual void onBackPressed(){}
	virtual void onMenuPressed(){}
};
}
