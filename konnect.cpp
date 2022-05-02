#include "konnect.h"
#include <QDebug>
#include<QNetworkInterface>
#include<QString>
#include</usr/include/gpiod.h>
#include <cstdlib>
#include <qthread.h>
#include<QTimer>
#include <QElapsedTimer>

bool globalVar=false;


konnect::konnect(QObject *parent) : QObject(parent),m_btn(false),m_someVar(),m_cmd01("NA"),m_cmd02("NA"),m_cmd03(" "),m_cmd04(" "),m_cmd05("NA"),m_cmd06("NA"),m_cmd07("NA"),m_cmd08("NA"),m_cmd09("NA"),m_cmd10("NA"),m_cmd11("NA"),m_cmd12("NO")
{



    int val,last0;
        const char *chipname = "gpiochip0";
        struct gpiod_chip *chip;


        myTimer = new QTimer(this);
        myTimer->start(120);
        connect(myTimer, SIGNAL (timeout()), this, SLOT (setbtn()));



        server = new QTcpServer(this);
        connect(server, SIGNAL(newConnection()),
                    this, SLOT(newConnection()));


      if(!server->listen(QHostAddress::Any,2112))
               {
                   qDebug() << "Server could not start";

               }
               else
               {

                   qDebug() << "Nooo you cant do this";
           }




}

int konnect::btn()
{


    int val,last0;
        const char *chipname = "gpiochip0";
        struct gpiod_chip *chip;

        chip = gpiod_chip_open_by_name(chipname);
          struct gpiod_line *lineButton; // Pushbutton

          lineButton = gpiod_chip_get_line(chip, 12);
             gpiod_line_request_input(lineButton, "example2");

             // Open GPIO lines
            val = gpiod_line_get_value(lineButton);

            gpiod_line_release(lineButton);
            gpiod_chip_close(chip);


setbtn(val);

           return m_btn;


}

 void konnect::setbtn(int newbtn)
{


    if(m_btn!= newbtn)
    {
QString sal;

        m_btn= newbtn;
        //QElapsedTimer timer;
        //qint64 nanoSec;
       // timer.start();
        //something happens here
      //  nanoSec = timer.nsecsElapsed();
        //printing the result(nanoSec)
        //something else happening here

        //some other operation
   //     nanoSec = timer.nsecsElapsed();
       // if(nanoSec>=1000000000)
       // {


        //   struct gpiod_line *lineButton; // Pushbutton


          // Open GPIO chip


            if(m_btn==1){
                const char *chipname = "gpiochip0";
                  struct gpiod_chip *chip;
                  struct gpiod_line *lineYellow; // Yellow LED
                  chip = gpiod_chip_open_by_name(chipname);

                   // Open GPIO lines
                  lineYellow = gpiod_chip_get_line(chip, 11);
                  gpiod_line_request_output(lineYellow, "example1", 0);
                globalVar = not globalVar;

            if(globalVar==true){
           sal="1";
           gpiod_line_set_value(lineYellow,0);

           gpiod_line_release(lineYellow);

            }
            else if (globalVar==false) {
              sal="0";
              gpiod_line_set_value(lineYellow,1);

              gpiod_line_release(lineYellow);


            }
                setSomeVar(sal);

                emit someVarChanged();
                gpiod_chip_close(chip);

}


        //    timer.restart();
        

  emit btnChanged();
            }


}
QString konnect::someVar()
{
    return m_someVar;
}

void konnect::setSomeVar(QString newVar)
{
    if(m_someVar!= newVar)
    {
        m_someVar=newVar;
        emit someVarChanged();
    }

}
QString konnect::cmd01()
{
    return m_cmd01;
}

void konnect::setcmd01(QString newcmd01)
{
    if(m_cmd01!= newcmd01)
    {
        m_cmd01=newcmd01;
        emit cmd01Changed();
    }

}

