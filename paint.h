#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Paint; }
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT

public:
    Paint(QMainWindow *parent = nullptr);
    ~Paint();

private:
    void paintEvent(QPaintEvent *event);

    Ui::Paint *ui;
};
#endif // PAINT_H
