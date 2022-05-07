#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Paint; }
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT

public:
    Paint(QMainWindow *parent = nullptr);
    ~Paint();

private slots:
    void updatePaint();

private:
    void paintEvent(QPaintEvent *event);

    Ui::Paint *ui;
    QTimer *paintTimer;
};
#endif // PAINT_H
