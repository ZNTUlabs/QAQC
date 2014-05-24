#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
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
//количество строк кода #1

void MainWindow::on_SLOC_clicked()
{
        QString str=ui->plainTextEdit->toPlainText();
        int n =str.count("\n");
        ui->label ->setText(QString::number(n+1));
}
//количество пустых строк #2
void MainWindow::on_EmptyLines_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    int n =str.count("\n\n");
    ui->label_2 ->setText(QString::number(n+1));
}
//количество комментариев #3

void MainWindow::on_Comments_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    int n =str.count("\n//");
    ui->label_3 ->setText(QString::number(n));
    int k =str.count("\n");
    ui->label_4 ->setText(QString::number(((float)n)/(k+1)*100)+"%");
}

//количество строк кода(общее к-во строк - комментарии - пустые строки)#4

void MainWindow::on_OnlyCode_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    int n =str.count("\n");
    ui->label ->setText(QString::number(n+1));
    int k =str.count("\n//");
     ui->label_3 ->setText(QString::number(k));
    int p =str.count("\n\n");
     ui->label_2 ->setText(QString::number(p+1));

    ui->label_5 ->setText(QString::number(n-k-p));
}
//словарь операторов #5



void MainWindow::on_VocOperandn2_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
    QRegExp rx("([\\w\\']+)[\\s,.;]");
    QStringList list;
    int pos=0;
    while ((pos=rx.indexIn(str,pos))!=-1)
    {   list<<rx.cap(1);
        pos+=rx.matchedLength();
    }
    list.removeDuplicates();
    QString types = "int void string double float iterator List const array for while do goto";
    QStringList ltypes;
    ltypes=types.split(" ");
    QStringList::Iterator itt=ltypes.begin();
    for (int i=list.count()-1; i>=0; --i)
    {const QString& item=list[i];
        itt=ltypes.begin();
        while (itt !=ltypes.end())
        {if(item==*itt)
                list.removeAt(i);
            ++itt;
        }
        if ((item.toFloat()!=0))
        {list.removeAt(i);}
    }
    for (int i=list.count()-1; i>=0; --i)
    {
        const QString& item=list[i];
        if(item=="0")
        {list.removeAt(i);}
    }
    n2=list.count();
    ui->label_6 ->setText(QString::number(list.count()));
    }

//словарь операторов№6

void MainWindow::on_VocOperandn1_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();

    QStringList list=str.split(" ");
    QString types=" + - = += ++ -- * << >> < > != == || && & ";

    QStringList lst = str.split(QRegExp("(void|int|string|float|double|byte)[A-ZA-z0-9]*"), QString::SkipEmptyParts);

    QStringList ltypes;
    QStringList ress;
    list.removeDuplicates();
    ltypes = types.split(" ");
    QStringList::Iterator itt=ltypes.begin();
    for(int i=list.count()-1; i>=0; --i)
    {
        const QString& item=list[i];
        itt=ltypes.begin();
        while(itt!=ltypes.end())
        {
            if(item==*itt)
            {
                ress<<item;
            }
            ++itt;
        }
    }
    int r=0;
    //QStringList::iterator t=lst.begin();
    for(int i=lst.count()-1; i>=0; --i)
    {
        const QString& item = lst[i];
        r=r+item.count(")\n");
    }
    R=r;
    n1=ress.count();
    ui->label_7->setText(QString::number(ress.count()+r));
}


//общее количество операторов №7
void MainWindow::on_AllOperatN1_clicked()
{
    QString str=ui->plainTextEdit->toPlainText();
        QStringList list = str.split(" ");
        QString types = " + - = += == -- * << >> < > != == || && & ";
        QStringList ltypes;
        QStringList ress;
        ltypes = types.split(" ");
        QStringList::Iterator itt = ltypes.begin();
        for (int i = list.count()-1; i>=0; --i)
        {
            const QString& item = list[i];
            itt = ltypes.begin();
            while (itt != ltypes.end())
            {
                if (item == *itt)
                    ress<<item;
                {
                    ++itt;
                }
            }
        }

            N1 = ress.count();
            ui->label_8->setText(QString::number(ress.count()+R));
}

//общее количество операндов №8

void MainWindow::on_AllOperandN2_clicked()
{
    QString str = ui->plainTextEdit->toPlainText();
            QRegExp rx ("([\\w\\']+)[\\s,.;]");
            QStringList list;
            int pos=0;
            while ((pos = rx.indexIn(str,pos)) != -1)
            {
                list << rx.cap(1);
                pos += rx.matchedLength();
            }


                    QString types = " if int void string double float iterator List const array for while do goto ";
                    QStringList ltypes;

                    ltypes = types.split(" ");
                    QStringList::Iterator itt = ltypes.begin();
                    for (int i = list.count()-1; i>=0; --i)
                    {
                        const QString& item = list[i];
                        itt = ltypes.begin();
                        while (itt != ltypes.end())
                        {
                            if (item == *itt)
                                list.removeAt(i);
                            ++itt;
                        }
                         if ((item.toFloat()!=0))
                         {list.removeAt(i);}
                    }
                    for (int i = list.count()-1; i>=0; --i)
                    {
                        const QString& item = list[i];
                        if (item =="0") {list.removeAt(i);}
                    }
                    N2=list.count();
                    ui->label_9->setText(QString::number(list.count()));


}



//цикломатическая сложность №9

void MainWindow::on_Cyclomatic_clicked()
{
    QString str = ui->plainTextEdit->toPlainText();
        QStringList list = str.split(QRegExp("(for|while)"),
                                     QString::SkipEmptyParts);
    //QStringList::Iterator it = list.begin();
    int s=0;
    for(int i=list.count()-1; i>=0; --i)
    {
        const QString& item = list[i];
        if ((item.count("{")>=item.count("}"))&&(item.count("}")!=0))
        {s=s+1;}
    }

    ui->label_10->setText(QString::number(s+str.count("if(")));

}


//словарь программы m=n1+n2+R №10;

void MainWindow::on_Voc_clicked()
{
    m = n1 + n2 + R;
    ui->label_11->setText(QString::number(m));
}

//Длина программы N=N1+N2+R

void MainWindow::on_N_clicked()
{
    N=N1+N2+R;
    ui->label_12->setText(QString::number(N));
}
