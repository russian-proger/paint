// Graphic Toolkit
#include <X11/Xlib.h>
#include <X11/Xutil.h>


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

public:
     GTWindow();
    ~GTWindow();

    void Clear();
    bool Init();
    bool IsClosed();
    void Update();

    GC GetDefaultGC();
};