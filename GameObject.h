#ifndef HB_GAME_OBJECT_H
#define HB_GAME_OBJECT_H
#include <vector>
#include <string>
#include <unordered_map>
#include "Transform.h"

namespace hb
{
	class GameObject : public Transform
	{
	public:
		class Component
		{
		public:
			friend class GameObject;
			Component()
			{
				m_game_object = nullptr;
				m_relative = true;
			}
			virtual ~Component(){}
			virtual void preUpdate(){}
			virtual void update(){}
			virtual void postUpdate(){}
			GameObject* getGameObject() const {return m_game_object;}

		private:
			void setGameObject(GameObject* game_object)
			{m_game_object = game_object;}
			GameObject* m_game_object;
			bool m_relative;
		};

		static GameObject* getGameObjectById(int id);
		static const std::vector<GameObject*>* getGameObjectsByName(const std::string& name);
		static void destroyAll();

		GameObject();
		~GameObject();
		int getIdentifier() const;
		const std::string& getName() const;
		void setName(const std::string& name);
		void update();
		void addComponent(Component* component);

	private:
		static int s_game_object_identifier;
		static std::unordered_map<int, GameObject*> s_game_objects_by_id;
		static std::unordered_map<std::string, std::vector<GameObject*>> s_game_objects_by_name;

		int m_identifier;
		std::string m_name;
		std::vector<Component*> m_components;
	};
}
#endif
