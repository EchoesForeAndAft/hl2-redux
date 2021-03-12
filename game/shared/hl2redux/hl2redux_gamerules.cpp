#include "cbase.h"
#include "hl2redux_gamerules.h"

#ifdef CLIENT_DLL
	#define CHL2ReduxGameRulesProxy C_HL2ReduxGameRulesProxy
#endif

class CHL2ReduxGameRulesProxy : public CGameRulesProxy
{
	DECLARE_CLASS( CHL2ReduxGameRulesProxy, CGameRulesProxy );
	DECLARE_NETWORKCLASS();
};

LINK_ENTITY_TO_CLASS( hl2redux_gamerules, CHL2ReduxGameRulesProxy );
IMPLEMENT_NETWORKCLASS_ALIASED( HL2ReduxGameRulesProxy, DT_HL2ReduxGameRulesProxy )

REGISTER_GAMERULES_CLASS( CHL2ReduxGameRules );

BEGIN_NETWORK_TABLE_NOBASE( CHL2ReduxGameRules, DT_HL2ReduxGameRules )
#ifdef CLIENT_DLL
	RecvPropBool( RECVINFO( m_bMegaPhysgun ) ),
#else
	SendPropBool( SENDINFO( m_bMegaPhysgun ) ),
#endif
END_NETWORK_TABLE()

#ifdef CLIENT_DLL
void RecvProxy_HL2ReduxGameRules( const RecvProp *pProp, void **pOut, void *pData, int objectID )
{
	CHL2ReduxGameRules *pRules = HL2ReduxGameRules();
	Assert( pRules );
	*pOut = pRules;
}

BEGIN_RECV_TABLE( CHL2ReduxGameRulesProxy, DT_HL2ReduxGameRulesProxy )
	RecvPropDataTable( "hl2redux_gamerules_data", 0, 0, &REFERENCE_RECV_TABLE( DT_HL2ReduxGameRules ), RecvProxy_HL2ReduxGameRules )
END_RECV_TABLE()
#else
void *SendProxy_HL2ReduxGameRules( const SendProp *pProp, const void *pStructBase, const void *pData, CSendProxyRecipients *pRecipients, int objectID )
{
	CHL2ReduxGameRules *pRules = HL2ReduxGameRules();
	Assert( pRules );
	pRecipients->SetAllRecipients();
	return pRules;
}

BEGIN_SEND_TABLE( CHL2ReduxGameRulesProxy, DT_HL2ReduxGameRulesProxy )
	SendPropDataTable( "hl2redux_gamerules_data", 0, &REFERENCE_SEND_TABLE( DT_HL2ReduxGameRules ), SendProxy_HL2ReduxGameRules )
END_SEND_TABLE()
#endif

CHL2ReduxGameRules::CHL2ReduxGameRules() : CHalfLife2()
{
}