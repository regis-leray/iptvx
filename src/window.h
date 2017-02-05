/*

   Copyright 2017   Jan Kammerath

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#ifndef	WINDOW_H
#define WINDOW_H

#include <SDL/SDL.h>

/* SDL context type */
struct sdl_context
{
    SDL_Surface *surf;
    SDL_mutex *mutex;
} typedef sdl_context;

/*
    defines the overlay data
    @param      overlay_ptr         pointer to PNG data
    @param      ready_ptr           pointer to bool indicating if ready
*/
void iptvx_window_set_overlay(void* overlay_ptr, bool* ready_ptr);

/* 
    creates the main window for this application 
    @param          width               defines width of the window
    @param          height              defines height of the window
    @param          keyDownCallback     callback func when key down event
    @param          startPlayCallback   callback func to call when playback can start
*/
int iptvx_create_window(int width, int height,void (*keyDownCallback)(int),void (*startPlayCallback)(void*));

/*
    locks the window surface and mutex
    @param          data        pointer to data
    @param          p_pixels    pointer to pixels
*/
extern void *iptvx_window_lock(void *data, void **p_pixels);

/*
    unlocks the window surface and mutex
    @param          data        pointer to data
    @param          id          picture identifier (not needed, legacy)
    @param          p_pixels    pointer to pixels
*/
extern void iptvx_window_unlock(void *data, void *id, void *const *p_pixels);

/*
    displays the window surface
    @param          data        pointer to data
    @param          id          picture identifier (not needed, legacy)
*/
extern void iptvx_window_display(void *data, void *id);

#endif