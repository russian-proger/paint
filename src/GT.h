// Graphic Toolkit
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <set>
#include <string>

class GTWindow {

protected:
    virtual void OnMouseClick();
    virtual void OnMouseMove();
    virtual void OnMouseDown();
    virtual void OnMouseUp();
    virtual void OnKeyPress();
    virtual void OnWindowClose();

private:
    bool closed_;

    Display *x_display_;
    XEvent   x_ev_buf_;
    Window   x_window_;
    int      x_screen_;
    
    Atom wm_delete_window_;

    GC GetDefaultGC();

public:
     GTWindow();
    ~GTWindow();

    bool Init();
    void Clear();
    void Update();
    
    bool IsClosed();
};

struct GTMouseEvent {

};

struct GTEvent {

};

class GTObject {
    int z_index;
    std::string name;

public:
    void Render();

    bool operator()(const GTObject *other);
};

class GTObjectManager {

private:
    std::set<GTObject*, GTObject> gt_objects_;

public:
    GTObjectManager();
    ~GTObjectManager();

    void Add();
};