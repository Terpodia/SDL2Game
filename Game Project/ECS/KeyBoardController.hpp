#ifndef KeyBoardController_hpp
#define KeyBoardController_hpp

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController: public Component
{
public:
    
    SpriteComponent *sprite;
    TransformComponent *transform;
    
    void init()
    {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }
    
    void update()
    {
        if(Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = -1;
                    sprite->play("Walk");
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    sprite->play("Walk");
                    sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
                    break;
                    
                case SDLK_s:
                    transform->velocity.y = 1;
                    sprite->play("Walk");
                    break;
                    
                case SDLK_d:
                    sprite->play("Walk");
                    transform->velocity.x = 1;
                    sprite->spriteFlip = SDL_FLIP_NONE;
                    break;
                    
                case SDLK_ESCAPE:
                    Game::isRunning = false;
                    break;
                    
                default:
                    break;
            }
        }
        
        if(Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = 0;
                    sprite->play("Idle");
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    sprite->play("Idle");
                    break;
                    
                case SDLK_s:
                    transform->velocity.y = 0;
                    sprite->play("Idle");
                    break;
                    
                case SDLK_d:
                    transform->velocity.x = 0;
                    sprite->play("Idle");
                    
                default:
                    break;
            }

        }
       
    }
};

#endif /* KeyBoardController_hpp */
