files = main.cpp


ENGINE_FOLDER = ../src/Engine
SCENES_FOLDER = ../src/Scenes

CPP_FILES = $(ENGINE_FOLDER)/*.cpp
Scenes = $(Scenes)/*.cpp
all:
	g++ -std=c++11 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -I ../include -I ../include/Engine -I ../src ../lib/libraylib.a ../src/${files} $(CPP_FILES) -o ./voxelcraft2d
	./voxelcraft2d

