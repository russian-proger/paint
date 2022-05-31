// Graphic Toolkit
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

#include "EventSystem.h"


// GTObject
class GTObject : IEventListener {
private:
    std::string          name_;
    std::list<GTObject*> children_;
    GTObject*            parent_;
    bool                 visible_;

public:
    GTObject();
    ~GTObject();
    virtual void Render();

    // Getters
    std::string GetName();
    GTObject*   GetParent();

    // Methods
    void AppendObject(GTObject* obj);
    void RemoveObject(GTObject* obj);
};

// GTWindow
class GTWindow : GTObject {

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
class GTButton : GTObject {
private:
    std::string name;

public:
    GTButton();
    void Render();
};