#include "../../../../myIncludes/game.hpp"

void	ftChangeSidedownPanel(Game *game, Camera2D *camera);
void	ftDrawSideDownButtons(Game *game);
void	ftDragAndDrop(Game *game, Props *blocks, EnvItems *envItems, MultipleCam2D *allCameras);

//*** All functions for side down panel ***//
void	ftSideDownMenu2D(Game *game, Props *blocks, EnvItems *envItems, MultipleCam2D *allCameras)
{
	ftDrawSideDownButtons(game);
	ftChangeSidedownPanel(game, &allCameras->camera02.camera);

	if (game->ctMenuSideDownButtons == 0)
	{
		ftDragAndDrop(game, blocks, envItems, allCameras);
	}
	else if (game->ctMenuSideDownButtons == 1)
	{

	}
	else if (game->ctMenuSideDownButtons == 2)
	{

	}
}

//*** Draw shapes for drag and drop ***//
void	ftDragAndDrop(Game *game, Props *blocks, EnvItems *envItems, MultipleCam2D *allCameras)
{
	Vector2 mousePos = game->mouse.pos;
	Vector2 rayPos = GetScreenToWorld2D(mousePos, allCameras->camera02.camera);


	DrawText("Square", 12, 55, 20, DARKGRAY);
	Rectangle rec = {1221, 387, 54, 54};
	if (CheckCollisionPointRec(rayPos, rec))
	{
		DrawTextureEx(game->dragDrop.squareSelect.ftReturnOneEnviTexture(),
			game->dragDrop.squareSelect.ftReturnOneEnviPos(), 0, 1, WHITE); // Square
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Vector2 pos = GetScreenToWorld2D(CENTER_SCREEN, allCameras->camera00.camera);
			int nbr = blocks->ftReturnNbr();

			std::string	name;
			name = "Block";
			name.append(ft_ftoa(blocks->ftReturnNbr(), 0));
			name.erase(name.length() - 7);
			blocks->ftAddProps(pos, {24, 24}, DARKGRAY, true, nbr, "blocks", name);
		}
	}
	else
	{
		DrawTextureEx(game->dragDrop.square.ftReturnOneEnviTexture(),
			game->dragDrop.square.ftReturnOneEnviPos(), 0, 1, WHITE);	// Square
	}

	DrawText("Triangle", 102, 55, 20, DARKGRAY);
	rec = {1321, 387, 54, 54};
	if (CheckCollisionPointRec(rayPos, rec))
	{
		DrawTextureEx(game->dragDrop.triangleSelect.ftReturnOneEnviTexture(),
			game->dragDrop.triangleSelect.ftReturnOneEnviPos(), 0, 1, WHITE); // Triangle
	}
	else
	{
		DrawTextureEx(game->dragDrop.triangle.ftReturnOneEnviTexture(),
			game->dragDrop.triangle.ftReturnOneEnviPos(), 0, 1, WHITE);	// Triangle
	}

	DrawText("Circle", 218, 55, 20, DARKGRAY);
	rec = {1421, 387, 54, 54};
	if (CheckCollisionPointRec(rayPos, rec))
	{
		DrawTextureEx(game->dragDrop.circleSelect.ftReturnOneEnviTexture(),
			game->dragDrop.circleSelect.ftReturnOneEnviPos(), 0, 1, WHITE); // Circle
	}
	else
	{
		DrawTextureEx(game->dragDrop.circle.ftReturnOneEnviTexture(),
			game->dragDrop.circle.ftReturnOneEnviPos(), 0, 1, WHITE);	// Circle
	}

	DrawText("Others", 12, 155, 20, DARKGRAY);
	rec = {1221, 487, 54, 54};
	if (CheckCollisionPointRec(rayPos, rec))
	{
		DrawTextureEx(game->dragDrop.otherSelect.ftReturnOneEnviTexture(),
			game->dragDrop.otherSelect.ftReturnOneEnviPos(), 0, 1, WHITE); // Others
	}
	else
	{
		DrawTextureEx(game->dragDrop.other.ftReturnOneEnviTexture(),
			game->dragDrop.other.ftReturnOneEnviPos(), 0, 1, WHITE);	// Others
	}

	DrawText("Platform", 150, 155, 20, DARKGRAY);
	rec = {1321, 487, 154, 54};
	if (CheckCollisionPointRec(rayPos, rec))
	{
		DrawTextureEx(game->dragDrop.platformSelect.ftReturnOneEnviTexture(),
			game->dragDrop.platformSelect.ftReturnOneEnviPos(), 0, 1, WHITE); // Others
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Texture2D	tex;
			Vector2 pos = GetScreenToWorld2D(CENTER_SCREEN, allCameras->camera00.camera);
			int nbr = blocks->ftReturnNbr();

			std::string	name;
			name = "Platform";
			name.append(ft_ftoa(envItems->ftReturnEnviAllNbr(), 0));
			name.erase(name.length() - 7);
			envItems->ftInitEnvitem(pos, {244, 56}, 1, DARKGRAY, tex, envItems->ftReturnEnviAllNbr(), name);
		}
	}
	else
	{
		DrawTextureEx(game->dragDrop.platform.ftReturnOneEnviTexture(),
			game->dragDrop.platform.ftReturnOneEnviPos(), 0, 1, WHITE);	// Others
	}
}

