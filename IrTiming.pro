QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Core/core.cpp \
    Core/driver.cpp \
    Core/gap.cpp \
    Core/lap.cpp \
    Core/lap_sector.cpp \
    Core/myteam.cpp \
    Core/pitstop.cpp \
    Core/session.cpp \
    Core/stint.cpp \
    Core/stint_pitstop.cpp \
    Core/sunset.cpp \
    Core/team.cpp \
    Core/team_avg_calculator.cpp \
    Core/team_gap_container.cpp \
    Core/teams.cpp \
    Core/tire_wear.cpp \
    Core/track.cpp \
    Core/trackpoint.cpp \
    Core/trackpoints.cpp \
    Core/weather.cpp \
    Data/database.cpp \
    Data/db_telemetry.cpp \
    Data/db_track.cpp \
    Data/db_windows.cpp \
    Ir/ir_service.cpp \
    Ir/ir_tel_var.cpp \
    Ir/ir_tel_vars.cpp \
    Ir/irsdk_diskclient.cpp \
    Ir/irsdk_utils.cpp \
    SessionInfo/driverinfo.cpp \
    SessionInfo/driverinfo_drivers.cpp \
    SessionInfo/sessioninfo.cpp \
    SessionInfo/sessioninfo_resultposition.cpp \
    SessionInfo/sessioninfo_session.cpp \
    SessionInfo/sessionstring.cpp \
    SessionInfo/splittimeinfo.cpp \
    SessionInfo/splittimeinfo_sectors.cpp \
    SessionInfo/telemetryoptions.cpp \
    SessionInfo/weekendinfo.cpp \
    SessionInfo/weekendoptions.cpp \
    Telemetry/telemetry_data.cpp \
    Telemetry/telemetry_save_data.cpp \
    Telemetry/telemetry_save_data_lap.cpp \
    Telemetry/telemetry_save_data_lap_pct.cpp \
    Telemetry/telemetryreader.cpp \
    UI/Delegates/cus_default_cell.cpp \
    UI/Delegates/cus_driverlaps_cell.cpp \
    UI/Delegates/cus_fuel_cell.cpp \
    UI/Delegates/cus_gap_cel.cpp \
    UI/Delegates/cus_gap_cell.cpp \
    UI/Delegates/cus_laptime_cell.cpp \
    UI/Delegates/cus_lis_cell.cpp \
    UI/Delegates/cus_state_cell.cpp \
    UI/black.cpp \
    UI/debug_timing.cpp \
    UI/gap_overlay.cpp \
    UI/gap_overlay_2.cpp \
    UI/hue.cpp \
    UI/race_graph.cpp \
    UI/stint_creator.cpp \
    UI/stint_overlay.cpp \
    UI/times.cpp \
    UI/tire_graph.cpp \
    UI/tires.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    master.cpp \
    yaml-cpp/src/binary.cpp \
    yaml-cpp/src/contrib/graphbuilder.cpp \
    yaml-cpp/src/contrib/graphbuilderadapter.cpp \
    yaml-cpp/src/convert.cpp \
    yaml-cpp/src/depthguard.cpp \
    yaml-cpp/src/directives.cpp \
    yaml-cpp/src/emit.cpp \
    yaml-cpp/src/emitfromevents.cpp \
    yaml-cpp/src/emitter.cpp \
    yaml-cpp/src/emitterstate.cpp \
    yaml-cpp/src/emitterutils.cpp \
    yaml-cpp/src/exceptions.cpp \
    yaml-cpp/src/exp.cpp \
    yaml-cpp/src/memory.cpp \
    yaml-cpp/src/node.cpp \
    yaml-cpp/src/node_data.cpp \
    yaml-cpp/src/nodebuilder.cpp \
    yaml-cpp/src/nodeevents.cpp \
    yaml-cpp/src/null.cpp \
    yaml-cpp/src/ostream_wrapper.cpp \
    yaml-cpp/src/parse.cpp \
    yaml-cpp/src/parser.cpp \
    yaml-cpp/src/regex_yaml.cpp \
    yaml-cpp/src/scanner.cpp \
    yaml-cpp/src/scanscalar.cpp \
    yaml-cpp/src/scantag.cpp \
    yaml-cpp/src/scantoken.cpp \
    yaml-cpp/src/simplekey.cpp \
    yaml-cpp/src/singledocparser.cpp \
    yaml-cpp/src/stream.cpp \
    yaml-cpp/src/tag.cpp

