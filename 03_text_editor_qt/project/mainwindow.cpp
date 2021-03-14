#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto stateMachine = new QStateMachine{this};

    auto Unlocked = new QState{stateMachine};
    Unlocked->assignProperty(ui->pbToggle, "text", "Lock");
    Unlocked->assignProperty(ui->pbOpen, "enabled", true);
    Unlocked->assignProperty(ui->pbSave, "enabled", true);
    Unlocked->assignProperty(ui->teText, "enabled", true);

    auto Startup = new QState{Unlocked};
    Startup->assignProperty(ui->pbOpen, "enabled", true);
    Startup->assignProperty(ui->pbSave, "enabled", false);
    Startup->assignProperty(ui->teText, "enabled", false);
    Startup->assignProperty(ui->teText, "placeholderText", "Open file to start editing...");

    auto Open = new QState{Unlocked};
    connect(Open, SIGNAL(entered()), this, SLOT(open()));

    auto View = new QState{Unlocked};
    View->assignProperty(ui->pbOpen, "enabled", true);
    View->assignProperty(ui->pbSave, "enabled", false);
    View->assignProperty(ui->teText, "enabled", true);

    auto Edit = new QState{Unlocked};
    Edit->assignProperty(ui->pbOpen, "enabled", false);
    Edit->assignProperty(ui->pbSave, "enabled", true);
    Edit->assignProperty(ui->teText, "enabled", true);

    auto Save = new QState{Unlocked};
    connect(Save, SIGNAL(entered()), this, SLOT(save()));

    auto Error = new QState{Unlocked};
    Error->assignProperty(ui->pbOpen, "enabled", true);
    Error->assignProperty(ui->pbSave, "enabled", false);
    Error->assignProperty(ui->teText, "enabled", false);
    Error->assignProperty(ui->teText, "placeholderText", "Error ocured. Open file to start editing...");

    auto Locked = new QState{stateMachine};
    Locked->assignProperty(ui->pbToggle, "text", "Unlock");
    Locked->assignProperty(ui->pbOpen, "enabled", false);
    Locked->assignProperty(ui->pbSave, "enabled", false);
    Locked->assignProperty(ui->teText, "enabled", false);

    QHistoryState *HistoryState = new QHistoryState(Unlocked);
    HistoryState->setDefaultState(Startup);

    Startup->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), Open);
    Open->addTransition(this, SIGNAL(opened()), View);
    View->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), Open);
    View->addTransition(ui->teText, SIGNAL(textChanged()), Edit);
    Edit->addTransition(ui->pbSave, SIGNAL(clicked(bool)), Save);
    Save->addTransition(this, SIGNAL(saved()), View);

    Save->addTransition(this, SIGNAL(error()), Error);
    Open->addTransition(this, SIGNAL(error()), Error);
    Error->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), Open);

    Unlocked->addTransition(ui->pbToggle, SIGNAL(clicked(bool)), Locked);
    Locked->addTransition(ui->pbToggle, SIGNAL(clicked(bool)), HistoryState);

    stateMachine->setInitialState(Unlocked);
    Unlocked->setInitialState(Startup);
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString fileName =  QFileDialog::getOpenFileName(
              this,
              "Open Document",
              QDir::currentPath());

    this->fileName = fileName;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        emit error();

    QTextStream stream(&file);
    QString fileContent = stream.readAll();
    ui->teText->setText(fileContent);

    file.close();

    emit opened();
}

void MainWindow::save()
{
    QFile file(this->fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        emit error();

    QString editedText = ui->teText->toPlainText();
    QTextStream stream(&file);
    stream << editedText;

    file.close();

    emit saved();
}
