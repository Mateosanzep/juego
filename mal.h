#ifndef MAL_H
#define MAL_H

#include <QWidget>



class MalWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MalWindow(int id,QWidget *parent = nullptr);

private slots:
    void openMainWindow();
    void goOut();

private:
    QLabel *correctaLabel;
};

#endif // FIRSTWINDOW_H