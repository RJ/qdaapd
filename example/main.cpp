#include <QtCore/QCoreApplication>
#include "qdaapd/qdaapd.h"
#include "fakecollection.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FakeCollection coll("Stub/fake collection");
    printf("Starting on port 8080\n");
    printf("FYI, Rhythmbox can manually connect to specific daap shares\n");
    printf("or you can advertise it using: avahi-publish-service Example _daap._tcp 8080\n");
    QDaap::QDAAPd server(&coll, 8080);
    coll.loadTracks();
    return a.exec();
}
