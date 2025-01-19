#include "Header.h"


float player_pos_x = 0.f;
float player_pos_y = 0.f;
void simulate_game(Render_State render_state, Input* input,float dt){
    clear_screen(render_state,0xff5000);

    float speed = 50.f;
    if(is_down(BUTTON_UP)) player_pos_y += speed * dt;
    if(is_down(BUTTON_DOWN)) player_pos_y -= speed * dt;
    if(is_down(BUTTON_LEFT)) player_pos_x -= speed * dt;
    if(is_down(BUTTON_RIGHT)) player_pos_x += speed * dt;
    draw_rect(render_state,player_pos_x,player_pos_y,1,1,0x00ff22);

}