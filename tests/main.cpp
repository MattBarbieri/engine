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
    glfwInit();
    GLFWwindow *window;
    int width = 800;
    int height = 600;

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    window = glfwCreateWindow(width, height, APPLICATION_NAME, nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
        glfwGetFramebufferSize(window, &width, &height);
        /* code */

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
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