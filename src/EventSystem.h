enum class EventType {
    eMouseEnter,
    eMouseLeave,
    eMouseMove,
    eMouseClick,
    eMouseDown,
    eMouseUp,
    eKeyPress,
    eWindowClose
};

enum class MouseButton {
    eLeftButton,
    eRightButton,
    eWheel
};


struct MouseEvent {
    int
        x,              // Relative position x
        y,              // Relative position y
        root_x,         // Absolute posiiton x
        root_y;         // Absolute posiiton y
        
    MouseButton button; // Pressed Button
};

struct KeyEvent {
    char key_code;      // Char code typed
};

struct Event {
    EventType type;
    union {
        KeyEvent    key;
        MouseEvent  mouse;
    };
};

class IEventListener {
protected:
    virtual void OnMouseClick (MouseEvent);
    virtual void OnMouseMove  (MouseEvent);
    virtual void OnMouseDown  (MouseEvent);
    virtual void OnMouseUp    (MouseEvent);
    virtual void OnKeyPress   (     Event);
    virtual void OnWindowClose(     Event);
};