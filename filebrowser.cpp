#include "filebrowser.h"
#include "ui_filebrowser.h"
#include "global.h"
FileBrowser::FileBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);
    filemodel = new QFileSystemModel;
    filemodel->setRootPath(QDir::currentPath());
    ui->treeView->setModel(filemodel);
}

FileBrowser::~FileBrowser()
{
    delete ui;
}

void FileBrowser::on_treeView_doubleClicked(const QModelIndex &index)
{
    filePath = filemodel->fileInfo(index).absoluteFilePath();
    this->accept();
}
