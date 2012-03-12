/*-- L�schobjekt --*/

#strict

public func Activate()
{
	return 1;
}

global func FxFireStart(object obj, int iNumber, int iTemp, int iCausedBy, bool fBlasted, object pIncineratingObject)
{
	// Wenn ein Objekt zu brennen beginnt, gleich das L�schen planen
	var i;
	if (!iTemp)
		if (GetAlive(obj))
			if (i = ObjectCount(_ETG))
			{
				// L�sche in Schl�sselframes, damit nahe beieinanderliegende Objekte ungef�hr gleichzeitig gel�scht werden
				// Dies verringert die Chance des Neuanz�ndens
				var iExtgTime = 175 / i + 50 - (FrameCounter() % 50);
				AddEffect("IntExtinguisher", obj, 1, iExtgTime, obj);
			}
	return inherited(obj, iNumber, iTemp, iCausedBy, fBlasted, pIncineratingObject);
}

global func FxIntExtinguisherStop(object obj, int iNumber, int iReason, bool fTemp)
{
	if (!fTemp)
	{
		// Zeit zum L�schen!
		Extinguish(obj);
	}
}

global func FxFireStop(object obj, int iNumber, int iReason, bool fTemp)
{
	if (!fTemp)
	{
		// Das Objekt wurde gel�scht (entweder durch den L�scheffekt, oder anderswie): L�cheffekt entfernen
		RemoveEffect("IntExtinguisher", obj, 0, true);
	}
	return inherited(obj, iNumber, iReason, fTemp);
}
