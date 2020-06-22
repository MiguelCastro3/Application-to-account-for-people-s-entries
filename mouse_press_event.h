#ifndef MOUSE_PRESS_EVENT_H
#define MOUSE_PRESS_EVENT_H

#include <QLabel>
#include <QMouseEvent>

class Mouse_press_event : public QLabel
{
    Q_OBJECT
public:
    explicit Mouse_press_event(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *mouse_event);
    int x, y;

signals:
    void mouse_position();
};

#endif // MOUSE_PRESS_EVENT_H
