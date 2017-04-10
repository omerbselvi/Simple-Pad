#include "simplepad.h"
#include "ui_simplepad.h"
#include "dialoginfo.h"


simplePad::simplePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::simplePad)
{
    ui->setupUi(this);
}

simplePad::~simplePad()
{
    delete ui;
}

void simplePad::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}

void simplePad::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void simplePad::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void simplePad::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void simplePad::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void simplePad::on_actionInfo_triggered()
{

    DialogInfo asd;
    asd.setFixedSize(150,100);
    asd.setModal(true);
    asd.exec();

}

void simplePad::on_actionNew_triggered()
{
    FileName="";
    ui->plainTextEdit->setPlainText("");
}

void simplePad::on_actionOpen_triggered()
{
    QString file= QFileDialog::getOpenFileName(this,"Select a file");

    if(!file.isEmpty()){
        QFile File(file);
        if(File.open(QFile::ReadOnly | QFile::Text)){
            FileName=file;
            QTextStream fileIn(&File);
            QString text= fileIn.readAll();
            ui->plainTextEdit->setPlainText(text);
        }
    }
}

void simplePad::on_actionSave_triggered()
{
    if(FileName!=""){
        QFile saveFile(FileName);
        if(saveFile.open(QFile::WriteOnly| QFile::Text)){
            QTextStream fileOut(&saveFile);
            fileOut<< ui->plainTextEdit->toPlainText();

            saveFile.flush();
            saveFile.close();
        }}
    else{
        on_actionSave_As_triggered();
    }
}

void simplePad::on_actionSave_As_triggered()
{
    QString file= QFileDialog::getSaveFileName(this,"Save as...");
    if(!file.isEmpty()){
        FileName=file;
        on_actionSave_triggered();
    }
}
