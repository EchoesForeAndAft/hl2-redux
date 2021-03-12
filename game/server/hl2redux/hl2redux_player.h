#ifndef HL2REDUX_PLAYER_H
#define HL2REDUX_PLAYER_H

#include "cbase.h"
#include "hl2_player.h"

class CHL2ReduxPlayer : public CHL2_Player
{
	DECLARE_CLASS( CHL2ReduxPlayer, CHL2_Player );
	DECLARE_SERVERCLASS();
	DECLARE_DATADESC();

public:
	static CHL2ReduxPlayer *Create( edict_t *pEdict );

	//	void Spawn() override;
};

#endif // HL2REDUX_PLAYER_H