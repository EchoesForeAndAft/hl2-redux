#ifndef C_HL2REDUX_PLAYER_H
#define C_HL2REDUX_PLAYER_H

#include "cbase.h"
#include "c_basehlplayer.h"

class C_HL2ReduxPlayer : public C_BaseHLPlayer
{
	DECLARE_CLASS( C_HL2ReduxPlayer, C_BaseHLPlayer );
	DECLARE_CLIENTCLASS();
	DECLARE_DATADESC();

public:

//	void Spawn() override;
};

#endif // C_HL2REDUX_PLAYER_H