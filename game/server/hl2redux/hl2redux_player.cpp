#include "cbase.h"
#include "hl2redux_player.h"

LINK_ENTITY_TO_CLASS( hl2redux_player, CHL2ReduxPlayer );

IMPLEMENT_SERVERCLASS_ST( CHL2ReduxPlayer, DT_HL2ReduxPlayer )
END_SEND_TABLE()

BEGIN_DATADESC( CHL2ReduxPlayer )
END_DATADESC()

CHL2ReduxPlayer *CHL2ReduxPlayer::Create( edict_t *pEdict )
{
	CHL2_Player::s_PlayerEdict = pEdict;
	return static_cast<CHL2ReduxPlayer *>( CreateEntityByName( "hl2redux_player" ) );
}