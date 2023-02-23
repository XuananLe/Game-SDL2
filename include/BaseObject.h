#include "/home/xuananle/Documents/Chicken-Invaders-Part1/include/CommonFunctionAndVarible.h"
#ifndef BASEOBJECT_H
#define BASEOBJECT_H
class BaseObject
{
protected:
SDL_Texture *p_object_;
SDL_Rect rect_;
public:
// CONSTRUCTOR AND DESTRUCTOR
BaseObject();
~BaseObject();

// Set and Get method with the Rectangle // 
void set_rect_cordinate(const int &x, const int &y);
void set_rect_cordinate_and_width_height(const int &x, const int &y, const int& width, const int &height);
void set_width_height(const int &width, const int &height);
SDL_Rect get_rect() const;
 
// Load Static IMG
void load_static_img(const char *file);
// Render Static Image
void render_static_image();
void render_static_image_with_scale(const double &scale);
// Free Function
void free();
};
#endif
