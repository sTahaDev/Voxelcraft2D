files = main.cpp


ENGINE_FOLDER = ../src/Engine
CPP_FILES = $(ENGINE_FOLDER)/gameobject.cpp $(ENGINE_FOLDER)/envanter.cpp $(ENGINE_FOLDER)/collider.cpp $(ENGINE_FOLDER)/block.cpp $(ENGINE_FOLDER)/map.cpp $(ENGINE_FOLDER)/player.cpp

all:
	g++ -std=c++11 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -I ../include -I ../include/Engine ../lib/libraylib.a ../src/${files} $(CPP_FILES) -o ./voxelcraft2d
	./voxelcraft2d

