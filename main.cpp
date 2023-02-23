#include <iostream>
#include "/home/xuananle/Documents/Chicken-Invaders-Part1/include/BaseObject.h"
#include "/home/xuananle/Documents/Chicken-Invaders-Part1/include/CommonFunctionAndVarible.h"
// INIT DATA AND ESCAPE IF FAIL
bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;
    if (window == NULL)
    {
        std::cout << "Cannot Create Window"
                  << "\n";
        return false;
    }
    if (renderer == NULL)
    {
        std::cout << "Cannot Create Renderer"
                  << "\n";
        return false;
    }
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) && imgFlags))
    {
        return false;
    }
    return success;
}
BaseObject* back_ground;

int main(int argc, char *argv[])
{

    srand(time(NULL));
    if (!InitData()) return -1;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    
    back_ground->load_static_img("");
    
    
    bool isRunning = true;
    while(isRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                isRunning = false;
                break;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                    break;
                }
            }
        }
    


    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    }
    SDL_Quit();
}