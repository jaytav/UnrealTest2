// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Engine.h"
#include "UT_State.h"

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "UT_StateMachine.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTEST2_API UUT_StateMachine : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUT_StateMachine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere)
	FString InitialState;
	
	UPROPERTY(EditAnywhere)
	UUT_State* ActiveState;

	TMap<FString, UUT_State*> States;

	virtual void TransitionToState(FString State);
};
