#ifndef DIALOGINFO_H
#define DIALOGINFO_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class DialogInfo;
}

class DialogInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInfo(QWidget *parent = 0);
    ~DialogInfo();

private:
    Ui::DialogInfo *ui;
};

#endif // DIALOGINFO_H
