#ifndef GETarroncoinPAGE_H
#define GETarroncoinPAGE_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QTimer>

namespace Ui {
    class GetarroncoinPage;
}
class ClientModel;
class WalletModel;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Trade page widget */
class GetarroncoinPage : public QWidget
{
    Q_OBJECT

public:
    explicit GetarroncoinPage(QWidget *parent = 0);
    ~GetarroncoinPage();

    void setModel(ClientModel *clientModel);
    void setModel(WalletModel *walletModel);

public slots:

// signals:

private:
    Ui::GetarroncoinPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;

private slots:

};

#endif // GETarroncoinPAGE_H
