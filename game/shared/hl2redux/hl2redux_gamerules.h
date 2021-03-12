#ifndef HL2REDUX_GAMERULES_H
#define HL2REDUX_GAMERULES_H

#include "cbase.h"
#include "hl2_gamerules.h"

#ifdef CLIENT_DLL
	#define CHL2ReduxGameRules C_HL2ReduxGameRules
#endif

class CHL2ReduxGameRules : public CHalfLife2
{
	DECLARE_CLASS( CHL2ReduxGameRules, CHalfLife2 );

public:
	CHL2ReduxGameRules();

	virtual const char *GetGameDescription()
	{
		return "Half-Life 2: Redux";
	}
};

inline CHL2ReduxGameRules *HL2ReduxGameRules()
{
	return static_cast<CHL2ReduxGameRules *>( g_pGameRules );
}

#endif // HL2REDUX_GAMERULES_H