#ifndef TIEMPO_H
#define TIEMPO_H

#include <QWidget>

class TiempoWindow : public QWidget {
    Q_OBJECT

public:
    explicit TiempoWindow(QWidget *parent = nullptr);

private slots:
    void openMainWindow();
    void goOut();
};

#endif // FIRSTWINDOW_H