HEADERS += \
    Core/core.h \
    Core/driver.h \
    Core/gap.h \
    Core/lap.h \
    Core/lap_sector.h \
    Core/myteam.h \
    Core/pitstop.h \
    Core/session.h \
    Core/stint.h \
    Core/stint_pitstop.h \
    Core/sunset.h \
    Core/team.h \
    Core/team_avg_calculator.h \
    Core/team_gap_container.h \
    Core/teams.h \
    Core/tire_wear.h \
    Core/track.h \
    Core/trackpoint.h \
    Core/trackpoints.h \
    Core/weather.h \
    Data/database.h \
    Data/db_telemetry.h \
    Data/db_track.h \
    Data/db_windows.h \
    Ir/ir_service.h \
    Ir/ir_tel_var.h \
    Ir/ir_tel_vars.h \
    Ir/irsdk_defines.h \
    Ir/irsdk_diskclient.h \
    Ir/irsdk_utils.h \
    SessionInfo/driverinfo.h \
    SessionInfo/driverinfo_drivers.h \
    SessionInfo/sessioninfo.h \
    SessionInfo/sessioninfo_resultposition.h \
    SessionInfo/sessioninfo_session.h \
    SessionInfo/sessionstring.h \
    SessionInfo/splittimeinfo.h \
    SessionInfo/splittimeinfo_sectors.h \
    SessionInfo/telemetryoptions.h \
    SessionInfo/weekendinfo.h \
    SessionInfo/weekendoptions.h \
    Telemetry/telemetry_data.h \
    Telemetry/telemetry_save_data.h \
    Telemetry/telemetry_save_data_lap.h \
    Telemetry/telemetry_save_data_lap_pct.h \
    Telemetry/telemetryreader.h \
    UI/Delegates/cus_default_cell.h \
    UI/Delegates/cus_driverlaps_cell.h \
    UI/Delegates/cus_fuel_cell.h \
    UI/Delegates/cus_gap_cel.h \
    UI/Delegates/cus_gap_cell.h \
    UI/Delegates/cus_laptime_cell.h \
    UI/Delegates/cus_lis_cell.h \
    UI/Delegates/cus_state_cell.h \
    UI/black.h \
    UI/debug_timing.h \
    UI/gap_overlay.h \
    UI/gap_overlay_2.h \
    UI/gap_overlay_copy.tmp \
    UI/hue.h \
    UI/race_graph.h \
    UI/stint_creator.h \
    UI/stint_overlay.h \
    UI/times.h \
    UI/tire_graph.h \
    UI/tires.h \
    global.h \
    mainwindow.h \
    master.h \
    yaml-cpp/anchor.h \
    yaml-cpp/binary.h \
    yaml-cpp/contrib/anchordict.h \
    yaml-cpp/contrib/graphbuilder.h \
    yaml-cpp/depthguard.h \
    yaml-cpp/dll.h \
    yaml-cpp/emitfromevents.h \
    yaml-cpp/emitter.h \
    yaml-cpp/emitterdef.h \
    yaml-cpp/emittermanip.h \
    yaml-cpp/emitterstyle.h \
    yaml-cpp/eventhandler.h \
    yaml-cpp/exceptions.h \
    yaml-cpp/mark.h \
    yaml-cpp/node/convert.h \
    yaml-cpp/node/detail/impl.h \
    yaml-cpp/node/detail/iterator.h \
    yaml-cpp/node/detail/iterator_fwd.h \
    yaml-cpp/node/detail/memory.h \
    yaml-cpp/node/detail/node.h \
    yaml-cpp/node/detail/node_data.h \
    yaml-cpp/node/detail/node_iterator.h \
    yaml-cpp/node/detail/node_ref.h \
    yaml-cpp/node/emit.h \
    yaml-cpp/node/impl.h \
    yaml-cpp/node/iterator.h \
    yaml-cpp/node/node.h \
    yaml-cpp/node/parse.h \
    yaml-cpp/node/ptr.h \
    yaml-cpp/node/type.h \
    yaml-cpp/noexcept.h \
    yaml-cpp/null.h \
    yaml-cpp/ostream_wrapper.h \
    yaml-cpp/parser.h \
    yaml-cpp/src/collectionstack.h \
    yaml-cpp/src/contrib/graphbuilderadapter.h \
    yaml-cpp/src/directives.h \
    yaml-cpp/src/emitterstate.h \
    yaml-cpp/src/emitterutils.h \
    yaml-cpp/src/exp.h \
    yaml-cpp/src/indentation.h \
    yaml-cpp/src/nodebuilder.h \
    yaml-cpp/src/nodeevents.h \
    yaml-cpp/src/ptr_vector.h \
    yaml-cpp/src/regex_yaml.h \
    yaml-cpp/src/regeximpl.h \
    yaml-cpp/src/scanner.h \
    yaml-cpp/src/scanscalar.h \
    yaml-cpp/src/scantag.h \
    yaml-cpp/src/setting.h \
    yaml-cpp/src/singledocparser.h \
    yaml-cpp/src/stream.h \
    yaml-cpp/src/streamcharsource.h \
    yaml-cpp/src/stringsource.h \
    yaml-cpp/src/tag.h \
    yaml-cpp/src/token.h \
    yaml-cpp/stlemitter.h \
    yaml-cpp/traits.h \
    yaml-cpp/yaml.h


FORMS += \
    UI/black.ui \
    UI/debug_timing.ui \
    UI/gap_overlay.ui \
    UI/gap_overlay_2.ui \
    UI/hue.ui \
    UI/race_graph.ui \
    UI/stint_creator.ui \
    UI/stint_overlay.ui \
    UI/times.ui \
    UI/tire_graph.ui \
    UI/tires.ui \
    mainwindow.ui

# Default rules for deployment.
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
