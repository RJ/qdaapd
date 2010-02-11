An embeddable C++/Qt DAAP server library.

How to build 
------------

$ qmake && make

now you have libqdaapd.a

How to use
----------

Include "qdaapd/qdaapd.h" and link to the static library.
Extend QDaap::Collection and pass it to QDAAPd().
See example:

$ cd example/ && qmake && make

Then run: ./example-qdaadp

Make sure /tmp/test.mp3 exists, or edit example/fakecollection.h accordingly.

Notes
-----
So far only tested with amarok and rhythmbox (not itunes, but should work)

