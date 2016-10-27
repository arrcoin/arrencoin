#include "whatsnewdialog.h"
#include "ui_whatsnewdialog.h"
#include "clientmodel.h"
#include "util.h"
#include "guiutil.h"
#include "guiconstants.h"
#include "version.h"

using namespace GUIUtil;

bool whatsNewAccepted = false;

WhatsNewDialog::WhatsNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WhatsNewDialog)
{
    std::string title = "艾伦币总量：8.8亿\n 区块速度：60S \n 核心算法：Scrypt";
    std::string description = GetArg("-vDescription", "暂无新版本更新，请等待更新").c_str();
    std::string version = "初始版本：1.0.0.0、如有更新请尽快更新钱包版本" + GetArg("-vVersion", "0.0");
    ui->setupUi(this);

    ui->title->setFont(qFontLarge);
    ui->title->setText(title.c_str());
    ui->description->setFont(qFont);
    ui->description->setText(version.append(": ").append(description).c_str());
}

void WhatsNewDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion().append(GetArg("-vArch", "").c_str()).append("  (没有可用的更新)"));
    }
}

WhatsNewDialog::~WhatsNewDialog()
{
    delete ui;
}

void WhatsNewDialog::on_buttonBox_accepted()
{
    whatsNewAccepted = true;
    close();
}
