/****************************************************************************
 * KONOHA ASSURANCE CASE
 *  written by Kimio Kuramitsu  twitter: @konohakun 
 ***************************************************************************/

a = 1;

if(a == 1) {
	TEST = 1;
}
else {
	TEST2 = 1;
}

assure "ScriptDynamicIf" {
	assert defined(TEST);
	assert !defined(TEST2);
}

