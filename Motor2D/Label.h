
#include "p2SString.h"
#include "j1Fonts.h"
#include "UI_Element.h"

#ifndef __LABEL_H__
#define __LABEL_H_

class Label : public UI_Element
{
	p2SString Text;
	uint MaxSize;
	//Image texture;
	j1Fonts* font;
	SDL_Color color;
	_TTF_Font* f;

public:

	Label(){}

	Label(p2SString t) : MaxSize(14)
	{
		Text = t;
		f = App->font->Load(DEFAULT_FONT, 14);
		App->UI->elements.add(this);
	}


	bool CheckUser();

	void Update()
	{
		Draw();
	}

	void Draw()
	{
		App->render->Blit(App->font->Print(Text.GetString(), { (255), (255), (255), (255) }, f), rectangle->x, rectangle->y, false, false);
	}

};

#endif //__LABEL_H__