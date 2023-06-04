/* DO NOT MODIFY THIS FILE WITHOUT CONSULTING LAIN.  OTHERWISE, LAIN WILL DO
 * EVERYTHING IN HER POWER TO MAKE YOUR LIFE MISERABLE FROM THEREON OUT WITH A
 * LEVEL OF DETERMINATION UNLIKE ANYTHING ANYONE HAS EVER SEEN IN THE HISTORY
 * OF MANKIND.
 *
 * YES, THAT MEANS YOU READING THIS RIGHT NOW.
 *
 * IF YOU HAVE A FORK AND FEEL YOU NEED TO MODIFY THIS, SUBMIT A PULL REQUEST
 * AND WAIT UNTIL IT HAS BEEN MERGED AND FULLY RELEASED IN THE CORE PROJECT
 * BEFORE USING IT.
 *
 * THIS IS YOUR ONLY WARNING. */

#define HOOK_VER_MAJOR 1
#define HOOK_VER_MINOR 8
#define HOOK_VER_PATCH 1

#ifndef STRINGIFY
#define STRINGIFY(s) #s
#endif

#define MAKE_VERSION_NAME(major, minor, patch) \
	STRINGIFY(major) "." STRINGIFY(minor) "." STRINGIFY(patch) ".0"
#define HOOK_VERSION_NAME \
	MAKE_VERSION_NAME(HOOK_VER_MAJOR, HOOK_VER_MINOR, HOOK_VER_PATCH)
