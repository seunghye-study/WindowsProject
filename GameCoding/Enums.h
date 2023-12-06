#pragma once

enum class SceneType
{
	None,
	DevScene,
	GameScene,
	EditScene,

	MenuScene,
	FortressScene,
};

enum LAYER_TYPE
{
	LAYER_BACKGROUND,
	LAYER_OBJECT,
	///
	LAYER_UI,
	LAYER_MAXCOUNT
};

enum class ColliderType
{
	Box,
	Sphere,
};