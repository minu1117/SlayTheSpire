#include "Framework.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "../Scenes/SceneManager.h"
#include "../DataTable/DataTableMgr.h"
#include "SoundManager.h"

Framework::Framework(int width, int height)
	: windowSize(width, height)
{
	window.create(VideoMode(windowSize.x, windowSize.y), "Slay The Spire");
}

Framework::~Framework()
{

}

float Framework::GetDT() const
{
    return deltaTime.asSeconds();
}

bool Framework::Init()
{
    DATATABLE_MGR->Init();
    RESOURCE_MGR->LoadAll();
    SOUND_MGR->Init();
    SCENE_MGR->Init();
    InputMgr::Init();

    return true;
}

bool Framework::Play()
{
    while (window.isOpen())
    {
        InputMgr::ClearInput();
        deltaTime = clock.restart();
        float dt = GetDT(); 

        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                window.close();
            }
            InputMgr::UpdateInput(ev);
        }
        SCENE_MGR->Update(dt);
        SOUND_MGR->Update(dt);

        window.clear();
        SCENE_MGR->Draw(window);

        window.display();
    }

	return true;
}
