#ifndef GAME_HPP
# define GAME_HPP

# include "../vendor/raylib/src/raylib.h"
# include "../vendor/raylib/src/raymath.h"
# include "./class2D/player.hpp"
# include "./class2D/props.hpp"
# include "./class2D/menu.hpp"
# include "./class2D/envitems.hpp"
# include "./class2D/buttons.hpp"
# include "./class2D/squareProps.hpp"
# include "../vendor/raylib/src/rlgl.h"

# include <string>
# include <iostream>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

# define G 800
# define PLAYER_JUMP_SPD 600.0f
# define PLAYER_HOR_SPD 200.0f
# define MAX_INPUT_CHARS 8

# define DARKGRAY1   CLITERAL(Color){ 60, 60, 60, 255 }
# define DARKGRAY2   CLITERAL(Color){ 140, 140, 140, 255 }
# define DARKPURPLE2 CLITERAL(Color){ 46, 23, 126, 255 } 
# define MYDARKGREEN  CLITERAL(Color){ 0, 148, 54, 255 }

namespace obj
{


	struct MultipleCam2D;
	typedef struct Mouse{
		Vector2	pos;
		float	camZoom;
	}	Mouse;

	typedef struct NeedBy2DCam{
		RenderTexture 	textForCam2;
		RenderTexture 	textForCam;
		Rectangle		rectForCam;
		Camera2D 		camera;
		Image			image;
	}	NeedBy2DCam;

	typedef struct MultipleCam2D{
		NeedBy2DCam	camera00;
		NeedBy2DCam camera01;
		NeedBy2DCam camera02;
		NeedBy2DCam camera03;
		NeedBy2DCam camera04;
		NeedBy2DCam camera05;
		NeedBy2DCam camera06;
		NeedBy2DCam camera07;
		NeedBy2DCam camera08;
		NeedBy2DCam camera09;
	}	MultipleCam2D;

	typedef struct Select
	{
		Player		*lastPlayer;	// 1
		Player		*player;	// 1
		class SquareProps	*lastProp;		// 2
		class SquareProps	*prop;		// 2
		class EnvItems	*lastItem;		// 3
		class EnvItems	*item;		// 3
		int			lastSelected = 0;
		int			selected = 0;
		int			lastType = 0;
		int			type = 0;	// Select witch
		int			nbr = 0;		// Nbr of prop

		int			lastNbr = 0;
		bool		resetTxt = false; // If deselect items

		int			letterCount = 0;
		int			witchBox = 0;
	}	Select;

	typedef struct MenuUp
	{
		Buttons		*buttonControlClose;
		Buttons		*buttonControlOpen;
		Buttons		*buttonColorClose;
		Buttons		*buttonColorOpen;
		Buttons		*play;
		Buttons		*stop;
	}	MenuUp;

	typedef struct MenuSideDown
	{
		Buttons		*buttonMiddleClose;
		Buttons		*buttonMiddleOpen;
		Buttons		*buttonRightClose;
		Buttons		*buttonRightOpen;
		Buttons		*buttonLeftClose;
		Buttons		*buttonLeftOpen;
	}	MenuSideDown;

	typedef struct TrioBox
	{
		Vector2		posTextBox;

		Rectangle	writeBox;
		Rectangle	hitBox;
	}	TrioBox;

	typedef struct TextBoxSideUp
	{
		TrioBox		RightBox0;
		TrioBox		LeftBox0;
		TrioBox		RightBox1;
		TrioBox		LeftBox1;

	}	TextBoxSideUp;

	class Game 
	{
		public:
		
		const int   screenWidth = 1500;
		const int   screenHeight = 800;
		float		delta;

		bool		ctCollision = false;
		int         characterSelection = 0;
		int			ctMenuSideDownButtons = 0;
		int			ctMenuUpButtons = 0;
		int			ctImgBuildGame = 1;
		int			ctStopAttack = 1;
		int			ctPlayStop = 1;
		int         ct_action = 0;
		int			ctMode = 1;

		Mouse			mouse;
		Font			font1;
		Vector2			posCam = {650, 300};
		Select			selected2D;

