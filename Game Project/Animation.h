#ifndef Animation_h
#define Animation_h

struct Animation
{
    int frames;
    int speed;
    int width;
    int height;
    SDL_Texture* sprite;
    
    Animation(){}
    Animation(int w, int h, int f, int s, const char* path)
    {
        width = w;
        height = h;
        frames = f;
        speed = s;
        sprite = TextureManager::loadTexture(path);
    }
};


#endif /* Animation_h */
