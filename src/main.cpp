#include "App.hpp"
#include <iostream>

#include <thread>

void runApp()
{
    App app {1280, 720, "muesli reforged"};
    app.run();
}

int main()
{
	std::thread appThread(runApp);
	std::cout << "program exit\n";
	appThread.join();
    return 0;
}