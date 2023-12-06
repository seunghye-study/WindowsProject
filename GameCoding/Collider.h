#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider(ColliderType colliderType);
	virtual ~Collider();
	virtual void BeginPlay() override;
	virtual void TickComponent() override;
	virtual void Render(HDC hdc) override;

	virtual bool CheckCollision(Collider* other);

	ColliderType GetColliderType() { return _colliderType; }
	void SetShowDebug(bool show) { _showDegub = show; }

protected:
	ColliderType _colliderType;
	bool _showDegub = true;
};

