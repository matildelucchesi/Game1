cmake_minimum_required(VERSION 3.16)
project(Game LANGUAGES CXX)

find_package(SFML 2 COMPONENTS system window graphics network CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)

add_library(core STATIC
    src/achievements/Achievements.cpp
    src/achievements/Achievements.h
    src/achievements/Observable.cpp
    src/achievements/Observable.h
    src/achievements/Observer.h
    src/animation/Animation.cpp
    src/animation/Animation.h
    src/animation/FAnimation.cpp
    src/animation/FAnimation.h
    src/animation/ObjectAnimation.cpp
    src/animation/ObjectAnimation.h
    src/characters/Character.cpp
    src/characters/Character.h
    src/characters/Enemy.cpp
    src/characters/Enemy.h
    src/characters/Hero.cpp
    src/characters/Hero.h
    src/core/Game.cpp
    src/core/Game.h
    src/items/Armor.h
    src/items/ArmorCreator.h
    src/items/ConcreteArmor.cpp
    src/items/ConcreteArmor.h
    src/items/ConcreteArmorCreator.cpp
    src/items/ConcreteArmorCreator.h
    src/items/ConcreteWeapon.cpp
    src/items/ConcreteWeapon.h
    src/items/ConcreteWeaponCreator.cpp
    src/items/ConcreteWeaponCreator.h
    src/items/Potion.cpp
    src/items/Potion.h
    src/items/Weapon.h
    src/items/WeaponCreator.h
    src/states/ArmorMenuState.cpp
    src/states/ArmorMenuState.h
    src/states/ClassMenuState.cpp
    src/states/ClassMenuState.h
    src/states/EndState.cpp
    src/states/EndState.h
    src/states/FightState.cpp
    src/states/FightState.h
    src/states/FirstLevelState.cpp
    src/states/FirstLevelState.h
    src/states/GameState.cpp
    src/states/GameState.h
    src/states/PausedState.cpp
    src/states/PausedState.h
    src/states/Playable.cpp
    src/states/Playable.h
    src/states/PlayingState.cpp
    src/states/PlayingState.h
    src/states/RaceMenuState.cpp
    src/states/RaceMenuState.h
    src/states/SecondLevelState.cpp
    src/states/SecondLevelState.h
    src/states/StartState.cpp
    src/states/StartState.h
    src/states/ThirdLevelState.cpp
    src/states/ThirdLevelState.h
    src/states/WeaponMenuState.cpp
    src/states/WeaponMenuState.h
    src/utils/Dice.cpp
    src/utils/Dice.h
    src/world/InteractiveObject.cpp
    src/world/InteractiveObject.h
    src/world/Tile.cpp
    src/world/Tile.h
    src/world/TileMap.cpp
    src/world/TileMap.h
)
target_compile_features(core PUBLIC cxx_std_11)
target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(core PUBLIC
    sfml-system sfml-window sfml-graphics sfml-network tinyxml2::tinyxml2
)

add_executable(Game src/main.cpp)
target_link_libraries(Game PRIVATE core)
# Resource paths under assets/ are relative to the repository root.
set_property(TARGET Game PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()
