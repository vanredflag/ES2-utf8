// gouyee.c

inherit SKILL;

void create() { seteuid(getuid()); }

int valid_skill_usage(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("谷衣心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

int exert_function(object me, string arg)
{
	string func, target;
	object target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else
		func = arg;
	if( file_size("/d/skill/gouyee/" + func + ".c") < 0 )
		return notify_fail("你所学的内功没有这种功能。\n");
	else
		return (int)call_other("/d/skill/gouyee/" + func, "exert", me, target_ob);
}
