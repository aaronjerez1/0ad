/* Copyright (C) 2009 Wildfire Games.
 * This file is part of 0 A.D.
 *
 * 0 A.D. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * 0 A.D. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 0 A.D.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDED_GAMESETUP
#define INCLUDED_GAMESETUP

//
// GUI integration
//

extern void GUI_Init();

extern void GUI_Shutdown();

extern void GUI_ShowMainMenu();

// display progress / description in loading screen
extern void GUI_DisplayLoadProgress(int percent, const wchar_t* pending_task);

extern void Render();
extern void RenderActor();

/**
 * initialize global modules that are be needed before Init.
 * must be called from the very beginning of main.
 **/
extern void EarlyInit();

enum InitFlags
{
	// avoid setting a video mode / initializing OpenGL; assume that has
	// already been done and everything is ready for rendering.
	// needed by map editor because it creates its own window.
	INIT_HAVE_VMODE = 1,

	// skip initializing the in-game GUI.
	// needed by map editor because it uses its own GUI.
	INIT_NO_GUI = 2,

	// skip initializing the simulation.
	// used by actor viewer because it doesn't need the simulation code.
	INIT_NO_SIM = 4
};

void RenderGui(bool RenderingState);

class CmdLineArgs;
extern void Init(const CmdLineArgs& args, int flags);
extern void Shutdown(int flags);

#endif // INCLUDED_GAMESETUP