QString konnect::cmd02()
{
    return m_cmd02;
}

void konnect::setcmd02(QString newcmd02)
{
    if(m_cmd02!= newcmd02)
    {
        m_cmd02=newcmd02;
        emit cmd02Changed();
    }

}

QString konnect::cmd03()
{
    return m_cmd03;
}

void konnect::setcmd03(QString newcmd03)
{
    if(m_cmd03!= newcmd03)
    {
        m_cmd03=newcmd03;
        emit cmd03Changed();
    }

}


QString konnect::cmd04()
{
    return m_cmd04;
}

void konnect::setcmd04(QString newcmd04)
{
    if(m_cmd04!= newcmd04)
    {
        m_cmd04=newcmd04;
        emit cmd04Changed();
    }

}


QString konnect::cmd05()
{
    return m_cmd05;
}

void konnect::setcmd05(QString newcmd05)
{
    if(m_cmd05!= newcmd05)
    {
        m_cmd05=newcmd05;
        emit cmd05Changed();
    }

}


QString konnect::cmd06()
{
    return m_cmd06;
}

void konnect::setcmd06(QString newcmd06)
{
    if(m_cmd06!= newcmd06)
    {
        m_cmd06=newcmd06;
        emit cmd06Changed();
    }

}


QString konnect::cmd07()
{
    return m_cmd07;
}

void konnect::setcmd07(QString newcmd07)
{
    if(m_cmd07!= newcmd07)
    {
        m_cmd07=newcmd07;
        emit cmd07Changed();
    }

}


QString konnect::cmd08()
{
    return m_cmd08;
}

void konnect::setcmd08(QString newcmd08)
{
    if(m_cmd08!= newcmd08)
    {
        m_cmd08=newcmd08;
        emit cmd08Changed();
    }

}



QString konnect::cmd09()
{
    return m_cmd09;
}

void konnect::setcmd09(QString newcmd09)
{
    if(m_cmd09!= newcmd09)
    {
        m_cmd09=newcmd09;
        emit cmd09Changed();
    }

}


QString konnect::cmd10()
{
    return m_cmd10;
}

void konnect::setcmd10(QString newcmd10)
{
    if(m_cmd10!= newcmd10)
    {
        m_cmd10=newcmd10;
        emit cmd10Changed();
    }

}



QString konnect::cmd11()
{
    return m_cmd11;
}

void konnect::setcmd11(QString newcmd11)
{
    if(m_cmd11!= newcmd11)
    {
        m_cmd11=newcmd11;
        emit cmd11Changed();
    }

}


QString konnect::cmd12()
{
    return m_cmd12;
}

void konnect::setcmd12(QString newcmd12)
{
    if(m_cmd12!= newcmd12)
    {
        m_cmd12=newcmd12;
        emit cmd12Changed();
    }

}
void konnect::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

   // socket->write("Hello client\r\n");
    //socket->flush();

   // socket->waitForBytesWritten(3000);
    //socket->write(socket->readLine());
    //socket->waitForBytesWritten(3000);
    //socket->flush();

QString cmd_text;
QString dmc_text;
QStringList cmd_broken;
QString val_text;
QString hours_text;
QString mins_text;
const char *chipname = "gpiochip0";
  struct gpiod_chip *chip;
  struct gpiod_line *lineYellow; // Yellow LED

