#include <QCoreApplication>
#include <QObject>
#include <QDebug>

class MyObject : public QObject{
QString name;
public:
    MyObject(QString name, QObject* parent) : QObject(parent){
        this->name = name;
        qDebug() << "Tworzy sie MyObject" << name << "\n" ;
    }

    ~MyObject(){
        qDebug() << "MyObject "<< name << "umiera!.\n";
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Start\n";
    MyObject* son;
    MyObject* grandson;

    {
        MyObject daddy("Ojczulek", nullptr);
        son = new MyObject("Synek", &daddy);
        grandson = new MyObject("Wnusio", son);
        qDebug() << "Przed końcem zakresu\n";
    }

    qDebug() << "Poza zakresem.\n";

    return a.exec();
}
