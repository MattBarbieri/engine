#include <iostream>
#include <vulkan/vulkan.h>
// #include "loadlib.cpp"
#include <imgui/imgui.h>

#if WINDOWS
#include <Windows.h>

int WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    WNDCLASS window = {};
    window.hInstance = hInstance;
    window.lpszMenuName = "Menu";
    window.style = CS_HREDRAW | CS_VREDRAW;
    Text while (true)
    {
        /* code */
    }
    return (0);
}

#elif APPLE
#include <GLFW/glfw3.h>
int main(int argc, char const *argv[])
{
    /* code */
    ImFont font;
    std::cout << "apple plataform" << std::endl;

    while (true)
    {
        /* code */
    }

    return 0;
}
#elif UNIX
#include <GLFW/glfw3.h>
int main(int argc, char const *argv[])
{
    /* code */
    while (true)
    {
        /* code */
    }
    std::cout << "Linux plataform" << std::endl;
    return 0;
#endif