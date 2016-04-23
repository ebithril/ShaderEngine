#include "Engine_Precompiled.h"
#include "DirectXInterface.h"

#include "DirectX.h"

namespace GraphicsEngine
{
	DirectXInterface::DirectXInterface()
	{
		myDirectXEngine = new DirectX();
	}

	DirectXInterface::~DirectXInterface()
	{
	}

	GraphicsEngine::DirectX& DirectXInterface::GetDirectX()
	{
		return *myDirectXEngine;
	}

	bool DirectXInterface::Init(WindowInterface& aWindowInterface)
	{
		return myDirectXEngine->Init(aWindowInterface);
	}

	void DirectXInterface::BeginScene()
	{
		myDirectXEngine->BeginScene();
	}

	void DirectXInterface::EndScene()
	{
		myDirectXEngine->EndScene();
	}

}