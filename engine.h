#pragma once
#include "UE4/SDK.h"
#include "logger.h"
#include "config.h"
#include "cIcons.h"
#include <vector>

#include <d3d11.h>
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_internal.h"


#include "HookLib/Hooklib.h"
#pragma comment(lib, "HookLib/Hooklib.lib")
#pragma comment(lib, "HookLib/Zydis.lib")

void processhk(void* Object, UFunction* Function, void* Params);
typedef void(__stdcall* fnProcessEvent)(void* Object, UFunction* Function, void* Params);

namespace engine
{
	static UAthenaGameViewportClient* AthenaGameViewportClient = nullptr;
	static ULocalPlayer* localPlayer = nullptr;
	static APlayerController* playerController = nullptr;
	static AAthenaPlayerCharacter* localPlayerActor = nullptr;
	static ULevel* persistentLevel = nullptr;
	static Config::Configuration* cfg = &Config::cfg;
	static bool bClearSunkList = false;
	static fnProcessEvent oProcessEvent = nullptr;
	static ACharacter* aimTarget = nullptr;
}

struct FunctionIndex {
	static inline int32_t BoxedRpcDispatcherComponent = -1;
};

void render(ImDrawList* drawList);
bool initUE4(uintptr_t world, uintptr_t objects, uintptr_t names);
bool setGameVars();
bool checkGameVars();
bool updateGameVars();
void RenderText(ImDrawList* drawList, const char* text, const FVector2D& pos, const ImVec4& color, const float dist, const bool outlined = false, const bool centered = true);
void RenderText(ImDrawList* drawList, const char* text, const FVector2D& pos, const ImVec4& color, const bool outlined = false, const bool centered = true);
void RenderText(ImDrawList* drawList, const char* text, const FVector2D& pos, const ImVec4& color, const int fontSize = 10, const bool centered = true);
void RenderText(ImDrawList* drawList, const char* text, const ImVec2& screen, const ImVec4& color, const float size, const bool outlined = false, const bool centered = true);
void renderPin(ImDrawList* drawList, const ImVec2& pos, const ImVec4& color, const float radius);
void Render2DBox(ImDrawList* drawList, const FVector2D& top, const FVector2D& bottom, const float height, const float width, const ImVec4& color);
float fClamp(float v, const float min, const float max);
bool checkSDKObjects();
bool WorldToScreen(Vector3 origin, Vector2* out, const FVector& cameraLocation, const FRotator& cameraRotation, const float fov);
uintptr_t milliseconds_now();
Vector2 RotatePoint(Vector2 pointToRotate, Vector2 centerPoint, float angle, bool angleInRadians = false);
bool raytrace(UWorld* world, const struct FVector& start, const struct FVector& end, struct FHitResult* hit);
FVector pickHoleToAim(AHullDamage* damage, const FVector& localLoc);
bool loadDevSettings();
void ClearSunkList();
void hookProcessEvent();
void unhookProcessEvent();
void EngineShutdown();

int getMapNameCode(char* name);
std::string getIslandNameByCode(int code);
std::string getShortName(std::string name);