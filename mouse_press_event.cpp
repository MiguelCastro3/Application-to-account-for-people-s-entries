#include "mouse_press_event.h"

Mouse_press_event::Mouse_press_event(QWidget *parent) : QLabel(parent)
{

}

void Mouse_press_event::mousePressEvent(QMouseEvent *mouse_event)
{
    this->x = mouse_event->x();
    this->y = mouse_event->y();
    emit(mouse_position());
}
