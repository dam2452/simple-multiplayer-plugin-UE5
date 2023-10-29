// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessionSubsystem.h"
#include "Components/Button.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MultiplayerMenu")
	void MenuSetup(int32 NumPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForALL")), FString LobbyPath = FString(TEXT("/Game/Levels/Sublevels/dam2452-Test")));
	UFUNCTION(BlueprintCallable, Category = "MultiplayerMenu")
	void BPMenuTearDown();

protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	//
	// Callback for custom delegates form Multiplayersubsystem
	//

	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);

private:

	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	//UPROPERTY(meta = (BindWidget))
	//UButton* ReturnButton;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	//UFUNCTION()
	//void ReturnButtonClicked();

	void MenuTearDown();

	//Subsystem onilne session
	UMultiplayerSessionSubsystem* MultiplayerSessionSubsystem;

	int32 NumPublicConnections{4};
	FString MatchType{TEXT("FreeForALL")};

	FString PathToLobby{ TEXT("") };
};
