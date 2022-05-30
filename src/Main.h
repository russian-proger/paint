#include <iostream>
#include <thread>
#include "GT.h"


class MainWindow : public GTWindow {
protected:
    void OnMouseClick();
public:
    MainWindow();
    ~MainWindow();
};

class MainActivity {
private:
    MainWindow* window;
public:
    MainActivity();
    ~MainActivity();
    void Start();
};