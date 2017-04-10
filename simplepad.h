#ifndef SIMPLEPAD_H
#define SIMPLEPAD_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>


namespace Ui {
class simplePad;
}

class simplePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit simplePad(QWidget *parent = 0);
    ~simplePad();

private slots:
    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();



    void on_actionInfo_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::simplePad *ui;
    QString FileName;

};

#endif // SIMPLEPAD_H
