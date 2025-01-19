#include <windows.h> 
#include "utils.h"
//Define
#define global_variable static
#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)

#define process_button(b,vk)\
    case vk:{\
        input.buttons[b].is_down = is_down;\
        input.buttons[b].changed = true;\
    }break;


//Data Struct
struct Render_State {
    int height,width;
    void* memory;
    BITMAPINFO bitmap_info;
};

struct Button_State {
    bool is_down;
    bool changed;
};

enum{
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_COUNT,
};

struct Input{
    Button_State buttons[BUTTON_COUNT];
};

//Function
void render_background(Render_State);
void clear_screen(Render_State,u32);
void draw_rect(Render_State,float,float,float,float,u32);
void simulate_game(Render_State,Input*,float);