#include "GameObject.h"
using namespace hb;

int GameObject::s_game_object_identifier = 0;

GameObject* GameObject::getGameObjectById(int id)
{
	GameObject* go = nullptr;
	auto s = s_game_objects_by_id.find(id);
	if (s != s_game_objects_by_id.end())
		go = s->second;

	return go;
}


const std::vector<GameObject*>* GameObject::getGameObjectsByName(const std::string& name)
{
	const std::vector<GameObject*>* v = nullptr;
	auto s = s_game_objects_by_name.find(name);
	if (s != s_game_objects_by_name.end())
		v = &s->second;
	return v;
}


GameObject::GameObject():
Transform()
{
	m_identifier = s_game_object_identifier++;	
	s_game_objects_by_id.insert(std::pair<int, GameObject*>(m_identifier, this));
}


GameObject::~GameObject()
{
	for (Component* component : m_components)
		delete component;

	s_game_objects_by_id.erase(m_identifier);
	auto s = s_game_objects_by_name.find(m_name);
	if (s != s_game_objects_by_name.end())
	{
		for (std::vector<GameObject*>::iterator i = s->second.begin(); i != s->second.end(); ++i)
		{
			if (*i == this)
			{
				s->second.erase(i);
				i = s->second.end();
			}
		}
	}
}


int GameObject::getIdentifier() const
{
	return m_identifier;
}


const std::string& GameObject::getName() const
{
	return m_name;
}


void GameObject::setName(const std::string& name)
{
	// Remove from existing name group
	auto s = s_game_objects_by_name.find(m_name);
	if (s != s_game_objects_by_name.end())
	{
		for (std::vector<GameObject*>::iterator i = s->second.begin(); i != s->second.end(); ++i)
		{
			if (*i == this)
			{
				s->second.erase(i);
				i = s->second.end();
			}
		}
	}

	// Add to new name group
	m_name = name;
	auto go_group = s_game_objects_by_name.find(name);
	if (go_group == s_game_objects_by_name.end())
	{
		std::vector<GameObject*> go_vect;
		go_vect.push_back(this);
		s_game_objects_by_name.insert(std::pair<std::string, std::vector<GameObject*>>(m_name, go_vect));
	}
	else
	{
		go_group->second.push_back(this);
	}
}


void GameObject::update()
{
	for (Component* component : m_components)
		component->preUpdate();
	for (Component* component : m_components)
		component->update();
	for (Component* component : m_components)
		component->postUpdate();
}


void GameObject::addComponent(Component* component)
{
	m_components.push_back(component);
	m_components[m_components.size() - 1]->setGameObject(this);
}
