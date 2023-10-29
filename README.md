# MultiplayerSessions Plugin for UE5

The MultiplayerSessions plugin provides comprehensive tools to handle multiplayer sessions in your Unreal Engine 5 projects.

## Features:
1. **MultiplayerSessionSubsystem**: This subsystem offers functionality for creating, finding, joining, destroying, and starting multiplayer sessions.
2. **Menu UserWidget**: An easy-to-integrate widget to manage your multiplayer session interactions, including host and join buttons.
3. **OnlineSubsystem Integration**: Designed to work seamlessly with UE's OnlineSubsystem and OnlineSubsystemSteam, facilitating multiplayer functionalities.

## Prerequisites:

Ensure you have the `OnlineSubsystem` and `OnlineSubsystemSteam` plugins enabled in your project.

## Installation:

1. Copy the `MultiplayerSessions` plugin folder into your project's `Plugins` directory.
2. Rebuild your project.
3. Enable the plugin from the Edit -> Plugins menu in the UE5 editor.

## How to Use:

### MultiplayerSessionSubsystem

#### Methods:
- `CreateSession(int32 NumPublicConnections, FString MatchType)`: Initiates session creation.
- `FindSession(int32 MaxSearchResults)`: Starts the process to find available sessions.
- `JoinSession(const FOnlineSessionSearchResult& SessionResult)`: Allows a player to join a specific session.
- `DestroySession()`: Terminates the current session.
- `StartSession()`: Starts the current session, making it active.

### Menu (UserWidget)

#### Methods:
- `MenuSetup(int32 NumPublicConnections, FString TypeOfMatch, FString LobbyPath)`: Set up the menu with the desired parameters.
- `BPMenuTearDown()`: Blueprint callable function to tear down the menu.

#### Properties:
- `HostButton`: Button for the player to host a new session.
- `JoinButton`: Button for the player to join an existing session.
- `ResumeButton`: Blueprint-implemented button allowing players to resume their current session.
- `QuitButton`: Blueprint-implemented button allowing players to exit the game.

#### Events:
There are custom callbacks for the MultiplayerSubsystem, which you can override or bind to in Blueprints, such as `OnCreateSession`, `OnFindSession`, `OnJoinSession`, `OnDestroySession`, and `OnStartSession`.

### Build Configuration:

Ensure that you include dependencies on `OnlineSubsystem`, `OnlineSubsystemSteam`, `Slate`, `SlateCore`, and `UMG` in your project build settings.

## Known Limitations:

- This plugin is designed with the Steam OnlineSubsystem in mind. Adjustments may be required for other platforms.
- Ensure you handle failed session operations appropriately in your project.

## Contribution:

Feel free to fork and submit pull requests for any enhancements or bug fixes. Your contributions are appreciated.

## License:

This code is released as open-source. You are free to use, modify, and distribute it without seeking additional permissions or giving credit to the author. Use at your own risk.

---