		Image			imgCercleChrom;
		Texture2D		textCercleChrom;
		Rectangle		rectCercleChrom;
		MenuUp			buttonsMenuUp;
		TextBoxSideUp	textBoxSideUp;
		MenuSideDown	buttonsMenuSideDown;
		bool			colorCt = false;

		int				nbrEnvItems = 0;
		int				nbrSquareProps = 0;
		int				nbrbuttons = 0;

		char rotation[MAX_INPUT_CHARS + 1] = "\0";

		void (*cameraUpdaters[])(Game *, Camera2D *, Player *, int, float, int, int);


	/**----------------------------> Menu <-----------------------------**/
	// void	ftMenuChooseCharacter(Game *Game, Player * player, Menu *menu);
	// void	ftChooseCharacter(Menu *menu);
	// void	ftChooseMenu(Menu *menu);

	// //**********************************************************************************//
	// //										2D											//
	// //**********************************************************************************//

	// /**--------------------------->> Init <<---------------------------**/

	// // void	ftInitTextBoxSideUp(Game *game);

	// /**----------------------->> Control Panel <<-----------------------**/

	// void	ftControlItems(Game *game, Player *player, EnvItems **envItems, SquareProps **blocks);
	// // void	ftSideUpMenu2D(Game *game, Player *player, Menu *menu, MultipleCam2D *allCameras);
	// void	ftSideUpControlMenu2D(Game *game, Player *player, Menu *menu);
	// // void	ftSideDownMenu2D(Game *game, Camera2D *camera);
	// // void	ftSelectItemsTop(Game *game, Camera2D *camera);
	// void	ftUpMenu2D(Game *game, Camera2D *camera);
	// // void	ftDrawVarsRiDownPanel(Game *game);
	// // void	ftDrawBoarders(Game *Game);

	// /**-------------------------> Build Game <--------------------------**/

	// // void	ftRunBuildMode(Game *Game,Stop *buildGame);
	// void	ftRunBuildMode(Game *game, Player *player, EnvItems **envItems,
	// 			SquareProps **blocks, Camera2D *camera);
	// void	ftMoveScreen(Game *game, Camera2D *camera);

	// /**----------------------------> Game <-----------------------------**/

	// // void 	ftUpdatePlayer(Game *game, Player *player, Menu *menu, EnvItems **envItems, int envItemsLength, float delta);
	// void 	ftUpdateCameraCenter(Game *game, Camera2D *camera, Player *player,
	// 			int envItemsLength, float delta, int width, int height);
	// void	ftImgsGestion(Game *game, Player *player);

	// // void	ftRoutine(Game *game, Player *player, Menu *menu, Camera2D *camera, SquareProps **blocks, EnvItems **envItems);
	// // void	ftGestionProps(Game *game, SquareProps **blocks, EnvItems **envItems, float deltaTime, int envItemsLength);
	// // void	ftKeyGestion(Game *game, Player *player, Menu *menu, float delta);

	// // void	ftRunGameMode(Game *game, Menu menu, Player player, EnvItems **envItems,
	// // 			SquareProps **blocks, MultipleCam2D allCameras);
	// void	ftDrawAll(Game *ame, Player *player, EnvItems **envItems, SquareProps **blocks);

	// /**---------------------------> Utility <----------------------------**/

	// // void	ftUsePlayerGravity(Player *player, EnvItems **envItems, float delta, int envItemsLength);
	// // void	ftUseGravity(SquareProps *prop, EnvItems **envItems, float delta, int envItemsLength);
	// // void	ftGravityGestion(Game *game, Player *player, SquareProps **blocks);
	// char	*ft_ftoa(float f, int *status);
	// // void	ftKeyGestionBuildMode(Game *Game);

	// //**********************************************************************************//
	// //										3D											//
	// //**********************************************************************************//

	// /**------------------------->> Fonctions <<-------------------------**/

	// // void	ftMode2D(Game *game, Menu *menu);
	// // void 	ftMode3D(Game *game);
	};
};


#endif