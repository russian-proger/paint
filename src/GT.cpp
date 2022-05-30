#include "GT.h"
#include <iostream>

/**
 * @brief Definition GTWindow
 */

GTWindow::GTWindow() {
    this->closed_ = false;
}

GTWindow::~GTWindow() {
    XCloseDisplay(x_display_);
    XDestroyWindow(x_display_, x_window_);
}

bool GTWindow::Init() {
    this->x_display_ = XOpenDisplay(nullptr);

    if (x_display_ == nullptr) {
        return false;
    }

    this->x_screen_ = XDefaultScreen(x_display_);
    this->x_window_ = XCreateSimpleWindow(
        x_display_,
        XDefaultRootWindow(x_display_),
        0,
        0,
        500,
        500,
        1,
        XBlackPixel(x_display_, x_screen_),
        XWhitePixel(x_display_, x_screen_)
    );

    this->Clear();
    XMapWindow(x_display_, x_window_);

    this->wm_delete_window_ = XInternAtom(x_display_, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(x_display_, x_window_, &wm_delete_window_, 1);

    XSelectInput(x_display_, x_window_, ButtonPressMask);

    return true;
}

void GTWindow::Update() {
    
    XNextEvent(this->x_display_, &x_ev_buf_);
    if (x_ev_buf_.type == ClientMessage) {
        if (x_ev_buf_.xclient.data.l[0] == wm_delete_window_) {
            this->closed_ = true;
        }
    }

    if (x_ev_buf_.type == ButtonPress) {
        this->OnMouseClick();
    }
}

void GTWindow::Clear() {
    XClearWindow(x_display_, x_window_);
}

GC GTWindow::GetDefaultGC() {
    return XDefaultGC(x_display_, x_screen_);
}

bool GTWindow::IsClosed() {
    return this->closed_;
}

// Virtual functions
void GTWindow::OnMouseClick() {}
void GTWindow::OnMouseMove() {}
void GTWindow::OnMouseDown() {}
void GTWindow::OnMouseUp() {}
void GTWindow::OnKeyPress() {}
void GTWindow::OnWindowClose() {}