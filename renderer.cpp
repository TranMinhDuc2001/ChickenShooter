#include "Header.h"

void render_background(Render_State render_state){
    u32* pixel = (u32*) render_state.memory;
    for(int i = 0 ; i < render_state.height ; i++){
        for(int j = 0 ; j < render_state.width ; j++){
            *pixel++ = 0xff00ff * i + 0x00ff00 * j;
        }

    }

}

void clear_screen(Render_State render_state,u32 color){
    u32* pixel = (u32*) render_state.memory;
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

static void draw_rect_in_pixels(Render_State render_state,int xs,int ys,int xe,int ye,u32 color){
    xs = clamp(0,xs,render_state.width);
    xe = clamp(0,xe,render_state.width);
    ys = clamp(0,ys,render_state.height);
    ye = clamp(0,ye,render_state.height);

    for(int i = ys ; i < ye ; i++){
        u32* pixel = (u32*) render_state.memory + xs + i * render_state.width;
        for(int j = xs ; j < xe ; j++){
            *pixel++ = color;
        }

    }
}

global_variable float render_scale = 0.01f;

void draw_rect(Render_State render_state,float x, float y, float half_size_x, float half_size_y,u32 color){
    x *= render_state.height * render_scale;
    y *= render_state.height * render_scale;
    half_size_x *= render_state.height * render_scale;
    half_size_y *= render_state.height * render_scale;
    
    x += render_state.width / 2.f;
    y += render_state.height / 2.f;

    int x0 = x - half_size_x;
    int x1 = x + half_size_x;
    int y0 = y - half_size_y;
    int y1 = y + half_size_y;
    draw_rect_in_pixels(render_state,x0,y0,x1,y1,color);
}