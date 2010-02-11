#ifndef FAKE_COLLECTION_H
#define FAKE_COLLECTION_H

#include "qdaapd/collection.h"

class FakeCollection : public QDaap::Collection
{
Q_OBJECT
public:
    explicit FakeCollection(QString name, QObject *parent = 0)
        : QDaap::Collection(name, parent)
    {};

    // called when we should load/prepare the tracklist for this collection:
    virtual void loadTracks()
    {
        qDebug() << "LoadTracks()";
        // fetch from database, read over network etc:

        QDaap::Track t;
        t.id = t.perid = 1;
        t.artist = "Test artist name 1";
        t.album = "Test album name 1";
        t.track = "Test track title 1";
        t.duration = 300000;
        t.filesize = 1024*1024*5;
        t.albumposition = 1;
        t.genre = "Rock";
        t.comment = "no comment";
        t.year = 1982;
        t.albumdiscnumber = 1;
        t.bitrate = 128;


        m_tracks[t.id] = t;

        QDaap::Track t2;
        t2.id = t2.perid = 2;
        t2.artist = "Test artist name 2";
        t2.album = "Test album name 2";
        t2.track = "Test track title 2";
        t2.duration = 200000;
        t2.filesize = 1024*1024*3;
        t2.albumposition = 7;
        t2.genre = "Rock";
        t2.comment = "no comment";
        t2.year = 1982;
        t2.albumdiscnumber = 1;
        t2.bitrate = 128;

        m_tracks[t2.id] = t2;

        emit finishedLoading();
    };

    virtual QIODevice * getTrack(quint32 id)
    {
        if(!m_tracks.contains(id))
        {
            qDebug() << "no track id in collection : " << id;
            return 0;
        }
        //QDaap::Track t = m_tracks[id];
        // lookup file path/url from track id... (hardcoded here)
        QFile * f = new QFile("/tmp/test.mp3");
        f->open(QIODevice::ReadOnly);
        return f;
    };

};


#endif 
