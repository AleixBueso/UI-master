#include "p2Point.h"
#include "p2List.h"
#include "j1Gui.h"
#include "SDL\include\SDL.h"

#ifndef __UI_ELEMENT_H__
#define __UI_ELEMENT_H__

class UI_Element 
{
	p2List<UI_Element*> childs;
	enum type_object;
	//listener i rectangle

public:

	p2List<UI_Element*> elements;
	SDL_Rect* rectangle;

	UI_Element()
	{
		rectangle = new SDL_Rect();
		rectangle->x, rectangle->y, rectangle->h, rectangle->w = 0;
	}

	void Move(int x, int y)
	{
		rectangle->x = x;
		rectangle->y = y;
	}

	virtual void Update()
	{
		for (uint i = 0; i < elements.count(); i++)
			elements.At(i)->data->Update();
	}

	bool CleanUp()
	{
		delete rectangle;
	}

	void addChild(UI_Element* child)
	{
		childs.add(child);
	}

	bool MouseCollision(p2Point<int> mouse_pos)
	{
		bool ret = false;

		if (mouse_pos.x > position.x &&
			mouse_pos.x < rect.w + position.x &&
			mouse_pos.y > position.y &&
			mouse_pos.y < rect.h + position.y)
		{
			ret = true;
		}


};

#endif // __UI_ELEMENT_H__