//   struct gpiod_line *lineButton; // Pushbutton


  // Open GPIO chip
  chip = gpiod_chip_open_by_name(chipname);

   // Open GPIO lines
  lineYellow = gpiod_chip_get_line(chip, 11);


        //QRegExp rx("#"); //QRegExp rx("(\\ |\\,|\\.|\\:|\\t)"); //RegEx for ' ' or ',' or '.' or ':' or '\t ' QStringList query = cmd_text.split(rx);
    QByteArray totol_data, data_buffer;
    if(socket->waitForReadyRead()) {

       cmd_text = socket->readLine();
   //    if(cmd_text!= nullptr)
     //  {
           cmd_broken = cmd_text.split(',').first().split('_');
           dmc_text = cmd_broken.first();
           val_text = cmd_broken.last();
                                     //  setcmd07("TRAIN OK");
                                    //   setcmd07(dmc_text);
                                   //   setcmd08(val_text);





           if(dmc_text=="CMD01")
           {

               if(val_text.toDouble()<=99.99 && val_text.toDouble()>=0)
               {
                setcmd01(val_text);


               }
               else
               {
                setcmd01("ERR");
               }

           }


           if(dmc_text=="CMD02")
           {

               if(val_text=="YES")
               {
                setcmd02("ON");

               }
               else if(val_text=="NO")
               {

                setcmd02("OFF");
               }

           }


           if(dmc_text=="CMD03")
           {

               if(val_text=="YES")
               {
                setcmd03("S");

               }
               else if(val_text=="NO")
               {

                setcmd03("M");
               }

           }


           if(dmc_text=="CMD04")
           {

               if(val_text=="YES")
               {
                setcmd04("X");

               }
               else if(val_text=="NO")
               {

                setcmd04("O");
               }

           }

           if(dmc_text=="CMD05")
           {
               if(val_text.toInt()<=40)
               {
               setcmd05(val_text + "V");
               }
               else {
                   setcmd05("ERR");

               }
            }

           if(dmc_text=="CMD06")
           {
               if(val_text.toInt()<=100)
               {
               setcmd06(val_text);
               }
               else {
                   setcmd06("ERR");

               }
            }


           if(dmc_text=="CMD07")
           {

               if(val_text=="YES")
               {
                setcmd07("TRAIN OK");

               }
               else if(val_text=="NO")
               {

               setcmd07("TRAIN NOK");
               }

           }

               if(dmc_text=="CMD08")
               {
                   //setcmd07(val_text);
                   if(val_text.toInt()<=9999)
                   {
                   setcmd08(val_text + "M");
                   }
                   else {
                       setcmd08("ERR");

                   }




           }

               if(dmc_text=="CMD09")
               {
                   if(val_text.toInt()<=999999)
                   {
                   setcmd09(val_text);
                   }
                   else {
                       setcmd09("ERR");

                   }
                }


               if(dmc_text=="CMD10")
               {
                   hours_text = val_text.split(':').first();
                   mins_text = cmd_broken.last();

                   if(hours_text.toInt()<25 && mins_text.toInt()<60)
                   {
                   //setcmd10(hours_text + ":" + mins_text);
                       setcmd10(mins_text);
                    }
                   else {
                       setcmd10("ERR");
                   }
                }

               if(dmc_text=="CMD11")
               {

                   if(val_text.toDouble()<=99.99 && val_text.toDouble()>=0)
                   {
                    setcmd11(val_text);


                   }
                   else
                   {
                    setcmd11("ERR");
                   }

               }


               //  lineButton = gpiod_chip_get_line(chip, 6);

                 // Open LED lines for output
                 //gpiod_line_request_output(lineRed, "example1", 0);
                 //gpiod_line_request_output(lineGreen, "example1", 0);
                 gpiod_line_request_output(lineYellow, "example1", 0);
               if(dmc_text=="CMD12" )
               {
    
                   if(val_text=="YES")
                   {
                    setcmd12("YES");
                       gpiod_line_set_value(lineYellow,1);

                       gpiod_line_release(lineYellow);

                   }
                   if(val_text=="NO")

                   {
    
                    setcmd12("NO");
                       gpiod_line_set_value(lineYellow,0);

                       gpiod_line_release(lineYellow);


                   }
    
               }
//                  gpiod_line_release(lineButton);
// gpiod_chip_close(chip);

socket->close();
gpiod_chip_close(chip);
    }


        //setSomeVar(socket->readLine());

        //socket->close();

        }











