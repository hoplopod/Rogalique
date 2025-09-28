#include "pch.h"
#include "MouseComponent.h"

namespace Engine {

	MouseComponent::MouseComponent(GameObject* gameObject) : Component(gameObject){
		transform = gameObject->GetComponent<TransformComponent>();
		renderer = gameObject->GetComponent<SpriteRendererComponent>();
	}

	void MouseComponent::Update(float deltaTime)
	{
		if (GameWorld::Instance()->FindGameObject("player")->GetComponent<PVEComponent>()->GetDeathStatus())
		{
			renderer->SetRenderCondition(false);
			return;	
		}

		if (sf::Event::MouseEntered) {
			transform->SetLocalPosition(attachmentToAnObject());
		}

		status = MouseStatus::statusPalm;

		std::vector<PVEComponent*> pveObject = Engine::PVESystem::Instance()->GetSubscribePVE();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			status = MouseStatus::statusFist;

			Vector2Df tapPosition = transform->GetWorldPosition();
			Vector2Df positionBody;
			float length;
			bool statusOfCatch = false;

			for (int i = 0; i < pveObject.size(); ++i)
			{
				if (pveObject[i]->GetGameObject()->GetName() == "player")
					continue;
				if (pveObject[i]->GetCatchStatus())
				{
					statusOfCatch = true;
					pveObject[i]->GetGameObject()->GetComponent<TransformComponent>()->SetWorldPosition(transform->GetWorldPosition());
				}
			}

			if (!statusOfCatch)
			for (int i = 0; i < pveObject.size(); ++i) {

				if (pveObject[i]->GetGameObject()->GetName() == "player") continue;

				auto body = pveObject[i]->GetGameObject()->GetComponent<TransformComponent>();
				positionBody = body->GetWorldPosition();
				length = sqrtf(pow((positionBody.x - tapPosition.x),2)+ pow((positionBody.y - tapPosition.y), 2));
				if (length == 0) length = 0.001;

				if (length > tapRadius) continue;
					
				pveObject[i]->setCatchStatus(true);
				body->GetGameObject()->GetComponent<SpriteRendererComponent>()->SetRenderCondition(false);
				body->SetWorldPosition(transform->GetWorldPosition());

			}
		}
		else for (int i = 0; i < pveObject.size(); ++i) {
			pveObject[i]->setCatchStatus(false);
			pveObject[i]->GetGameObject()->GetComponent<SpriteRendererComponent>()->SetRenderCondition(true);
		}

		
	}

	void MouseComponent::Render()
	{
		switch (status)
		{
		case Engine::MouseStatus::statusPalm: {
			renderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureMapElementShared("arm1", 0));
			//renderer->SetPixelSize(200, 200);
			break;
		}

		case Engine::MouseStatus::statusFist: {
			renderer->SetTexture(*Engine::ResourceSystem::Instance()->GetTextureMapElementShared("arm1(2)", 0));
			//renderer->SetPixelSize(270, 270);
			break;
		}

		default:
			break;
		}
		
		if (transform->GetWorldPosition().x < Engine::GameWorld::Instance()->FindGameObject("player")->GetComponent<TransformComponent>()->GetWorldPosition().x) {
			Engine::GameWorld::Instance()->FindGameObject("player")->GetComponent<SpriteRendererComponent>()->FlipX(true);
			renderer->FlipX(true);
		}
		else {
			Engine::GameWorld::Instance()->FindGameObject("player")->GetComponent<SpriteRendererComponent>()->FlipX(false);
			renderer->FlipX(false);
		}
	}

	Vector2Df MouseComponent::attachmentToAnObject()
	{
		Vector2Df position{ 0,0 }, mousePosition, playerPosition, playerWindowPosition{ 640,360 };
		float posX, posY, length, lengthMiniX, lengthMiniY;
		posX = sf::Mouse::getPosition(Engine::RenderSystem::Instance()->GetMainWindow()).x;
		posY = 720-sf::Mouse::getPosition(Engine::RenderSystem::Instance()->GetMainWindow()).y;
		

		auto playerComponent = Engine::GameWorld::Instance()->FindGameObject("player");
		playerPosition = playerComponent->GetComponent<TransformComponent>()->GetWorldPosition();
		
		mousePosition = {posX, posY};

		length = sqrtf(pow((mousePosition.x - playerWindowPosition.x), 2) + pow((mousePosition.y - playerWindowPosition.y), 2));
		if (length == 0) length = 0.001;

		if (length > maxDistance) {

			lengthMiniX = maxDistance * (mousePosition.x - playerWindowPosition.x) / length;
			lengthMiniY = maxDistance * (mousePosition.y - playerWindowPosition.y) / length;

		}
		else {
			lengthMiniX = mousePosition.x - playerWindowPosition.x;
			lengthMiniY = mousePosition.y - playerWindowPosition.y;
		}

		position = { playerPosition.x + lengthMiniX, playerPosition.y + lengthMiniY };
		return position;
		
	}

};


