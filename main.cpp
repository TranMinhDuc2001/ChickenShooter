#include "Header.h"

//Global Variable
Render_State render_state;
global_variable bool running;

//function
LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam,LPARAM lParam){
    LRESULT result = 0;
    switch (uMsg){
        case WM_CLOSE:{
            /* code */
            running = false;
        } break;

        case WM_DESTROY:{
            running = false;
        }break;

        case WM_SIZE:{
            RECT rect;
            GetClientRect(hwnd,&rect);
            render_state.width = rect.right - rect.left;
            render_state.height = rect.bottom - rect.top;
            
            int size = render_state.width * render_state.height * sizeof(unsigned int);
            
            if(render_state.memory) VirtualFree(render_state.memory,0,MEM_RELEASE);
            render_state.memory = VirtualAlloc(0,size,MEM_COMMIT | MEM_RESERVE,PAGE_READWRITE);

            render_state.bitmap_info.bmiHeader.biSize = sizeof(render_state.bitmap_info.bmiHeader);
            render_state.bitmap_info.bmiHeader.biWidth = render_state.width;
            render_state.bitmap_info.bmiHeader.biHeight = render_state.height;
            render_state.bitmap_info.bmiHeader.biPlanes = 1;
            render_state.bitmap_info.bmiHeader.biBitCount = 32;
            render_state.bitmap_info.bmiHeader.biCompression = BI_RGB;
        }break;

        default:{
            result = DefWindowProc(hwnd,uMsg,wParam,lParam);
        }break;
    }
    
    
    return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { 
    // Create Window Class
    const char CLASS_NAME[] = "Chicken Shooter";

    WNDCLASS window_class = {};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpszClassName = "Chicken Shooter";
    window_class.lpfnWndProc = window_callback;
    
    //Register Class
    RegisterClass(&window_class);

    //Create Window

    HWND window = CreateWindowEx(
        0, CLASS_NAME, "Chicken Shooter",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    if (window == NULL) return 0;

    ShowWindow(window, nCmdShow);
    running = true;

    HDC hdc = GetDC(window);
    Input input = {};

    float delta_time = 0.016666f; // 60PFS
    LARGE_INTEGER frame_begin_time;
    QueryPerformanceCounter(&frame_begin_time);

    float performance_frequency;
    {
        LARGE_INTEGER perf;
        QueryPerformanceFrequency(&perf);
        performance_frequency = (float)perf.QuadPart;
    }


    while(running){
        //Input
        MSG message;
        for(int i = 0 ; i < BUTTON_COUNT ; i++){
            input.buttons[i].changed = false;
        }
        while(PeekMessage(&message,window,0,0,PM_REMOVE)){
            switch(message.message){
                case WM_KEYUP:
                case WM_KEYDOWN:{
                    u32 vk_code = (u32)message.wParam;
                    bool is_down = ((message.lParam & (1 << 31)) == 0);

                    switch (vk_code){
                        process_button(BUTTON_UP,VK_UP);
                        process_button(BUTTON_DOWN,VK_DOWN);
                        process_button(BUTTON_LEFT,VK_LEFT);
                        process_button(BUTTON_RIGHT,VK_RIGHT);
                    }
                }break;
                default:{
                    TranslateMessage(&message);
                    DispatchMessage(&message);
                }

            }

        }
        //Simulate

        simulate_game(render_state,&input,delta_time);
        //draw_rect(render_state,0,0,.2,.2,0x00ff22);
        //Render
        //render_background(render_state);


        StretchDIBits(hdc,
        0,0,
        render_state.width,
        render_state.height,
        0,0,
        render_state.width,
        render_state.height,
        render_state.memory,
        &render_state.bitmap_info,
        DIB_RGB_COLORS,
        SRCCOPY);

        LARGE_INTEGER frame_end_time;
        QueryPerformanceCounter(&frame_end_time);
        delta_time = (float)(frame_end_time.QuadPart - frame_begin_time.QuadPart) / performance_frequency;
        frame_begin_time = frame_end_time;
    }
    return 0;
} 
