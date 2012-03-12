/*-- Neues Script --*/

#strict
#appendto KNIG

public func ContextAntiStuck()
{
	[Anti Stuck|Image=STUC]
	FindObject(STUC)->Activate(GetOwner());
}
