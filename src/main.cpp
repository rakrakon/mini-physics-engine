#include <iostream>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "mini_physics_engine/WorldConstants.h"
#include "mini_physics_engine/math/Point2.h"
#include "mini_physics_engine/physics/Particle.h"


/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = nullptr;
static SDL_Renderer *renderer = nullptr;

namespace math = miniPhysicsEngine::math;
namespace physics = miniPhysicsEngine::physics;


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

static physics::Particle particle = physics::Particle(1, math::Point2(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata("Mini Physics Engine", "1.0", "com.mini_physics_engine.renderer-points");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Particle Testing", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(renderer, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    particle.applyForce(miniPhysicsEngine::GRAVITY_FORCE);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    particle.step(0.001);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    // positive y is down in
    SDL_RenderPoint(renderer, particle.position.x, WINDOW_HEIGHT - particle.position.y);

    SDL_RenderPresent(renderer);  /* put it all on the screen! */

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    /* SDL will clean up the window/renderer for us. */
}

// int main() {
//     namespace math = miniPhysicsEngine::math;
//     namespace physics = miniPhysicsEngine::physics;
//
//     physics::Particle testParticle{10};
//
//     testParticle.applyForce(miniPhysicsEngine::GRAVITY_FORCE);
//
//     for (int i = 0; i < 5; i++) {
//         testParticle.step(1);
//
//         std::cout << "Position: " << testParticle.position << "\n";
//         std::cout << "Velocity: " << testParticle.velocity << "\n";
//         std::cout << "Acceleration: " << testParticle.acceleration << "\n";
//     }
//
//     return 0;
// }
