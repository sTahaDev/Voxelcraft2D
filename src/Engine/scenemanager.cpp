#include "scenemanager.hpp"

// Sahne listesini başlat
std::vector<Scene *> SceneManager::scenes;
int SceneManager::currentScene = 0; // Başlangıç değeri ver

void SceneManager::addScene(Scene &scene)
{
    scenes.push_back(&scene);
}

void SceneManager::setup(Scene &beginnigScene)
{
    SceneManager::currentScene = beginnigScene.id;
    scenes.push_back(&beginnigScene);
}

void SceneManager::update()
{

    for (int i = 0; i < scenes.size(); i++)
    {
        if (scenes[i]->id == SceneManager::currentScene)
        {

            scenes[i]->update();
        }
    }
}

void SceneManager::render()
{
    for (int i = 0; i < scenes.size(); i++)
    {
        if (scenes[i]->id == SceneManager::currentScene)
        {

            scenes[i]->render();
        }
    }
}

void SceneManager::run(int id)
{ 
    currentScene = id;
    for (int i = 0; i < scenes.size(); i++)
    {
        if (scenes[i]->id == SceneManager::currentScene)
        {
            scenes[i]->setup();
        }
    }
}
