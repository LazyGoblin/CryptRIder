#include "TriggerArea.h"


UTriggerArea::UTriggerArea() 
{
    PrimaryComponentTick.bCanEverTick = true;
}


void UTriggerArea::BeginPlay()
{
    Super::BeginPlay();
}


void UTriggerArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    AActor* Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if(Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        MovingWall->SetShallItmove(true);
    } 
    else 
    {
            MovingWall->SetShallItmove(false);
    }
}

void UTriggerArea::SetMovingWall(UMovingWall *NewMovingWall)
{
    MovingWall = NewMovingWall;
}

AActor *UTriggerArea::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for(AActor* Actor : Actors)
    {
        if (Actor->ActorHasTag(TriggerTag))
        {
            return Actor;
        } 
    }
    return nullptr;
}