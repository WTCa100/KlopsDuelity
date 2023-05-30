#pragma once

class Application
{
private:
    static Application* instance_;
    Application();
public:
    void startApp();
    static Application* getInstance();
    ~Application();
};