//*** Put Button control panel for menu side down ***//
void	ftDrawSideDownButtons(Game *game)
{
	if (game->ctMenuSideDownButtons == 0) // Right panel side down
	{
		DrawTextureEx(game->buttonsMenuSideDown.buttonRightOpen.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonRightOpen.ftReturnOneEnviPos(), 0, 1, WHITE);
		DrawTextureEx(game->buttonsMenuSideDown.buttonMiddleClose.ftReturnOneEnviTexture(),
			 game->buttonsMenuSideDown.buttonMiddleClose.ftReturnOneEnviPos(), 0, 1, WHITE);
		DrawTextureEx(game->buttonsMenuSideDown.buttonLeftClose.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonLeftClose.ftReturnOneEnviPos(), 0, 1, WHITE);
	}
	else if (game->ctMenuSideDownButtons == 1) // Middle panel side down
	{
		DrawTextureEx(game->buttonsMenuSideDown.buttonRightClose.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonRightClose.ftReturnOneEnviPos(), 0, 1, WHITE);
		DrawTextureEx(game->buttonsMenuSideDown.buttonMiddleOpen.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonMiddleOpen.ftReturnOneEnviPos(), 0, 1, WHITE);
		DrawTextureEx(game->buttonsMenuSideDown.buttonLeftClose.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonLeftClose.ftReturnOneEnviPos(), 0, 1, WHITE);
	}
	else if (game->ctMenuSideDownButtons == 2) // Left panel side down
	{
		DrawTextureEx(game->buttonsMenuSideDown.buttonRightClose.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonRightClose.ftReturnOneEnviPos(), 0, 1, WHITE);
		DrawTextureEx(game->buttonsMenuSideDown.buttonMiddleClose.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonMiddleClose.ftReturnOneEnviPos(), 0, 1, WHITE);
		DrawTextureEx(game->buttonsMenuSideDown.buttonLeftOpen.ftReturnOneEnviTexture(),
			game->buttonsMenuSideDown.buttonLeftOpen.ftReturnOneEnviPos(), 0, 1, WHITE);
	}
}

//*** Change counter for change button side down panel ***//
void	ftChangeSidedownPanel(Game *game, Camera2D *camera)
{
	Vector2 pos1 = {(float)game->screenWidth - 97, (float)game->screenHeight / 3 + 40};
	Vector2 pos2 = {(float)game->screenWidth - 197, (float)game->screenHeight / 3 + 40};
	Vector2 pos3 = {(float)game->screenWidth - 297, (float)game->screenHeight / 3 + 40};

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		Vector2 mousePos = game->mouse.pos;
		Vector2 rayPos = GetScreenToWorld2D(mousePos, *camera);

		Rectangle item = game->buttonsMenuSideDown.buttonRightOpen.ftReturnOneRectangle(); // Right button
		item.x = pos1.x;
		item.y = pos1.y;
		if (CheckCollisionPointRec(rayPos, item))
		{
			game->ctMenuSideDownButtons = 0;
		}
		item = game->buttonsMenuSideDown.buttonMiddleOpen.ftReturnOneRectangle(); // Middle button
		item.x = pos2.x;
		item.y = pos2.y;
		if (CheckCollisionPointRec(rayPos, item))
		{
			game->ctMenuSideDownButtons = 1;
		}
		item = game->buttonsMenuSideDown.buttonLeftOpen.ftReturnOneRectangle(); // Left button
		item.x = pos3.x;
		item.y = pos3.y;
		if (CheckCollisionPointRec(rayPos, item))
		{
			game->ctMenuSideDownButtons = 2;
		}
	}
}
