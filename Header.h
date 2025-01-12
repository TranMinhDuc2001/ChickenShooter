#include <windows.h> 
#include "utils.h"
//Define
#define global_variable static


//Data Struct
struct Render_State {
    int height,width;
    void* memory;
    BITMAPINFO bitmap_info;
};

//Function
void render_background(Render_State);
void clear_screen(Render_State,u32);
void draw_rect(Render_State,float,float,float,float,u32);