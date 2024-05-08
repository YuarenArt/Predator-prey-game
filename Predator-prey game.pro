# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Predator-prey game
DESTDIR = ./x64/Debug
CONFIG += debug
LIBS += -L"."
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
HEADERS += ./src/game/field/actors/move_strategy/zombie_move_strategy/ZombieMoveStrategy.h \
    ./src/game/field/actors/move_strategy/prey_move_strategy/PreyMoveStrategy.h \
    ./src/game/field/actors/move_strategy/predator_move_strategy/PredatorMoveStrategy.h \
    ./src/game/field/actors/move_strategy/MoveStrategyInterface.h \
    ./src/game/field/actors/A_algorithm_class/AAlgorithm.h \
    ./src/game/field/actors/prey/Prey.h \
    ./src/game/field/actors/predator/Predator.h \
    ./src/game/field/actors/zombie/Zombie.h \
    ./src/game/field/enums/enums.h \
    ./src/game/field/game_settings/GameSettings.h \
    ./src/game/field/position_matrix/PositionMatrix.h \
    ./src/position/point2D/Point2D.h \
    ./src/position/Position.h \
    ./src/game/PredatorPreyGame.h \
    ./src/game/field/field_sprite_vector/field_sprite/FieldSprite.h \
    ./src/widgets/splash_screen/SplashScreen.h \
    ./src/widgets/advanced_settings_widget/AdvancedSettingsWidget.h \
    ./src/widgets/end_of_game_widget/EndOfGameWidget.h \
    ./src/widgets/settings_widget/SettingsWidget.h \
    ./src/widgets/control/ControlBtns.h \
    ./src/game/field/field_sprite_vector/FieldSpriteVector.h \
    ./src/game/field/Field.h \
    ./src/game/field/actors/ActorsInterface.h \
    ./src/widgets/menu/Menu.h
SOURCES += ./src/game/field/actors/move_strategy/prey_move_strategy/PreyMoveStrategy.cpp \
    ./src/game/field/actors/move_strategy/predator_move_strategy/PredatorMoveStrategy.cpp \
    ./src/game/field/actors/move_strategy/MoveStrategyInterface.cpp \
    ./src/game/field/actors/A_algorithm_class/AAlgorithm.cpp \
    ./src/game/field/actors/predator/Predator.cpp \
    ./src/game/field/actors/prey/Prey.cpp \
    ./src/game/field/actors/zombie/Zombie.cpp \
    ./src/game/field/enums/enums.cpp \
    ./src/game/field/Field.cpp \
    ./src/game/field/game_settings/GameSettings.cpp \
    ./src/game/field/position_matrix/PositionMatrix.cpp \
    ./src/game/field/actors/ActorsInterface.cpp \
    ./src/game/field/field_sprite_vector/field_sprite/FieldSprite.cpp \
    ./src/game/field/field_sprite_vector/FieldSpriteVector.cpp \
    ./src/main.cpp \
    ./src/position/point2D/Point2D.cpp \
    ./src/position/Position.cpp \
    ./src/game/PredatorPreyGame.cpp \
    ./src/widgets/advanced_settings_widget/AdvancedSettingsWidget.cpp \
    ./src/widgets/end_of_game_widget/EndOfGameWidget.cpp \
    ./src/widgets/settings_widget/SettingsWidget.cpp \
    ./src/widgets/splash_screen/SplashScreen.cpp \
    ./src/widgets/control/ControlBtns.cpp \
    ./src/widgets/menu/Menu.cpp \
    ./src/game/field/actors/move_strategy/zombie_move_strategy/ZombieMoveStrategy.cpp
FORMS += ./src/game/field/Field.ui \
    ./src/game/field/field_sprite_vector/field_sprite/FieldSprite.ui \
    ./src/game/field/field_sprite_vector/FieldSpriteVector.ui \
    ./src/game/PredatorPreyGame.ui \
    ./src/widgets/advanced_settings_widget/AdvancedSettingsWidget.ui \
    ./src/widgets/control/ControlBtns.ui \
    ./src/widgets/end_of_game_widget/EndOfGameWidget.ui \
    ./src/widgets/menu/Menu.ui \
    ./src/widgets/settings_widget/SettingsWidget.ui
RESOURCES += PredatorPreyGame.qrc

QT += widgets designer core gui testlib