#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QDir>
#include <QObject> // for connecting signals and slots
#include <QTimer>  // for scroll animation

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();
    void animate();


private:
    Ui::MainWindow *ui;

    int width = 1024;
    int height = 768;
    int offset = 25;
    int w = 400;
    int h = 200;

    //QImage *image;
    //QPainter *painter;
    QPixmap pix;

    // timer for scroll animation
    QTimer *timer;

    //
    bool createImage(QString text, QString path, QString imageName, QColor aColor);
};
#endif // MAINWINDOW_H
