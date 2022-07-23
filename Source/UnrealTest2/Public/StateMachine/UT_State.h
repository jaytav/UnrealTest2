// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "UT_State.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTEST2_API UUT_State : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUT_State();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	virtual void Enter();

	virtual void Exit();
};
