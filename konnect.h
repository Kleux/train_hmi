#ifndef KONNECT_H
#define KONNECT_H
#include<QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include<QtWidgets/qlabel.h>
#include<QTimer>
extern bool globalVar;
class konnect : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString someVar READ someVar WRITE setSomeVar NOTIFY someVarChanged )
    Q_PROPERTY(QString cmd01 READ cmd01 WRITE setcmd01 NOTIFY cmd01Changed )
    Q_PROPERTY(QString cmd02 READ cmd02 WRITE setcmd02 NOTIFY cmd02Changed )
    Q_PROPERTY(QString cmd03 READ cmd03 WRITE setcmd03 NOTIFY cmd03Changed )
    Q_PROPERTY(QString cmd04 READ cmd04 WRITE setcmd04 NOTIFY cmd04Changed )
    Q_PROPERTY(QString cmd05 READ cmd05 WRITE setcmd05 NOTIFY cmd05Changed )
    Q_PROPERTY(QString cmd06 READ cmd06 WRITE setcmd06 NOTIFY cmd06Changed )
    Q_PROPERTY(QString cmd07 READ cmd07 WRITE setcmd07 NOTIFY cmd07Changed )
    Q_PROPERTY(QString cmd08 READ cmd08 WRITE setcmd08 NOTIFY cmd08Changed )
    Q_PROPERTY(QString cmd09 READ cmd09 WRITE setcmd09 NOTIFY cmd09Changed )
    Q_PROPERTY(QString cmd10 READ cmd10 WRITE setcmd10 NOTIFY cmd10Changed )
    Q_PROPERTY(QString cmd11 READ cmd11 WRITE setcmd11 NOTIFY cmd11Changed )
    Q_PROPERTY(QString cmd12 READ cmd12 WRITE setcmd12 NOTIFY cmd12Changed )
    Q_PROPERTY(int btn READ btn WRITE setbtn NOTIFY btnChanged)
public:
     explicit konnect(QObject *parent = nullptr);
//    Q_INVOKABLE void anotherFunction();
    QString someVar();
    QString cmd01();
    QString cmd02();
    QString cmd03();
    QString cmd04();
    QString cmd05();
    QString cmd06();
    QString cmd07();
    QString cmd08();
    QString cmd09();
    QString cmd10();
    QString cmd11();
    QString cmd12();
    int btn();

signals:
    void someVarChanged();
    void cmd01Changed();
    void cmd02Changed();
    void cmd03Changed();
    void cmd04Changed();
    void cmd05Changed();
    void cmd06Changed();
    void cmd07Changed();
    void cmd08Changed();
    void cmd09Changed();
    void cmd10Changed();
    void cmd11Changed();
    void cmd12Changed();
    void btnChanged();
public slots:
      void newConnection();
    void setSomeVar(QString);
    void setcmd01(QString);
    void setcmd02(QString);
    void setcmd03(QString);
    void setcmd04(QString);
    void setcmd05(QString);
    void setcmd06(QString);
    void setcmd07(QString);
    void setcmd08(QString);
    void setcmd09(QString);
    void setcmd10(QString);
    void setcmd11(QString);
    void setcmd12(QString);
    void setbtn(int);



private:
      QTcpServer *server =nullptr;
      QTcpSocket *socket= nullptr;
      QString m_someVar;
      QString m_cmd01;
      QString m_cmd02;
      QString m_cmd03;
      QString m_cmd04;
      QString m_cmd05;
      QString m_cmd06;
      QString m_cmd07;
      QString m_cmd08;
      QString m_cmd09;
      QString m_cmd10;
      QString m_cmd11;
      QString m_cmd12;
      int m_btn;
QTimer *myTimer;
QTimer *newTimer;

};

#endif // KONNECT_H
