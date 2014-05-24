#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>

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
QString code;
float SrKolvoStrokMetodov(QString code)
{QStringList lst=code.split(QRegExp("(void|int|string|float|double|byte)[A-Za-z0-9]*"),QString::SkipEmptyParts);
    int s=0;
    for(int i=lst.count()-1;i>=0;--i)

{
        const QString&item=lst[i];
        s=s+item.count("\n");
}
    float sl=(float)s/(lst.count())-1;
    return sl;
}
float KolvoMetodov(QString code)
{QStringList lst=code.split(QRegExp("(void|int|string|float|double|byte)[A-Za-z0-9]*"), QString::SkipEmptyParts);
    float sl=lst.count()-1;
    return sl;
}
float KolvoStrokModuleyInc(QString code)
{QStringList lst=code.split(QRegExp("#include"), QString::SkipEmptyParts);
    float sl=lst.count()-1;
    return sl;
}
float SrKolvoStrokClassov(QString code)
{
    QStringList lst=code.split(QRegExp("class"), QString::SkipEmptyParts);
    int s=0;
    for(int i=lst.count()-1;i>=0;--i)
    {const QString&item=lst[i];
        s=s+item.count("\n")-1;
    }
    float sl=(float)s/(lst.count());
    return sl;
}
float KolvoClassov(QString code)
{QStringList lst=code.split(QRegExp("class"), QString::SkipEmptyParts);
    float sl=lst.count()-1;
    return sl;
}
 //количестов удаленых методов класса
int NORM(QString code)
{QStringList lst=code.split(QRegExp("class"),QString::SkipEmptyParts);
int s=0;
for(int i=lst.count()-1;i>=0;--i)
{
    const QString& item=lst[i];
    QStringList list=item.split("){",QString::SkipEmptyParts);
    s=s+item.count(")")-item.count("this->")-item.count(")");
}
return s;
}
//количество методов, которые могут быть вызваны экземпляром класса
int RFC(QString code)
{QStringList lst=code.split(QRegExp("class"),QString::SkipEmptyParts);
    int s=0;
    for(int i=lst.count()-1;i>=0;--i)
{
        const QString& item=lst[i];
        QStringList list=item.split("){",QString::SkipEmptyParts);
        s=s+item.count(")")-item.count(")");
}
return s;
}
//сложность методov класса

void MainWindow::MWC(QString code)
{QStringList lst=code.split(QRegExp("class"), QString::SkipEmptyParts);
int s=0;
for(int i=lst.count()-1;i>=0;--i)
{
    const QString& item=lst[i];
    QStringList list=item.split("){", QString::SkipEmptyParts);
    s=0;
    for(int j=list.count()-1;j>=0;--j)
    {const QString& ite=list[j];
        if((ite.count("{")>=ite.count("}"))&&(ite.count("}")!=0))
            s=s+1;
        }
    ui->label_MWC->setText(ui->label_MWC->text()+" "+QString::number(s));
}
}
//количество классов - наследников
void MainWindow::NOC(QString code)
{
    ui->label_NOC->setText("");
    QStringList lst=code.split(QRegExp("class\s"),QString::SkipEmptyParts);
    QStringList lis, Lclss, Rclss;
    for(int g=0; g<lst.count();g++)
    {const QString& item=lst[g].trimmed();
        QString St="";
        for(int i=0;i<item.count();i++)
            if(item[i]!='\n')
                St=St+QString(item[i]);
        else
                break;
        lis<<St;
    }
    for(int g=0;g<lis.count();g++)
    {const QString& item=lis[g].trimmed();
        QString St="";
        for(int i=0; i<item.count();i++)
            if(item[i]!=' ')
                St=St+QString(item[i]);
        else break;
        Rclss<<St;
    }
    for(int g=0;g<lis.count();g++)
    {const QString & item=lis[g].trimmed();
        QString St="";
        lst=item.split(QRegExp("public|protected|private"),QString::SkipEmptyParts);
        for(int i=0;i<lst.count();i++)
        {St=St+lst[i];}
        Lclss<<St;
    }
    for(int g=0;g<Rclss.count();g++)
    {Lclss[g].replace(0,Rclss[g].count(),"");
        Lclss[g]=Lclss[g].trimmed();}
    for(int g=0; g<Rclss.count();g++)
    {Rclss[g].remove(":");
        int s=0;
        for(int i=0; i<Rclss.count();i++)
        {s=s+Lclss[i].count(Rclss[g]);}
        ui->label_NOC->setText(ui->label_NOC->text()+""+Rclss[g]+""+QString::number(s));
    }}
void MainWindow::on_openfile_clicked()
{QString fileName=QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("C++Files(*.cpp *.h)"));
    if(fileName!="")
    {QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this,tr("Error"),tr("Could not open file"));
            return;}
            QTextStream in(&file);
            ui->plainTextEdit->setPlainText(in.readAll());
            file.close();
        }
        code=ui->plainTextEdit->toPlainText();

}







void MainWindow::on_Metrics_clicked()
{QString code=ui->plainTextEdit->toPlainText();
    ui->label_SrKMet->setText(QString::number(SrKolvoStrokMetodov(code)));
    ui->label_SrKSCl->setText(QString::number(SrKolvoStrokClassov(code)));
    MainWindow::MWC(code);MainWindow::NOC(code);
    ui->label_RFC->setText(QString::number(RFC(code)));
    ui->label_NORM->setText(QString::number(NORM(code)));
    ui->label_Met->setText(QString::number(KolvoMetodov(code)));
    ui->Kol_Class->setText(QString::number(KolvoClassov(code)));
    ui->Include->setText(QString::number(KolvoStrokModuleyInc(code)));

}
