#ifndef COLLECTION_H
#define COLLECTION_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QFile>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>

namespace QDaap
{


class Track
{
public:
    Track() : extension("mp3"), disabled(false), trackcount(1), albumdiscnumber(1)
    {};

    quint32 id;
    quint64 perid;
    QString genre;
    QString artist;
    QString album;
    QString track;
    QString comment;
    QString extension;
    bool disabled;
    quint16 bitrate;
    quint32 duration; // ms
    quint32 filesize;
    quint16 trackcount;
    quint16 albumposition;
    quint16 year;
    quint16 albumdiscnumber;
};



/* TODO playlists
class Playlist
{
public:
    quint32 id;
    quint64 perid;
    QString title;
    quint32 length; // num tracks in playlist

    virtual QList<Track> getTracks()
    {
        return QList<Track>();
    };
};
*/

class Collection : public QObject
{
Q_OBJECT
public:
    explicit Collection(QString name, QObject *parent = 0)
        : QObject(parent), m_tracksloaded(false), m_name(name)
    {
        connect(this, SIGNAL(finishedLoading()), this, SLOT(loaded()));
    };

    QString name() const            { return m_name; };
    int numTracks()                 { return tracks().size(); };
    QMap<quint32,Track> & tracks()  { return m_tracks; };
    bool isLoaded() const           { return m_tracksloaded; };

    // this should hit DB/peer get full current list of all tracks:
    virtual void loadTracks() = 0;
    virtual QIODevice * getTrack(quint32 id) = 0;

    // Playlists are not implemented yet
    virtual int numPlaylists() const { return 0 ; };
    //QList<Playlist> playlists() const = 0;

signals:
    void finishedLoading();

private slots:
    void loaded()
    {
      m_tracksloaded = true;
    };

protected:
    QString m_name;
    QMap<quint32,Track> m_tracks;
    bool m_tracksloaded;
};

} // ns

#endif // COLLECTION_H
