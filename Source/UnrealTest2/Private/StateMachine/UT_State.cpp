// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine/UT_State.h"

// Sets default values for this component's properties
UUT_State::UUT_State()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UUT_State::BeginPlay()
{
	// ..
}

// Called every frame
void UUT_State::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// ..
}

void UUT_State::Enter()
{
	// ..
}

void UUT_State::Exit()
{
	// ..
}
