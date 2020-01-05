/* 
	==== CONSOLE ENTITIES ====
	They do stuff in the console.
*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"

class CTriggerConsolePrinter : public CBaseEntity
{
public:
	void Spawn();
	void KeyValue(KeyValueData *pkvd);

	void Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value);

private:
	string_t m_iszMessage;
};

LINK_ENTITY_TO_CLASS(trigger_conprint, CTriggerConsolePrinter);

void CTriggerConsolePrinter::Spawn()
{
	// Nothing
}

void CTriggerConsolePrinter::KeyValue(KeyValueData *pkvd)
{
	if (FStrEq(pkvd->szKeyName, "conmessage"))
	{
		m_iszMessage = ALLOC_STRING(pkvd->szValue);
		pkvd->fHandled = TRUE;
	}

	else
		CBaseEntity::KeyValue(pkvd);
}

void CTriggerConsolePrinter::Use(CBaseEntity *pActivator, CBaseEntity *pCaller, USE_TYPE useType, float value)
{
	ALERT(at_console, "%s", STRING(m_iszMessage));
}
