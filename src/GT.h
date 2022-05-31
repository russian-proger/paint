// Graphic Toolkit
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

#include "EventSystem.h"

struct GTPoint {
    int x, y;
};

// GTObject
class GTObject : IEventListener {
private:
    std::string             name_;
    std::list<GTObject*>    children_;
    GTObject*               parent_;
    bool                    visible_;
    GTPoint                 point_;

public:
    GTObject();
    ~GTObject();
    virtual void Render();

    // Getters
    std::string GetName();
    GTObject*   GetParent();
    GTPoint     GetPosition();
    int         GetX();
    int         GetY();

    // Methods
    void SetX(const int x);
    void SetY(const int y);
    void SetPosition(const int x, const int y);
    void SetPosition(const GTPoint pos);
    void AppendObject(GTObject* obj);
    void RemoveObject(GTObject* obj);
};

// GTWindow
class GTWindow : public GTObject {

private:
    bool closed_;

    Display *x_display_;
    XEvent   x_ev_buf_;
    Window   x_window_;
    int      x_screen_;
    
    Atom wm_delete_window_;

    GC GetDefaultGC();

    void OnMouseClick(MouseEvent);

public:
     GTWindow();
    ~GTWindow();

    bool Init();
    void Clear();
    void Update();
    
    bool IsClosed();
};

// GTButton
class GTButton : public GTObject {
private:
    std::string name;
    int width;
    int height;

public:
    GTButton();
    void Render();
};