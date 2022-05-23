#pragma once
#include "GameEngineComponent.h"
#include <GameEngineBase/GameEngineMath.h>

// Ό³Έν :
class GameEngineRenderer : public GameEngineComponent
{
	friend class GameEngineLevel;

public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

protected:
	virtual void Start();
	virtual void Update(float _DeltaTime) {}
	virtual void End() {}

private:
	void Render(float _DeltaTime);

	float RoAngle_;
	float Angle_;
	float Angle2_;
	float CircleLen_;

	float Time1_;
	float Time2_;
	float Time3_;
	float Time4_;
	float Time5_;
	float Time6_;

};

