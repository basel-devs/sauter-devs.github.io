#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <string>

using namespace std;

string MY_PI="3141592";

int main(int argc, char *argv[])
{


   QFile file("/tmp/pi_test");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       return 0;
    QString line;
   QTextStream in(&file);
   while (!in.atEnd()) {
         line = in.readLine();
   }

   string str = line.toStdString();
   std::size_t found = str.find(MY_PI);

   cout << "found at " << found << endl;
    return 0;
}

