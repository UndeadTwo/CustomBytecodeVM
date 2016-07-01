#include <string.h>
#include <math.h>

#include <SDL2/SDL.h>

#include "commandParser.h"
#include "memoryMap.h"
#include "state.h"

int main() {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow(
    "CBVM",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    400,
    400,
    SDL_WINDOW_OPENGL
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (window == NULL) { 
    printf("Could not create window: %s\n", SDL_GetError());
    return -1;
  }
  
  state MyState = createState();

  memcpy(MyState.vmMemory, &testMemoryMap, (sizeof(char) * sizeof(testMemoryMap)));

  SDL_Event e;

  while(MyState.hasExited != true) {
    //printState(MyState);
    state NewState = parseCommand(MyState);
    MyState = NewState;

    SDL_RenderClear(renderer);

    for(int i = 0; i < 32768; i++) {
      SDL_SetRenderDrawColor(renderer, MyState.vmMemory[i], MyState.vmMemory[i], MyState.vmMemory[i], 0);
      SDL_Rect rect;
      rect.x = i % 400 * 4;
      rect.y = i / 400 * 4;
      rect.w = 4;
      rect.h = 4;
      SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);

    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
        SDL_Log("Program quit after %i ticks", e.quit.timestamp);
        printf("Quitting... \n");
        break;
    }

    // SDL_Delay(100);
  }

  printState(MyState);
  
  unsigned char target[] = {0xFC, 0x7F};
  printf("Memory Target %d\n", *((short unsigned int*)&target) );
  printf("Memory at target %d\n", MyState.vmMemory[*((short unsigned int*)&target)]);

  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}