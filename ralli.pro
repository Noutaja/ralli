TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        course.cpp \
        courseloader.cpp \
        drawable.cpp \
        game.cpp \
        main.cpp \
        player.cpp \
        point.cpp \
        tile.cpp \
        ui.cpp

HEADERS += \
    course.h \
    courseloader.h \
    drawable.h \
    game.h \
    player.h \
    point.h \
    tile.h \
    ui.h

DISTFILES += \
	default.trk \
	hangingballs.trk \
	hopskipjump.trk \
	images/ralli.png \
	readme.md \
	smol.trk
