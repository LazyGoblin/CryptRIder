// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptRIderGameMode.h"
#include "CryptRIderCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACryptRIderGameMode::ACryptRIderGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
