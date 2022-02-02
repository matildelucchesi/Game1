# CMakeList.txt: progetto CMake per Progetto. Includere l'origine e definire
# qui la logica specifica del progetto.
#
cmake_minimum_required (VERSION 3.8)

project(Game)


set(SOURCE_FILES	Animation.h
					Animation.cpp
					Character.h 
					Character.cpp 
					Enemy.h
					Enemy.cpp 
					Hero.h 
					Hero.cpp 
					Dice.h 
					Dice.cpp 
					Armor.h 
					ArmorCreator.h 
					ConcreteArmor.cpp 
					ConcreteArmor.h 
					ConcreteArmorCreator.cpp 
					ConcreteArmorCreator.h 
					ConcreteWeapon.h 
					ConcreteWeapon.cpp 
					ConcreteWeaponCreator.h 
					ConcreteWeaponCreator.cpp 
					Weapon.h 
					WeaponCreator.h 
					Achievements.cpp
					Achievements.h
					Observer.h
					Observable.h
					Observable.cpp
					GameState.h
					RaceMenuState.h
					RaceMenuState.cpp
					ClassMenuState.h
					ClassMenuState.cpp
					StartState.h
					StartState.cpp
					WeaponMenuState.h
					WeaponMenuState.cpp
					PlayingState.h
					PlayingState.cpp
					ArmorMenuState.h
					ArmorMenuState.cpp
					FirstLevelState.h
					FirstLevelState.cpp
					FightState.h
					FightState.cpp
					FAnimation.h
					FAnimation.cpp
					EndState.h
					EndState.cpp
					PausedState.h
					PausedState.cpp
					Map/TileMap.h
					Map/TileMap.cpp
					Map/Tile.h
					Map/Tile.cpp
					ObjectAnimation.h
					ObjectAnimation.cpp
					Playable.h
					Playable.cpp
					InteractiveObject.h
					InteractiveObject.cpp
					SecondLevelState.h
					SecondLevelState.cpp
					ThirdLevelState.h
					ThirdLevelState.cpp
					)

add_library(core ${SOURCE_FILES} "ArmorMenuState.cpp" "FirstLevelState.h" "FirstLevelState.cpp" "FightState.h" "FightState.cpp" "EndState.h" "PausedState.h" "Map/TileMap.h" "Map/Tile.h" "FAnimation.h"  "ArmorCreator.cpp" "Armor.cpp" "Weapon.cpp"  "InteractiveObject.h" "InteractiveObject.cpp" "SecondLevelState.h" "SecondLevelState.cpp")

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED )
find_package(tinyxml2 CONFIG REQUIRED)

add_subdirectory(test)
# Aggiungere l'origine all'eseguibile di questo progetto.
add_executable (Game  
				"Achievements.cpp"
				"Achievements.h"
				"Animation.cpp"
				"Animation.h"
				"Armor.h"
				"ArmorCreator.h"
				"Character.cpp"
				"Character.h"
				"ClassMenuState.cpp"
				"ClassMenuState.h"
				"ConcreteArmor.cpp"
				"ConcreteArmor.h"
				"ConcreteArmorCreator.cpp"
				"ConcreteArmorCreator.h"
				"ConcreteWeapon.cpp"
				"ConcreteWeapon.h"
				"ConcreteWeaponCreator.cpp"
				"ConcreteWeaponCreator.h"
				"Dice.cpp"
				"Dice.h"
				"Enemy.cpp"
				"Enemy.h"
				"Game.cpp"
				"Game.h"
				"GameState.h"
				"Hero.cpp"
				"Hero.h"
				"main.cpp"
				"Observable.cpp"
				"Observable.h"
				"Observer.h"
				"PlayingState.cpp"
				"PlayingState.h"
				"Potion.cpp"
				"Potion.h"
				"RaceMenuState.cpp"
				"RaceMenuState.h"
				"StartState.cpp"
				"StartState.h"
				"Weapon.h"
				"WeaponCreator.h"
				"WeaponMenuState.cpp"
				"WeaponMenuState.h"
				"ArmorMenuState.cpp"
				"ArmorMenuState.h" 
				"GameState.cpp" 
				"FirstLevelState.h" 
				"FirstLevelState.cpp" 
				"FightState.h"
				"FightState.cpp" 
				"EndState.h"
				"EndState.cpp" 
				"PausedState.h"
				"PausedState.cpp"
				"Map/TileMap.h"
				"Map/TileMap.cpp"
				"Map/Tile.h"
				"Map/Tile.cpp"
				"FAnimation.h"
				"FAnimation.cpp" 
				"ArmorCreator.cpp" 
				"Armor.cpp" 
				"Weapon.cpp" 
				"ObjectAnimation.h" 
				"ObjectAnimation.cpp" 
				"Playable.h"
				"Playable.cpp"
				"InteractiveObject.h" 
				"InteractiveObject.cpp" 
				"SecondLevelState.h" 
				"SecondLevelState.cpp"
				"ThirdLevelState.h"
				"ThirdLevelState.cpp")

# TODO: Aggiungere i test e, se necessario, installare le destinazioni.

target_link_libraries(Game PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(Game PRIVATE tinyxml2::tinyxml2)