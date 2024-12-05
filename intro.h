#ifndef INTRO_H
#define INTRO_H

#include <QWidget>

class FirstWindow : public QWidget {
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = nullptr);

private slots:
    void openMainWindow();
    void goOut();
};

#endif // FIRSTWINDOW_H


