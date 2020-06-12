#pragma once

#include "gizmo.h"

#include <vector>

namespace Zengine{

class Group:public Gizmo{
public:
	Group();
	virtual ~Group();

	virtual void destroy();
	virtual void update();
	virtual void draw();
	virtual void kill();

	int indexOf(Gizmo* g);
	Gizmo* add(Gizmo* g);
	Gizmo* erase(Gizmo* g);
	Gizmo* remove(Gizmo* g, bool autoDel=false);
public:

protected:
	std::vector<Gizmo*> _members;
	std::vector<Gizmo*> _toDel;
};
}
