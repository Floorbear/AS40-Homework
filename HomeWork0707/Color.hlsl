// #include "myshader.hlsli"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.

// t1

// Create("TransformData");
#include "TransformHeader.fx"

struct Input
{
    float4 Pos : POSITION;
    float4 Color : COLOR;
};

struct Output
{
    // �����Ͷ��������� ����Ʈ�� ���ؼ� �̳༮���� �ȼ��� ��������.
    float4 Pos : SV_POSITION;
    
    // �����Ͷ��������� ����Ʈ�� ���ؼ� �̳༮���� �ȼ��� ��������.
    float4 Pos2 : POSITION;
    float4 Color : COLOR;
};

// 1000
// 0100
// 2010
// 0301

// 1020
// 0103
// 0010
// 0001

Output Color_VS(Input _Input)
{
    // ���̴��� ��쿡�� ��κ��� ��Ȳ���� ����ȯ�� �����ϴ�.
    // 0
    Output NewOutPut = (Output)0;
    NewOutPut.Pos = _Input.Pos*10;
    NewOutPut.Pos.w = 1.0f;
    NewOutPut.Pos = mul(NewOutPut.Pos, WorldViewProjection);
    
    NewOutPut.Pos2 = _Input.Pos;
    // NewOutPut.Pos.w = 1.0f;
    NewOutPut.Color = _Input.Color;
    
    return NewOutPut;
}

cbuffer ResultColor : register(b0)
{
    float4 PlusColor;
    float4 MultyplyColor;
}

//cbuffer ResultColor2 : register(b2)
//{
//    float4 PlusColor2;
//    float4 MultyplyColor2;
//}

float4 Color_PS(Output _Input) : SV_Target0
{   
    if ((((_Input.Pos.x - 440) * (_Input.Pos.x - 440)) / ((300.0f) * (30.0f)) + ((_Input.Pos.y - 360) * (_Input.Pos.y - 360)) / ((180.0f) * (180.0f)) > 1.0f))
    {
        if ((_Input.Pos.x - 640) * (_Input.Pos.x - 640) + ((_Input.Pos.y - 360) * (_Input.Pos.y - 360)) > 400.0f)
        {
            if ((((_Input.Pos.x - 840) * (_Input.Pos.x - 840)) / ((300.0f) * (30.0f)) + ((_Input.Pos.y - 360) * (_Input.Pos.y - 360)) / ((180.0f) * (180.0f)) > 1.0f))
            {
                clip(-1);
            }
        }
    }

    return _Input.Color/* * MultyplyColor + PlusColor*/;
}
