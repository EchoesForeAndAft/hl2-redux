#ifndef HL2REDUX_PLAYER_SHARED_H
#define HL2REDUX_PLAYER_SHARED_H

#if defined( CLIENT_DLL )
	#define CHL2ReduxPlayer C_HL2ReduxPlayer
	#include "c_hl2redux_player.h"
#else
	#include "hl2redux_player.h"
#endif

#endif // HL2REDUX_PLAYER_SHARED_H