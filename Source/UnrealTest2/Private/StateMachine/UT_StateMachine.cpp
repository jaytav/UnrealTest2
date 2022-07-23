// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachine/UT_StateMachine.h"

// Sets default values for this component's properties
UUT_StateMachine::UUT_StateMachine()
{
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UUT_StateMachine::BeginPlay()
{
    for (USceneComponent* Child : GetAttachChildren()) {
        UUT_State* State = Cast<UUT_State>(Child);
        States.Add(State->GetName(), State);
    }

    TransitionToState(InitialState);
}

// Called every frame
void UUT_StateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    if (ActiveState) {
        ActiveState->TickComponent(DeltaTime, TickType, ThisTickFunction);
    }
}

void UUT_StateMachine::TransitionToState(FString State)
{
    GEngine->AddOnScreenDebugMessage(INDEX_NONE, 200, FColor::Green, "Transitioning to State: " + State);

    UUT_State* ToState = *States.Find(State);

    if (ToState == nullptr) {
        return;
    }

    if (ActiveState) {
        ActiveState->Exit();
    }

    UUT_State* FromState = ActiveState;
    ActiveState = ToState;
    ActiveState->Enter();
}


