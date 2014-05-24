#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SLOC_clicked();

    void on_EmptyLines_clicked();

    void on_Comments_clicked();

    void on_OnlyCode_clicked();

    void on_VocOperandn2_clicked();

    void on_VocOperandn1_clicked();

    void on_AllOperatN1_clicked();

    void on_AllOperandN2_clicked();

    void on_Cyclomatic_clicked();

    void on_Voc_clicked();

    void on_N_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
