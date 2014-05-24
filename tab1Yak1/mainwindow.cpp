#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"
int n1,n2,m,N1,N2,N,R;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SLOC_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    int n=str.count("\n");
    ui->label->setText(QString::number(n+1));
}


void MainWindow::on_EmptyLines_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    int n=str.count("\n\n");
    ui->label_2->setText(QString::number(n));
}

void MainWindow::on_Comments_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    int n=str.count("\n//");
    ui->label_3->setText(QString::number(n));
    int k=str.count("\n");
    ui->label_4->setText(QString::number(((float)n)/(k+1)*100)+"%");
}

void MainWindow::on_OnlyCode_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    int n=str.count("\n\n");
    int k=str.count("\n");
    int m=str.count("\n\\");
    ui->label_5->setText(QString::number((k+1)-n-m));
}

void MainWindow::on_VocOperandn2_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    QRegExp rx("([\\w\\']+)[\\s,.;]");
    QStringList list;
    int pos=0;
    while((pos=rx.indexIn(str,pos))!=-1){
        list<<rx.cap(1);
        pos+=rx.matchedLength(); }
        list.removeDuplicates();
        QString types="int void string double float iterator List const array for while do goto";
        QStringList Itypes;
        Itypes=types.split(" ");
        QStringList::Iterator itt=Itypes.begin();
        for(int i=list.count()-1;i>=0;--i)
        {const QString&item=list[i];
         itt=Itypes.begin();
         while(itt!=Itypes.end()){
             if(item==*itt)
                 list.removeAt(i);
             ++itt;}
         if((item.toFloat()!=0)){list.removeAt(i);}
        }
        for(int i=list.count()-1;i>=0;--i)
        {const QString&item=list[i];
            if(item=="0"){list.removeAt(i);}
        }
        n2=list.count();
        ui->label_6->setText(QString::number(list.count()));}

void MainWindow::on_VocOperatn1_clicked() //словарь операторов
{
    QString str=ui->plainTextEdit->toPlainText();
    QStringList list=str.split(" ");
    QString types="+-=+=++--*<<>><>!= ==||&& &";
    QStringList lst=str.split(QRegExp("void|int|string|float|double|byte)[A-ZA-z0-9]*"),QString::SkipEmptyParts);
    QStringList Itypes;
    QStringList ress;
    list.removeDuplicates();
    Itypes=types.split(" ");
    QStringList::Iterator itt=Itypes.begin();
    for(int i=list.count()-1;i>=0;--i)
    {const QString&item=list[i];
        itt=Itypes.begin();
        while (itt!=Itypes.end()) {
            if(item==*itt){
                ress<<item;
            }
            ++itt;
        }
}
int r=0;
QStringList::Iterator t=lst.begin();
for(int i=lst.count()-1;i>=0;--i)
{
    const QString&item=lst[i];
    r=r+item.count(")\n");
}
R=r;
n1=ress.count();
ui->label_7->setText(QString::number(ress.count()+r));
}
    // общее кол-во операторов

void MainWindow::on_AllOperatN1_clicked()
{
    {QString str=ui->plainTextEdit->toPlainText();
        QStringList list=str.split(" ");
        QString types="+-=+=++--*<<>><>!= ==||&& &";
        QStringList ltypes;
        QStringList ress;
        ltypes = types.split(" ");
        QStringList::Iterator itt=ltypes.begin();
        for(int i=list.count()-1;i>=0;--i)
        {
            const QString&item=list[i];
            itt=ltypes.begin();
            while(itt!=ltypes.end()){
                if(item==*itt){
                    ress<<item;
                }
                ++itt;
            }
        }
        N1=ress.count();
        ui->label_8->setText(QString::number(ress.count()+R));
    }
}
    //общее кол-во операндов

void MainWindow::on_AllOperandN2_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    QRegExp rx("([\\w\\']+)[\\s,.;]");
    QStringList list;
    int pos=0;
    while((pos=rx.indexIn(str,pos))!=-1){
        list<<rx.cap(1);
        pos+=rx.matchedLength();}
    QString types="int void string double float iterator List const array for while do goto";
    QStringList Itypes;
    Itypes=types.split(" ");
    QStringList::Iterator itt=Itypes.begin();
    for(int i=list.count()-1;i>=0;--i)
    {const QString& item=list[i];
        itt=Itypes.begin();
        while(itt!=Itypes.end()){
            if(item==*itt)
                list.removeAt(i);
            ++itt;}
        if((item.toFloat()!=0)){list.removeAt(i);}
    }
    for(int i=list.count()-1;i>=0;--i)
    {const QString&item=list[i];
        if(item=="0"){list.removeAt(i);}
        }
    N2=list.count();
    ui->label_9->setText(QString::number(list.count()));}


void MainWindow::on_Cyclomatic_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    QStringList list=str.split(QRegExp("(for|while)"),
            QString::SkipEmptyParts);
    QStringList::Iterator it=list.begin();
    int s=0;
    for(int i=list.count()-1;i>=0;--i)
    {const QString&item=list[i];
        if((item.count("{")>=item.count("}"))&&(item.count("}")!=0))
        {s=s+1 ;}
    }
    ui->label_10->setText(QString::number(s+str.count("if(")));}


void MainWindow::on_Voc_clicked()
{
    ui->label_11->setText(QString::number(n1+n2+R));
}



void MainWindow::on_N_clicked_clicked()
{
    ui->label_12->setText(QString::number(N1+N2+R));
}

void MainWindow::on_V_clicked_clicked()
{
    float q = N*qLn(m)/qLn(2);
    ui->label_13->setText(QString::number(q));
}

void MainWindow::on_CI_clicked_clicked()
{
    {QString str=ui->plainTextEdit->toPlainText();
        QStringList list=str.split(" ");
        QString types="||&& &";
        QStringList ltypes;
        QStringList ress;
        ltypes = types.split(" ");
        QStringList::Iterator itt=ltypes.begin();
        for(int i=list.count()-1;i>=0;--i)
        {
            const QString&item=list[i];
            itt=ltypes.begin();
            while(itt!=ltypes.end()){
                if(item==*itt){
                    ress<<item;
                }
                ++itt;
            }

}
    N1=ress.count();
    ui->label_14->setText(QString::number(ress.count()+R));
    }}
