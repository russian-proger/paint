#include "Main.h"

MainWindow::MainWindow() {}
MainWindow::~MainWindow() {}
void MainWindow::OnMouseClick() {

}


MainActivity::MainActivity() {
    window = new MainWindow();
}

MainActivity::~MainActivity() {
    // delete window;
}

void MainActivity::Start() {
    if (!window->Init()) {
        std::cout << "Cannot open display";
        return;
    }


    while (!window->IsClosed()) {
        window->Update();
    }
}