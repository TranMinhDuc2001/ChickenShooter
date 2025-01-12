#include <windows.h> 

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
void clear_screen(Render_State,unsigned int);
void draw_rect(Render_State,int,int,int,int,unsigned int);