/* Auswahlpfeil f�r Zauber mit Objektziel */

#strict

public func Initialize()
{
	SetAction("Arrow");
	ScheduleCall(this, "Remove", 25, 0);
}

public func Remove()
{
	var brand = CreateObject(FBMP, 0, 0, -1);
	SetYDir(10, brand);
	RemoveObject();
}
