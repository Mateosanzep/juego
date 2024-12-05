#ifndef GANASTE_H
#define GANASTE_H

#include <QWidget>



class GanasteWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit GanasteWindow(QWidget *parent = nullptr);

private slots:
    void openMainWindow();
    void goOut();

private:
};

#endif // FIRSTWINDOW_H