#ifndef HTTPD_H
#define HTTPD_H

#include <QDebug>
#include <QString>
#include <QRegExp>
#include <QStringList>

#ifdef _WIN32
#include <winsock.h>
#define	snprintf			_snprintf

#ifndef _WIN32_WCE
#ifdef _MSC_VER /* pragmas not valid on MinGW */
#endif /* _MSC_VER */

#else /* _WIN32_WCE */
/* Windows CE-specific definitions */
#pragma comment(lib,"ws2")
//#include "compat_wince.h"
#endif /* _WIN32_WCE */

#else
#include <sys/types.h>
#include <sys/select.h>
#include <sys/wait.h>
#endif

#ifndef _WIN32_WCE /* Some ANSI #includes are not available on Windows CE */
#include <time.h>
#include <errno.h>
#include <signal.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "qdaapd/mongoose.h"


#include "qdaapd/collection.h"

#include "qdaapd/basic.h"
#include "qdaapd/tagoutput.h"
#include "qdaapd/taginput.h"
#include "qdaapd/registry.h"

using namespace std;

typedef QMap<QString,QString> ssmap;

class QDAAPd :  public QObject
{
    Q_OBJECT
public:
    QDAAPd(QDaap::Collection * c, quint16 port = 8080);
    ~QDAAPd();

    void handleRequest(struct mg_connection * conn, const struct mg_request_info * request_info);

private slots:
    void startListening();

private:
    int do_server_info(QStringList & headers, QByteArray & body);
    int do_login(QStringList & headers, QByteArray & body);
    int do_databases(QStringList & headers, QByteArray & body);
    int do_databases_items(QStringList & headers, QByteArray & body);
    int do_databases_containers(QStringList & headers, QByteArray & body);
    int do_databases_containers_items(QStringList & headers, QByteArray & body);
    int do_update(QStringList & headers, QByteArray & body);

    QByteArray cs(const TagOutput &);

    QDaap::Collection * m_coll;
    struct mg_context * m_ctx;

    int m_port;

};

static void mongoose_handler(struct mg_connection * conn,
                             const struct mg_request_info * request_info,
                             void *user_data)
{
    QDAAPd * httpd = (QDAAPd*)user_data;
    httpd->handleRequest(conn, request_info);
}


#endif // HTTPD_H
