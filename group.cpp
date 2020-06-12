#include "zengine.h"

#include "group.h"

using namespace Zengine;

Group::Group()
{
	_members.clear();
}

Group::~Group()
{
	this->destroy();
}

void Group::destroy()
{
	for (std::vector<Gizmo*>::iterator itr = _members.begin();
		itr != _members.end(); itr++)
	{
		Gizmo* g = *itr;
		if (g != NULL)
		{
			g->destroy();
			delete g;
		}
	}

	_members.clear();
}

void Group::update()
{
	for (int i=0; i<_members.size();i++)
	{
		Gizmo* g = _members[i];
		if (g != NULL && g->exists && g->active)
		{
			g->update();
		}
	}

	for (int i = 0; i < _toDel.size(); i++)
	{
		delete _toDel[i];
	}
	_toDel.clear();
}

void Group::draw()
{
	for (std::vector<Gizmo*>::iterator itr = _members.begin();
		itr != _members.end(); itr++)
	{
		Gizmo* g = *itr;
		if (g != NULL && g->exists && g->visible)
		{
			g->draw();
		}
	}
}

void Group::kill()
{
	for (std::vector<Gizmo*>::iterator itr = _members.begin();
		itr != _members.end(); itr++)
	{
		Gizmo* g = *itr;
		if (g != NULL && g->exists)
		{
			g->kill();
		}
	}

	Gizmo::kill();
}

Gizmo* Group::add(Gizmo* g)
{
	if (g->parent == this)
	{
		return g;
	}

	if (g->parent != NULL)
	{
		g->parent->remove(g);
	}

	for (int i = 0; i < _members.size(); i++)
	{
		if (_members[i] == NULL)
		{
			_members[i] = g;
			g->parent = this;
			return g;
		}
	}

	_members.push_back(g);
	g->parent = this;
	return g;
}

Gizmo* Group::erase(Gizmo* g)
{
	int idx = this->indexOf(g);
	if (idx != -1)
	{
		_members[idx] = NULL;
		g->parent = NULL;
		return g;
	}

	return NULL;
}


Gizmo* Group::remove(Gizmo* g, bool autoDel/* = false*/)
{
	for (std::vector<Gizmo*>::iterator itr = _members.begin();
		itr != _members.end(); itr++)
	{
		if (g != NULL && g == *itr)
		{
			_members.erase(itr);
			g->parent = NULL;
			if (autoDel) _toDel.push_back(g);
			return g;
		}
	}
	return NULL;
}

int Group::indexOf(Gizmo* g)
{
	int idx = 0;
	for (std::vector<Gizmo*>::iterator itr = _members.begin();
		itr != _members.end(); itr++, idx++)
	{
		if (g != NULL && g == *itr)
		{
			return idx;
		}
	}
	return -1;
}