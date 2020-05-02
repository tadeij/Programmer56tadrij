#include <windows.h>
#define BUTTON_ID 1
#define MONTHCALID 2

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmsShow)
{
    const char class_name = "wnd-classname";
    MSG msg;
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.style = 0;
    wc.lpClassName = class_name;
    wc.lpszMenuName = nullptr;
    wc.hIcon = LoadIcon(NULL, IDI_INFORMATION);
    wc.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) COLOR_WINDOW);
    wc.hInstance = hInst;
    wc.lpfnWndProc = WndProc;

    HWND hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
                               classname,
                               "The Windows aero button style window",
                               WS_OVERLAPPEDWINDOW,
                               100,
                               100,
                               800,
                               600,
                               nullptr,
                               nullptr,
                               hInst,
                               nullptr);
    ShowWindow(hwnd, nCmsShow);
    UpdateWindow(hwnd);

    while(GetMessage(&msg, nullptr, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
         case WM_CREATE:
         {
             RECT rc = {100 ,100,190,160};  
             CreateWindowEx(0,
                            WC_BUTTON,
                            "Button example",
                            WS_VISIBLE | WS_CHILD,
                            10, 10, 100, 500,
                            hwnd,
                            (HMENU) BUTTON_ID,
                            nullptr,
                            nullptr);

             CreateWindowEx(0,
                            MONTHCAL_CLASS,
                            0,
                            WS_VISIBLE | WS_CHILD,
                            100,
                            100,
                            rc.left, 
                            rc.top, 
                            rc.right, 
                            rc.bottom,
                            hwnd,
                            (HMENU)MONTHCALID,
                            nullptr,
                            nullptr);
         }
         break;
         
         case WM_COMMAND:
              if(LOWORD(wParam) == BUTTON_ID)
              {
                   MessageBox(NULL,
                              "Clicked button Button example",
                              "Noftication",
                              MB_ICONEXCLAMATION | MB_OK);
              }
              break;

         case WM_CLOSE:
             DestroyWindow(hwnd);
             break;
         case WM_DESTROY:
             PodtQuitMessage(0);
             break;
         default:
             return DefWindowProc(hwnd, uMsg, wParam, lParam);
         
         return 0;
}
          
           

                            
                            
   

          
