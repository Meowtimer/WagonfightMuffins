#strict

public func Activate(object caster, real_caster)
{
	var idir = 1;
	if (GetDir(caster) == 0)
		idir = -1;
	var wagn = CreateObject(WAGN, 20 * idir, 38, GetOwner(caster));
	wagn->FadeIn();
	
	var wagn = CreateObject(WAGN, 60 * idir, 38, GetOwner(caster));
	wagn->FadeIn();
	Sound("Magic*");
	return 1;
}

