greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG +=console

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/gridwidget.cpp \
    src/mediator.cpp

HEADERS += \
    include/mainwidget.h \
    include/mainwindow.h \
    include/gridwidget.h \
    include/mediator.h

OTHER_FILES += \
    img/flag.png \
    img/happy.png \
    img/mine.png \
    img/sad.png


