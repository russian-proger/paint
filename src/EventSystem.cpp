#include "EventSystem.h"

// Virtual functions
void IEventListener::OnMouseClick (MouseEvent) {}
void IEventListener::OnMouseMove  (MouseEvent) {}
void IEventListener::OnMouseDown  (MouseEvent) {}
void IEventListener::OnMouseUp    (MouseEvent) {}
void IEventListener::OnKeyPress   (     Event) {}
void IEventListener::OnWindowClose(     Event) {}