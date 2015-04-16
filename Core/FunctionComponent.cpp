#include "FunctionComponent.h"
using namespace bienne;

FunctionComponent::FunctionComponent()
{

}


FunctionComponent::~FunctionComponent()
{
	for(auto x : m_vector_of_listener_id)
		ignoreToGameObject(x);
}


void FunctionComponent::addListener(const std::string& name, std::function<void(DataRepository&)>&& listener)
{
    bienne_assert(getGameObject() != nullptr, "Added listener to FunctionComponent before it being added to a GameObject.");
	addListenerToGameObject(name, std::move(listener));
}
