#include "UI_Element.h"
#include "SDL\include\SDL.h"
#include "j1App.h"
#include "j1Render.h"


class Image : public UI_Element
{

	SDL_Texture* tex;
	
public:

	Image(){}

	Image(SDL_Texture* tex, SDL_Rect* rect)
	{
		this->tex = tex;
		this->rectangle = rect;
		App->UI->elements.add(this);
	}

	void Update()
	{
		Draw();
	}

	void Draw()
	{
		App->render->Blit(tex, 10, 50, rectangle, false);
	}

};