#pragma once

class Application
{
private:
    static Application* instance_;
    Application();
    void startGameSession();
public:
    void startApp();
    static Application* getInstance();
    ~Application();
};

