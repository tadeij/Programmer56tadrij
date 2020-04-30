#include <windows.h>

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

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
{
    switch(msg)
    {
         case WM_CREATE:
             CreateWindow(
                 "The button class name",
                 "Windows Aero.button",
                  WS_VISIBLE | WS_CHILD,
                  100, 100, 25, 10,
                  hwnd,
                  (HMENU)1,
                  nullptr,
                  nullptr);
         break;
         case WM_CLOSE:
             DrstroyWindow(hwnd);
             break;
         case WM_DESTROY:
             PostQuitMessage(0);
             break;
         default:
             return DefWindowProc(hwnd, msg, wParam, lParam);
    }
   
    return 0;
}
