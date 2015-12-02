
#include "UI_Manager.h"
#include "Label.h"
#include "Image.h"

#ifndef __BUTTON_H__
#define __BUTTON_H__

class Button : public UI_Element
{
	unsigned int W, H;
	unsigned int Animation;
	Label Text;
	Image buttonImage;

public:
	bool Update();
	void Input();
	void Draw();

};

#endif // __BUTTON_H__