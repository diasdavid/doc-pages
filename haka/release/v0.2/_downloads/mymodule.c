/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <assert.h>
#include <pcre.h>
#include <string.h>

#include <haka/error.h>
#include <haka/log.h>
#include <haka/module.h>
#include <haka/thread.h>

#include "mymodule.h"

static int  init(struct parameters *args);
static void cleanup();

struct module MY_MODULE = {
	type:        MODULE_EXTENSION,
	name:        L"my module",
	description: L"my module",
	api_version: HAKA_API_VERSION,
	init:        init,
	cleanup:     cleanup
};


static int init(struct parameters *args)
{
	messagef(HAKA_LOG_INFO, L"mymodule", L"init my module");
	return 0;
}

static void cleanup()
{
	messagef(HAKA_LOG_INFO, L"mymodule", L"cleanup my module");
}

void myfunc(void)
{
	messagef(HAKA_LOG_INFO, L"mymodule", L"myfunc");
}
