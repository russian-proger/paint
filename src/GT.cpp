#include "GT.h"


/**
 * @brief Definition GTWindow
 */

GTObject::GTObject() {
    this->visible_ = true;
    this->point_ = {0, 0};
}

GTObject::~GTObject() {}

std::string GTObject::GetName() {
    return this->name_;
}

GTObject* GTObject::GetParent() {
    return this->parent_;
}

int GTObject::GetX() {
    return this->point_.x;
}

int GTObject::GetY() {
    return this->point_.x;
}

GTPoint GTObject::GetPosition() {
    return this->point_;
}

void GTObject::SetX(const int x) {
    this->point_.x = x;
}

void GTObject::SetY(const int y) {
    this->point_.y = y;
}

void GTObject::SetPosition(const GTPoint pos) {
    this->point_.x = pos.x;
    this->point_.y = pos.y;
}


void GTObject::AppendObject(GTObject* obj) {
    children_.push_back(obj);
}

void GTObject::RemoveObject(GTObject* obj) {
    std::list<GTObject*>::iterator child;
    child = std::find(children_.begin(), children_.end(), obj);

    if (child != children_.end()) {
        children_.push_back(obj);
    }
}

void GTObject::Render() {};

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
        this->OnMouseClick({
            
        });
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

void GTWindow::OnMouseClick(MouseEvent ev) {
    std::cout << "Mouse clicked!" << std::endl;
}

/**
 * @brief Definition GTButton
 * 
 */
GTButton::GTButton() {
    width = 60;
    height = 30;
}

void GTButton::Render() {
    
}