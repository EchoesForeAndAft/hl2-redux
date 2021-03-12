#include "cbase.h"
#include "hl2redux_player.h"
#include "hl2_gamerules.h"
#include "gamerules.h"
#include "teamplay_gamerules.h"
#include "entitylist.h"
#include "physics.h"
#include "game.h"
#include "player_resource.h"
#include "engine/IEngineSound.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

extern CBaseEntity *FindPickerEntityClass( CBasePlayer *pPlayer, char *classname );
extern bool g_fGameOver;
extern ConVar gamerules_survival;

void ClientPutInServer( edict_t *pEdict, const char *pszPlayerName )
{
	CHL2ReduxPlayer *pPlayer = CHL2ReduxPlayer::Create( pEdict );
	pPlayer->SetPlayerName( pszPlayerName );
}

void ClientActive( edict_t *pEdict, bool bLoadGame )
{
	CHL2ReduxPlayer *pPlayer = static_cast<CHL2ReduxPlayer *>( CBaseEntity::Instance( pEdict ) );

	Assert( pPlayer );
	if ( !pPlayer )
		return;

	pPlayer->InitialSpawn();

	if ( !bLoadGame )
		pPlayer->Spawn();
}

const char *GetGameDescription()
{
	if ( g_pGameRules )
	{
		// This function may be called before the world
		// has spawned, and the game rules initialized
		return g_pGameRules->GetGameDescription();
	}
	else
	{
		return "Half-Life 2: Redux";
	}

CBaseEntity *FindEntity( edict_t *pEdict, char *classname )
{
	// If no name was given set bits based on the picked
	if ( FStrEq( classname, "" ) )
		return ( FindPickerEntityClass( static_cast<CBasePlayer *>( GetContainingEntity( pEdict ) ), classname ) );

	return NULL;
}

void ClientGamePrecache( void )
{
	CBaseEntity::PrecacheModel( "models/player.mdl" );
	CBaseEntity::PrecacheModel( "models/gibs/agibs.mdl" );
	CBaseEntity::PrecacheModel( "models/weapons/v_hands.mdl" );

	CBaseEntity::PrecacheScriptSound( "HUDQuickInfo.LowAmmo" );
	CBaseEntity::PrecacheScriptSound( "HUDQuickInfo.LowHealth" );

	CBaseEntity::PrecacheScriptSound( "FX_AntlionImpact.ShellImpact" );
	CBaseEntity::PrecacheScriptSound( "Missile.ShotDown" );
	CBaseEntity::PrecacheScriptSound( "Bullets.DefaultNearmiss" );
	CBaseEntity::PrecacheScriptSound( "Bullets.GunshipNearmiss" );
	CBaseEntity::PrecacheScriptSound( "Bullets.StriderNearmiss" );

	CBaseEntity::PrecacheScriptSound( "Geiger.BeepHigh" );
	CBaseEntity::PrecacheScriptSound( "Geiger.BeepLow" );
}

// Called by ClientKill and DeadThink
void respawn( CBaseEntity *pEdict, bool fCopyCorpse )
{
	if ( gpGlobals->coop || gpGlobals->deathmatch )
	{
		if ( fCopyCorpse )
		{
			// Make a copy of the dead body for appearances sake
			static_cast<CHL2ReduxPlayer *>( pEdict )->CreateCorpse();
		}

		// Respawn player
		pEdict->Spawn();
	}
	else
	{
		// restart the entire server
		engine->ServerCommand( "reload\n" );
	}
}

void GameStartFrame( void )
{
	if ( g_fGameOver )
		return;

	gpGlobals->teamplay = ( teamplay.GetInt() != 0 );
}

void InstallGameRules()
{
	if ( gamerules_survival.GetBool() )
	{
		// Survival mode
		CreateGameRulesObject( "CHalfLife2Survival" );
	}
	else
	{
		// generic half-life
		CreateGameRulesObject( "CHalfLife2" );
	}
}
