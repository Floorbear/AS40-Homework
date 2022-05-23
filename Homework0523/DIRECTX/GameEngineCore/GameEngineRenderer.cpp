#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <GameEngineBase/GameEngineTransform.h>
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTransform.h>
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"
#include <GameEngineBase/GameEngineWindow.h>

GameEngineRenderer::GameEngineRenderer()
{
}

GameEngineRenderer::~GameEngineRenderer() 
{
}


void GameEngineRenderer::Start() 
{
	Angle_ = 0.0f;
	Angle2_ = 0.0f;

	Time1_ = 0.0f;
	Time2_ = 0.0f;
	Time3_ = 0.0f;
	Time4_ = 0.0f;
	Time5_ = 0.0f;
	GetActor()->GetLevel()->PushRenderer(this);
	GetActor()->GetTransform().SetScale({ 50,50 });
	GetActor()->GetTransform().SetPosition(GameEngineWindow::GetScale().Half()+float4(0,-250));


}

void GameEngineRenderer::Render(float _DeltaTime)
{


	RoAngle_ += _DeltaTime * 360.0f;
	if (Angle_ <= 360.0f)
	{
		Angle_ += _DeltaTime * 360.0f;
		float4 Dir = float4::DegreeToDirectionFloat4(Angle_);
		GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
		float4 CurPos = GetActor()->GetTransform().GetPosition();
	}
	else
	{
		if (Time1_ < 0.25f)
		{
			float4 Dir = float4::DegreeToDirectionFloat4(120.0f);
			GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
			Time1_ += _DeltaTime;
		}

	}



	if (Time1_ > 0.25f)
	{
		if (Time2_ < 0.25f)
		{
			float4 Dir = float4::DegreeToDirectionFloat4(0.0f);
			GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
			Time2_ += _DeltaTime;
		}

	}

	if (Time2_ >= 0.25f)
	{
		if (Time3_ < 0.25f)
		{
			float4 Dir = float4::DegreeToDirectionFloat4(240.0f);
			GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
			Time3_ += _DeltaTime;
		}
	}

	//다시 회전
	if (Time3_ >= 0.25f)
	{
		if (Angle2_ < 60)
		{
			Angle2_ += _DeltaTime * 360.0f;
			float4 Dir = float4::DegreeToDirectionFloat4(Angle2_);
			GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
			float4 CurPos = GetActor()->GetTransform().GetPosition();
		}
	}

	//회전스탑후 좌측으로
	if (Angle2_ >= 60)
	{
		if (Time4_ <= 0.25f)
		{
			float4 Dir = float4::DegreeToDirectionFloat4(-180.0f);
			GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
			Time4_ += _DeltaTime;
		}
	}

	//중앙쪽으로
	if (Time4_ > 0.25)
	{
		if (Time5_ <= 0.25f)
		{
			float4 Dir = float4::DegreeToDirectionFloat4(-300.0f);
			GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
			Time5_ += _DeltaTime;
		}
	}

	if (Time5_ > 0.25)
	{
		if (Time6_ <= 0.25f)
		{
			float4 Dir = float4::DegreeToDirectionFloat4(300.0f);
			GetActor()->GetTransform().SetMove(Dir * 1700.0f * _DeltaTime);
			Time6_ += _DeltaTime;
		}
	}






	//렌더링


	//렌더링 2
	GameEngineVertexBuffer* Vertex2 = GameEngineVertexBuffer::Find("6mangsung");
	GameEngineIndexBuffer* Index2 = GameEngineIndexBuffer::Find("6mangsung");

	std::vector<POINT> DrawVertex2;
	DrawVertex2.resize(Index2->Indexs.size());

	std::vector<float4> CopyBuffer2;
	CopyBuffer2.resize(Index2->Indexs.size());



	for (size_t i = 0; i < Index2->Indexs.size(); i++)
	{
		int TriIndex = Index2->Indexs[i];

		// 0 번째 순서의 점이 됩니다.
		CopyBuffer2[i] = Vertex2->Vertexs[TriIndex];

		// 크
		CopyBuffer2[i] *= GetActor()->GetTransform().GetScale();

		//회전
		CopyBuffer2[i] = float4::VectorRotationToDegreeZ(CopyBuffer2[i], RoAngle_);

		// 자전
		// CopyBuffer[TriIndex] *= GetActor()->GetTransform().GetScale();

		// 이동
		CopyBuffer2[i] += GetActor()->GetTransform().GetPosition();


		DrawVertex2[i] = CopyBuffer2[i].GetConvertWindowPOINT();
	}

	

	for (size_t i = 0; i < DrawVertex2.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex2[i], 3);
	}
	

	// Rectangle(GameEngineWindow::GetHDC(), LeftTop.ix(), LeftTop.iy(), RightBot.ix(), RightBot.iy());
}