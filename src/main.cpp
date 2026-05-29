#include <iostream>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "mini_physics_engine/World.h"
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

static auto particle1 = physics::Particle(1, math::Point2(WINDOW_WIDTH/2, WINDOW_HEIGHT), math::Vector2(0, -1));
static auto particle2 = physics::Particle(2, math::Point2(WINDOW_WIDTH/2, 0), math::Vector2(0, 2));
static auto world = miniPhysicsEngine::World();

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

    world.addParticle(particle1);
    world.addParticle(particle2);

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
    world.step(0.02);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    for (const auto particle : world.particles) {
        // positive y is down in
        SDL_RenderPoint(renderer, particle.position.x, WINDOW_HEIGHT - particle.position.y);
    }

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
