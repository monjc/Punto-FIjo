#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


double MainWindow::funcion(double c){
    return (667.38/c)*(1-exp(-0.146843*c))-40;

}
void MainWindow::metodo(){
    QString temp,temp2,temp3;
    double X1=ui->x->value();
    double error=ui->Error->value();
    double xr=0.0;
    double ea=100.0;
    while(ea>error){
        xr=funcion(X1);
        ea=100*std::abs(xr-X1)/xr;
        X1=xr;
    }
    temp.append("Raiz=").append(temp2.setNum(xr)).append("\nError=").append(temp3.setNum(ea));  // The text to be presented
    ui->Texto->setText(temp);
    }
    void MainWindow::borrar(){
        ui->x->setValue(0.0);
        ui->Error->setValue(0.0);
        ui->Texto->clear();
    }
