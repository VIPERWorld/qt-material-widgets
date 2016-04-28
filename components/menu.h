#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "flatbutton.h"

class MenuItem : public FlatButton
{
    Q_OBJECT

public:
    explicit MenuItem(QWidget *parent = 0);
    explicit MenuItem(const QString &text, QWidget *parent = 0);
    ~MenuItem();

    QSize sizeHint() const;
};

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

    inline void setBackgroundOpacity(qreal opacity) { _bkgOpacity = opacity; update(); }
    inline qreal backgroundOpacity() const { return _bkgOpacity; }

    void addMenuItem(MenuItem *item);
    void addMenuItem(const QString &text);

    inline int itemCount() const { return _items.count(); }

protected:
    void paintEvent(QPaintEvent *event);

private:
    QList<MenuItem *> _items;
    qreal _bkgOpacity;
};

#endif // MENU_H
