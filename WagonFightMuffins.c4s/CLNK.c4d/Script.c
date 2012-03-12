
#strict
#appendto CLNK

local Relaunchs;
local Kills;


//Damit man nicht zu viele Clonks im Spieler hat

protected func Death(int iKilledBy)
{
	// Info-Broadcasts f�r sterbende Clonks
	GameCallEx("OnClonkDeath", this, iKilledBy);
	
	// Der Broadcast k�nnte seltsame Dinge gemacht haben: Clonk ist noch tot?
	if (GetAlive())
		return ;
	
	// den Beutel fallenlassen
	if (GetAlchemBag())
		GetAlchemBag()->~Loose();
	
	Sound("Die");
	DeathAnnounce();
	// Letztes Mannschaftsmitglied tot: Script benachrichtigen
	
	if (!GetCrew(GetOwner()))
		GameCall("RelaunchPlayer", GetOwner(), this, Relaunchs, iKilledBy, Kills);
	return 1;
}
