#pragma once
#include <vector>
#include <iostream>

class Scene {
public:
    int id;
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

class SceneManager {
public:
    static void addScene(Scene& scene);
    static void setup(Scene& beginnigScene);
    static void update();
    static void render();
    static void run(int id);
private:
    static std::vector<Scene*> scenes;
    static int currentScene;
};
