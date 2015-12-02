#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2Point.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes
class Image;
class Label;

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions
	Image* CreateImage(SDL_Texture* tex, SDL_Rect* rect);
	Label* CreateLabel(p2SString text, int x, int y);

	bool Event();


	const SDL_Texture* GetAtlas() const;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;

public:
	p2List<Image*> images;
	p2List<Label*> labels;
	Image* image;
	Label* label;

};

#endif // __j1GUI_H__