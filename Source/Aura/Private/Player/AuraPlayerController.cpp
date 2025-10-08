// Copyright Jose Font


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"
#include "Kismet/GameplayStatics.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true; //Responding to data modification in the server updating the clients
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
	
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0); //Priority is for cases where there's several input mappings interfering

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent); //This class type for handling input is set in the editor Project settings > Input > Default Classes

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move); //Binding the custom MoveAction through the input component to the Move function
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	/* This works for rotated cameras, so that the character walks towards camera UP when W is pressed */
	const FRotator CameraRotation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraRotation();
	const FRotator CameraYawRotation(0.f, CameraRotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(CameraYawRotation).GetUnitAxis(EAxis::X); //Forward vector corresponding to yaw rotation
	const FVector RightDirection = FRotationMatrix(CameraYawRotation).GetUnitAxis(EAxis::Y);

	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	/* This works with a cameras that are always pointing at the same direction as UP,
	 * but as soon as you rotate the camera, the character walks towards its own UP direction instead of towards camera UP direction
	
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); //Forward vector corresponding to yaw rotation
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);*/

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y); //Y is associated with W and S, up and down
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X); //X is associated with A and D, left and right
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	if (ThisActor != LastActor)
	{
		if (LastActor != nullptr)
		{
			LastActor->HighlightActor();
			
		}
 
		if (ThisActor != nullptr)
		{
			ThisActor->HighlightActor();
		}
	}
	
	if (LastActor==nullptr)
	{
		if (ThisActor!=nullptr)
			ThisActor->HighlightActor();
	}
	else
	{
		if (ThisActor==nullptr) LastActor->UnHighlightActor();
		else
		{
			if (LastActor!=ThisActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}			
		}
	}

}
