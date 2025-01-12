
#include "Header.h"

void render_background(Render_State render_state){
    unsigned int* pixel = (unsigned int*) render_state.memory;
    for(int i = 0 ; i < render_state.height ; i++){
        for(int j = 0 ; j < render_state.width ; j++){
            *pixel++ = 0xff00ff * i + 0x00ff00 * j;
        }

    }

}

void clear_screen(Render_State render_state,unsigned int color){
    unsigned int* pixel = (unsigned int*) render_state.memory;
    for(int i = 0 ; i < render_state.height ; i++){
        for(int j = 0 ; j < render_state.width ; j++){
            *pixel++ = color;
        }

    }
}

inline int clamp(int min,int val,int max){
    if(val < min) return min;
    if(val > max) return max;
    return val;
}

void draw_rect(Render_State render_state,int xs,int ys,int xe,int ye,unsigned int color){
    xs = clamp(0,xs,render_state.width);
    xe = clamp(0,xe,render_state.width);
    ys = clamp(0,ys,render_state.height);
    ye = clamp(0,ye,render_state.height);

    for(int i = xs ; i < xe ; i++){
        unsigned int* pixel = (unsigned int*) render_state.memory + xs + i * render_state.width;
        for(int j = ys ; j < ye ; j++){
            *pixel++ = color;
        }

    }
}