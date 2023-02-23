#include "/home/xuananle/Documents/Chicken-Invaders-Part1/include/BaseObject.h"
// Implement Constructor and Destructor
BaseObject::BaseObject()
{
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}
BaseObject::~BaseObject(){}

// Implement Static IMG
void BaseObject::load_static_img(const char *file)
{
    p_object_ = Load_IMG(file);
    if(p_object_ == NULL)
    {
        std::cout << "Failed to load IMG" << std::endl;
        exit(0);
    }
}
// Implement Set and Get method with the Rectangle
void BaseObject::set_rect_cordinate(const int &x, const int &y)
{
    rect_.x = x;
    rect_.y = y;
}
void BaseObject::set_rect_cordinate_and_width_height(const int &x, const int &y, const int &width, const int &height)
{
    rect_.x = x;
    rect_.y = y;
    rect_.w = width;
    rect_.h = height;
}
void BaseObject::set_width_height(const int &width, const int &height)
{
    rect_.w = width;
    rect_.h = height;
}
SDL_Rect BaseObject::get_rect() const
{
    return rect_;
}
void BaseObject::free()
{
    if (p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}
// Render IMG
void BaseObject::render_static_image()
{
    SDL_Rect RenderQuad = rect_;
    SDL_RenderCopy(renderer, p_object_, nullptr, &rect_);
}
void BaseObject::render_static_image_with_scale(const double &scale)
{
    SDL_Rect RenderQuad;
    RenderQuad.x = rect_.x;
    RenderQuad.y = rect_.y;
    RenderQuad.w = static_cast<int> (rect_.w * scale);
    RenderQuad.h = static_cast<int> (rect_.h * scale);
    SDL_RenderCopy(renderer, p_object_, nullptr, &RenderQuad);
}